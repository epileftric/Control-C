#include "mainWindow.h"

#include <QDebug>

mainWindow::mainWindow()
	: QMainWindow(), Ui_ControlModerno() {
	
	setupUi(this);
	
	UPlot *uPlot = new UPlot();
	gridPlot->addWidget(uPlot, 0, 0, 1, 1);
	
	progressBar = new QProgressBar(this);
	progressBar->setAlignment(Qt::AlignRight);
	progressBar->setMaximumSize(180, 19);
	statusBar()->addPermanentWidget(progressBar);
	
	condicionesIniciales = new LabelList(this,formIniciales,"x");
	condicionesIniciales->changeSize(sistema->getVE());
	connect( spinVE,
			 static_cast<void (QSpinBox::*) (int)>(&QSpinBox::valueChanged),
			 condicionesIniciales,
			 &LabelList::changeSize);
			 
	polosLazoCerrado = new LabelList(this,formPolos,"p");
	polosLazoCerrado->changeSize( sistema->getVE() );
	connect( spinVE,
			 static_cast<void (QSpinBox::*) (int)>(&QSpinBox::valueChanged),
			 polosLazoCerrado,
			 &LabelList::changeSize);

	///~ Configuracion del status Bar:
	
	connect( handler->getNotifier(), &QNotifier::updateStatus, this, &mainWindow::updateStatus);
	connect( handler->getNotifier(), &QNotifier::updateProgressBar, progressBar, &QProgressBar::setValue);
		
	
	///~ Configuración del UPlot:
	connect( handler, &guiHandler::clearPlot, uPlot, &UPlot::clear );
	
	
	///~ Configuracion primer TAB: Sistema
	connect(handler, &guiHandler::reloadSystem,this,&mainWindow::reloadSystem);
	connect(actionAplicar,&QAction::triggered,this,&mainWindow::setABCD);
	connect(lineTs,&QLineEdit::editingFinished,this,&mainWindow::finishedEditingTs);

	
	///~ Configuración segundo TAB: simulacion
	connect(actionSimular, &QAction::triggered,this,&mainWindow::startSimulation);
	connect(lineTs,&QLineEdit::editingFinished,this,&mainWindow::computeN);
	connect(lineTf,&QLineEdit::editingFinished,this,&mainWindow::computeN);

	
	///~ Configuración tercer Tab: Control
	handler->setSliderRef( x0Slider );
	
	connect(handler, &guiHandler::reloadController,this,&mainWindow::reloadController);
	connect(handler, &guiHandler::reloadObserver,this,&mainWindow::reloadObserver);
	connect(actionGuardarPolos,&QAction::triggered,this,&mainWindow::guardarPolos);
	connect(pushGuardarK,&QPushButton::clicked,this,&mainWindow::guardarK);
	
	//~ connect(comboTipoObs,
			//~ static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged)
			//~ ,this,&mainWindow::changeObserver);
	
	connect(pushControl, &QPushButton::toggled, this,&mainWindow::startController);
	
	
	///~ Por último actualizo la interfaz.
	update();
}

//~ void mainWindow::changeObserver( int i ){
	//~ o_type index = static_cast<enum o_type>( i );
	//~ handler->changeObserver(index);
//~ }

void mainWindow::startController(bool tf ){
	o_type index = static_cast<enum o_type>(comboTipoObs->currentIndex());
	handler->startController(tf, index);
}
	
void mainWindow::updateStatus(const char *msg){
	QString str(msg);
	statusBar()->showMessage(str+".");
}

void mainWindow::update(void){
	if ( sistema != 0 )
		reloadSystem();
	if ( control != 0 )
		reloadController();
	if (observador != 0 )
		reloadObserver();
		
	computeN();
}



void mainWindow::setABCD(void){
	handler->setABCD( textA->toPlainText(),
					  textB->toPlainText(),
					  textC->toPlainText(),
					  textD->toPlainText() );
}

void mainWindow::reloadSystem(void){
	QTextEdit *text[]= {textA,textB,textC,textD,textPhi,textPsi};
	
	for (int i = 0; i <= mat::Psi ; i++) {
		Mat *matx = sistema->getMat(i);
		if ( matx != 0){
			text[i]->setText( QString::fromStdString( mat2str( matx )) );
		}
	}
	spinEntradas->setValue(sistema->getEntradas() );
	spinSalidas->setValue(sistema->getSalidas() );
	spinVE->setValue(sistema->getVE() );

	lineTs->setText( QString("%1").arg(sistema->getTSample()) );	
}

void mainWindow::reloadController(void){
	complexVector poly, poles = control->getPoles();
	
	polosLazoCerrado->changeSize( sistema->getVE() );
	polosLazoCerrado->setValues( poles );
	
		
	string str = mat2str( control->getMat(mat::k) );
	textK->setText( QString::fromStdString(str) );
}

void mainWindow::reloadObserver(void){
	if ( observador != 0 ) {
		comboTipoObs->setCurrentIndex( observador->getType() );
		Mat l = observador->getMat(mat::l)->clone();
		transpose(l,l);
		string str = mat2str( l );
		textL->setText( QString::fromStdString( str ) );
	}
	else 
		comboTipoObs->setCurrentIndex(0);
		
}


void mainWindow::guardarPolos(void){
	QStringList doubleList = polosLazoCerrado->returnStrings();
	handler->guardarPolos(&doubleList);
}

void mainWindow::guardarK(void){
	QString strK = textK->toPlainText();
	handler->guardarK(&strK);
}

void mainWindow::startSimulation(void){
	
	bool ok1,ok2,ok3,ok4;
	double Tf = lineTf->text().toDouble(&ok1);
	double To = lineTo->text().toDouble(&ok2);
	double A = lineAmp->text().toDouble(&ok3);
	
	doubleVector Xo;
	QStringList doubleList = condicionesIniciales->returnStrings();
	ok4 = true;
	for (int i = 0; i < doubleList.size() && ok4 ; i++) {
		Xo.push_back( doubleList[i].toDouble( &ok4 ) );
	}
	
	if ( ok1 && ok2 && ok3 && ok4 ){
		handler->startSimulation(comboTipoSenial->currentIndex(),Tf,To,A,Xo);	
		tabWidget->setCurrentWidget(tabPlot);
	}
}


