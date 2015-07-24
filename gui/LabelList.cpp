#include "LabelList.h"


LabelList::LabelList(QWidget *p,QFormLayout *l,QString s){
	parent=p;
	layout=l;
	elementName=s;
}

void LabelList::changeSize(int newSize){
	
	if ( line.size() == 0 || line.size() < newSize ){
		for (int i = line.size() ; i < newSize; i++) {
			label << newQLabel(i);
			line << newQLineEdit(i);
			
			layout->addRow(label[i],line[i]);
		}
	}
	else if ( line.size() > newSize ){
		for (int i = line.size() ; i > newSize ; i--) {
			delete line.last();
			delete label.last();
			line.removeLast();
			label.removeLast();
		}
	}
}

void LabelList::setValues( complexVector &p){	
	complexVector *poles = &p;
	if ( line.size() == (int) poles->size() ){
		for (uint i = 0; i < poles->size() ; i++)	{
			stringstream str;
			if ( imag( (*poles)[i]) != 0 )
				str << (*poles)[i];
			else
				str << real((*poles)[i]);
		
			line[i]->setText( QString::fromStdString ( str.str() ) );
		}
		
	}
}


QStringList LabelList::returnStrings(void){
	QStringList valores;
	for (int i = 0; i < line.size(); i++) {
		valores << line[i]->text();
	}
	return (valores);
}


QLabel* LabelList::newQLabel(int i){
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		
	QLabel *newOne = new QLabel(parent);
	
	newOne->setText(VEname(i));
	
	newOne->setObjectName(QString("labelX_%1").arg(i));
	newOne->setSizePolicy(sizePolicy);
	newOne->setMinimumSize(QSize(50, 0));
	newOne->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	
	
	return newOne;
}

QLineEdit* 	LabelList::newQLineEdit(int i){
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		
	
	QLineEdit *newOne = new QLineEdit(parent);
	

	newOne->setText("0.0");
	newOne->setObjectName(QString("lineX_%1").arg(i));
	newOne->setSizePolicy(sizePolicy);



	return newOne;
}
