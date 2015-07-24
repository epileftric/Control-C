/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlModerno
{
public:
    QAction *actionSimular;
    QAction *actionAplicar;
    QAction *actionGuardarPolos;
    QAction *actionExportar;
    QAction *actionCopy_for_Matlab;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabParametros;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupParametros;
    QGridLayout *gridLayout_2;
    QFrame *frameD;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelD;
    QTextEdit *textD;
    QGridLayout *gridLayout_4;
    QPushButton *pushAplicar;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frameB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelB;
    QTextEdit *textB;
    QFrame *frameC;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelC;
    QTextBrowser *textC;
    QFormLayout *formLayout;
    QLabel *labelEntradas;
    QSpinBox *spinEntradas;
    QLabel *labelSalidas;
    QSpinBox *spinSalidas;
    QLabel *labelVE;
    QSpinBox *spinVE;
    QLabel *LabelTs;
    QLineEdit *lineTs;
    QFrame *frameA;
    QHBoxLayout *horizontalLayout;
    QLabel *labelA;
    QTextBrowser *textA;
    QFrame *groupMatrices;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBoxPHI;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelPHI;
    QTextEdit *textPhi;
    QGroupBox *groupBoxPSI;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelPSI;
    QTextEdit *textPsi;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabSimulacion;
    QGridLayout *gridLayout_6;
    QGroupBox *groupIniciales;
    QGridLayout *gridLayout_12;
    QFormLayout *formIniciales;
    QGroupBox *groupEntrada;
    QHBoxLayout *horizontalLayout_9;
    QGridLayout *gridLayout_11;
    QLineEdit *lineTo;
    QLabel *labelAmp;
    QLineEdit *lineAmp;
    QLabel *labelN;
    QLabel *labelTo;
    QLineEdit *lineN;
    QLabel *labelTf;
    QLineEdit *lineTf;
    QLabel *labelTipo;
    QComboBox *comboTipoSenial;
    QSpacerItem *horizontalSpacer_7;
    QLabel *imagenEntrada;
    QPushButton *pushSimular;
    QSpacerItem *verticalSpacer_4;
    QWidget *tabControl;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushControl;
    QGridLayout *gridLayout_10;
    QLabel *x0Label;
    QSlider *x0Slider;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxK;
    QGridLayout *gridLayout_7;
    QTextEdit *textK;
    QLabel *labelK;
    QPushButton *pushGuardarK;
    QGroupBox *groupPolos;
    QGridLayout *gridLayout_8;
    QPushButton *pushGuardarPolos;
    QFormLayout *formPolos;
    QGroupBox *groupBoxL;
    QGridLayout *gridLayout_13;
    QLabel *labelL;
    QTextEdit *textL;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *comboTipoObs;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tabPlot;
    QGridLayout *gridPlot;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ControlModerno)
    {
        if (ControlModerno->objectName().isEmpty())
            ControlModerno->setObjectName(QStringLiteral("ControlModerno"));
        ControlModerno->resize(1024, 838);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlModerno->sizePolicy().hasHeightForWidth());
        ControlModerno->setSizePolicy(sizePolicy);
        ControlModerno->setMinimumSize(QSize(700, 700));
        ControlModerno->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ControlModerno->setDocumentMode(false);
        ControlModerno->setDockNestingEnabled(false);
        actionSimular = new QAction(ControlModerno);
        actionSimular->setObjectName(QStringLiteral("actionSimular"));
        actionAplicar = new QAction(ControlModerno);
        actionAplicar->setObjectName(QStringLiteral("actionAplicar"));
        actionGuardarPolos = new QAction(ControlModerno);
        actionGuardarPolos->setObjectName(QStringLiteral("actionGuardarPolos"));
        actionExportar = new QAction(ControlModerno);
        actionExportar->setObjectName(QStringLiteral("actionExportar"));
        actionCopy_for_Matlab = new QAction(ControlModerno);
        actionCopy_for_Matlab->setObjectName(QStringLiteral("actionCopy_for_Matlab"));
        centralwidget = new QWidget(ControlModerno);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMovable(true);
        tabParametros = new QWidget();
        tabParametros->setObjectName(QStringLiteral("tabParametros"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabParametros->sizePolicy().hasHeightForWidth());
        tabParametros->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(tabParametros);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupParametros = new QGroupBox(tabParametros);
        groupParametros->setObjectName(QStringLiteral("groupParametros"));
        gridLayout_2 = new QGridLayout(groupParametros);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frameD = new QFrame(groupParametros);
        frameD->setObjectName(QStringLiteral("frameD"));
        frameD->setMinimumSize(QSize(150, 75));
        frameD->setFrameShape(QFrame::StyledPanel);
        frameD->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameD);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelD = new QLabel(frameD);
        labelD->setObjectName(QStringLiteral("labelD"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelD->sizePolicy().hasHeightForWidth());
        labelD->setSizePolicy(sizePolicy2);
        labelD->setMinimumSize(QSize(50, 50));
        labelD->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(labelD);

        textD = new QTextEdit(frameD);
        textD->setObjectName(QStringLiteral("textD"));
        sizePolicy2.setHeightForWidth(textD->sizePolicy().hasHeightForWidth());
        textD->setSizePolicy(sizePolicy2);
        textD->setMaximumSize(QSize(500, 75));
        textD->setTabChangesFocus(true);
        textD->setReadOnly(false);

        horizontalLayout_4->addWidget(textD);

        textD->raise();
        labelD->raise();

        gridLayout_2->addWidget(frameD, 2, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushAplicar = new QPushButton(groupParametros);
        pushAplicar->setObjectName(QStringLiteral("pushAplicar"));

        gridLayout_4->addWidget(pushAplicar, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 3, 0, 1, 2);

        frameB = new QFrame(groupParametros);
        frameB->setObjectName(QStringLiteral("frameB"));
        frameB->setMinimumSize(QSize(150, 75));
        frameB->setFrameShape(QFrame::StyledPanel);
        frameB->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameB);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelB = new QLabel(frameB);
        labelB->setObjectName(QStringLiteral("labelB"));
        sizePolicy2.setHeightForWidth(labelB->sizePolicy().hasHeightForWidth());
        labelB->setSizePolicy(sizePolicy2);
        labelB->setMinimumSize(QSize(50, 50));
        labelB->setMaximumSize(QSize(50, 50));

        horizontalLayout_2->addWidget(labelB);

        textB = new QTextEdit(frameB);
        textB->setObjectName(QStringLiteral("textB"));
        sizePolicy2.setHeightForWidth(textB->sizePolicy().hasHeightForWidth());
        textB->setSizePolicy(sizePolicy2);
        textB->setMaximumSize(QSize(500, 75));
        textB->setTabChangesFocus(true);
        textB->setReadOnly(false);

        horizontalLayout_2->addWidget(textB);


        gridLayout_2->addWidget(frameB, 1, 1, 1, 1);

        frameC = new QFrame(groupParametros);
        frameC->setObjectName(QStringLiteral("frameC"));
        frameC->setMinimumSize(QSize(150, 75));
        frameC->setFrameShape(QFrame::StyledPanel);
        frameC->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameC);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelC = new QLabel(frameC);
        labelC->setObjectName(QStringLiteral("labelC"));
        sizePolicy2.setHeightForWidth(labelC->sizePolicy().hasHeightForWidth());
        labelC->setSizePolicy(sizePolicy2);
        labelC->setMinimumSize(QSize(50, 50));
        labelC->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(labelC);

        textC = new QTextBrowser(frameC);
        textC->setObjectName(QStringLiteral("textC"));
        sizePolicy2.setHeightForWidth(textC->sizePolicy().hasHeightForWidth());
        textC->setSizePolicy(sizePolicy2);
        textC->setMaximumSize(QSize(500, 75));
        textC->setTabChangesFocus(true);
        textC->setReadOnly(false);

        horizontalLayout_3->addWidget(textC);


        gridLayout_2->addWidget(frameC, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelEntradas = new QLabel(groupParametros);
        labelEntradas->setObjectName(QStringLiteral("labelEntradas"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelEntradas);

        spinEntradas = new QSpinBox(groupParametros);
        spinEntradas->setObjectName(QStringLiteral("spinEntradas"));
        spinEntradas->setMaximumSize(QSize(50, 16777215));
        spinEntradas->setMinimum(1);
        spinEntradas->setMaximum(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinEntradas);

        labelSalidas = new QLabel(groupParametros);
        labelSalidas->setObjectName(QStringLiteral("labelSalidas"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSalidas);

        spinSalidas = new QSpinBox(groupParametros);
        spinSalidas->setObjectName(QStringLiteral("spinSalidas"));
        spinSalidas->setMaximumSize(QSize(50, 16777215));
        spinSalidas->setMinimum(1);
        spinSalidas->setMaximum(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinSalidas);

        labelVE = new QLabel(groupParametros);
        labelVE->setObjectName(QStringLiteral("labelVE"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelVE);

        spinVE = new QSpinBox(groupParametros);
        spinVE->setObjectName(QStringLiteral("spinVE"));
        spinVE->setMaximumSize(QSize(50, 16777215));
        spinVE->setMinimum(1);
        spinVE->setMaximum(10);
        spinVE->setValue(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinVE);

        LabelTs = new QLabel(groupParametros);
        LabelTs->setObjectName(QStringLiteral("LabelTs"));

        formLayout->setWidget(3, QFormLayout::LabelRole, LabelTs);

        lineTs = new QLineEdit(groupParametros);
        lineTs->setObjectName(QStringLiteral("lineTs"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineTs->sizePolicy().hasHeightForWidth());
        lineTs->setSizePolicy(sizePolicy3);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineTs);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 2);

        frameA = new QFrame(groupParametros);
        frameA->setObjectName(QStringLiteral("frameA"));
        frameA->setMinimumSize(QSize(150, 75));
        frameA->setFrameShape(QFrame::StyledPanel);
        frameA->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameA);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelA = new QLabel(frameA);
        labelA->setObjectName(QStringLiteral("labelA"));
        sizePolicy2.setHeightForWidth(labelA->sizePolicy().hasHeightForWidth());
        labelA->setSizePolicy(sizePolicy2);
        labelA->setMinimumSize(QSize(50, 50));
        labelA->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(labelA);

        textA = new QTextBrowser(frameA);
        textA->setObjectName(QStringLiteral("textA"));
        sizePolicy2.setHeightForWidth(textA->sizePolicy().hasHeightForWidth());
        textA->setSizePolicy(sizePolicy2);
        textA->setMaximumSize(QSize(500, 75));
        textA->setTabChangesFocus(true);
        textA->setReadOnly(false);

        horizontalLayout->addWidget(textA);


        gridLayout_2->addWidget(frameA, 1, 0, 1, 1);


        verticalLayout->addWidget(groupParametros);

        groupMatrices = new QFrame(tabParametros);
        groupMatrices->setObjectName(QStringLiteral("groupMatrices"));
        groupMatrices->setMinimumSize(QSize(0, 50));
        gridLayout_5 = new QGridLayout(groupMatrices);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBoxPHI = new QGroupBox(groupMatrices);
        groupBoxPHI->setObjectName(QStringLiteral("groupBoxPHI"));
        groupBoxPHI->setMinimumSize(QSize(150, 75));
        horizontalLayout_5 = new QHBoxLayout(groupBoxPHI);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelPHI = new QLabel(groupBoxPHI);
        labelPHI->setObjectName(QStringLiteral("labelPHI"));
        sizePolicy2.setHeightForWidth(labelPHI->sizePolicy().hasHeightForWidth());
        labelPHI->setSizePolicy(sizePolicy2);
        labelPHI->setMinimumSize(QSize(50, 50));
        labelPHI->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(labelPHI);

        textPhi = new QTextEdit(groupBoxPHI);
        textPhi->setObjectName(QStringLiteral("textPhi"));
        sizePolicy2.setHeightForWidth(textPhi->sizePolicy().hasHeightForWidth());
        textPhi->setSizePolicy(sizePolicy2);
        textPhi->setMaximumSize(QSize(500, 75));
        textPhi->setReadOnly(true);

        horizontalLayout_5->addWidget(textPhi);


        gridLayout_5->addWidget(groupBoxPHI, 0, 0, 1, 1);

        groupBoxPSI = new QGroupBox(groupMatrices);
        groupBoxPSI->setObjectName(QStringLiteral("groupBoxPSI"));
        groupBoxPSI->setMinimumSize(QSize(150, 75));
        horizontalLayout_6 = new QHBoxLayout(groupBoxPSI);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelPSI = new QLabel(groupBoxPSI);
        labelPSI->setObjectName(QStringLiteral("labelPSI"));
        sizePolicy2.setHeightForWidth(labelPSI->sizePolicy().hasHeightForWidth());
        labelPSI->setSizePolicy(sizePolicy2);
        labelPSI->setMinimumSize(QSize(50, 50));
        labelPSI->setMaximumSize(QSize(50, 50));

        horizontalLayout_6->addWidget(labelPSI);

        textPsi = new QTextEdit(groupBoxPSI);
        textPsi->setObjectName(QStringLiteral("textPsi"));
        sizePolicy2.setHeightForWidth(textPsi->sizePolicy().hasHeightForWidth());
        textPsi->setSizePolicy(sizePolicy2);
        textPsi->setMaximumSize(QSize(500, 75));
        textPsi->setReadOnly(true);

        horizontalLayout_6->addWidget(textPsi);


        gridLayout_5->addWidget(groupBoxPSI, 0, 1, 1, 1);


        verticalLayout->addWidget(groupMatrices);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        tabWidget->addTab(tabParametros, QString());
        tabSimulacion = new QWidget();
        tabSimulacion->setObjectName(QStringLiteral("tabSimulacion"));
        gridLayout_6 = new QGridLayout(tabSimulacion);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupIniciales = new QGroupBox(tabSimulacion);
        groupIniciales->setObjectName(QStringLiteral("groupIniciales"));
        gridLayout_12 = new QGridLayout(groupIniciales);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        formIniciales = new QFormLayout();
        formIniciales->setObjectName(QStringLiteral("formIniciales"));

        gridLayout_12->addLayout(formIniciales, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupIniciales, 0, 2, 1, 1);

        groupEntrada = new QGroupBox(tabSimulacion);
        groupEntrada->setObjectName(QStringLiteral("groupEntrada"));
        groupEntrada->setFlat(false);
        horizontalLayout_9 = new QHBoxLayout(groupEntrada);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        lineTo = new QLineEdit(groupEntrada);
        lineTo->setObjectName(QStringLiteral("lineTo"));
        sizePolicy3.setHeightForWidth(lineTo->sizePolicy().hasHeightForWidth());
        lineTo->setSizePolicy(sizePolicy3);
        lineTo->setMinimumSize(QSize(75, 0));
        lineTo->setInputMask(QStringLiteral(""));
        lineTo->setText(QStringLiteral("0.5"));
        lineTo->setMaxLength(8);
        lineTo->setClearButtonEnabled(false);

        gridLayout_11->addWidget(lineTo, 2, 1, 1, 1);

        labelAmp = new QLabel(groupEntrada);
        labelAmp->setObjectName(QStringLiteral("labelAmp"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelAmp->sizePolicy().hasHeightForWidth());
        labelAmp->setSizePolicy(sizePolicy4);
        labelAmp->setMinimumSize(QSize(50, 0));
        labelAmp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(labelAmp, 3, 0, 1, 1);

        lineAmp = new QLineEdit(groupEntrada);
        lineAmp->setObjectName(QStringLiteral("lineAmp"));
        sizePolicy3.setHeightForWidth(lineAmp->sizePolicy().hasHeightForWidth());
        lineAmp->setSizePolicy(sizePolicy3);
        lineAmp->setMinimumSize(QSize(75, 0));
        lineAmp->setInputMask(QStringLiteral(""));
        lineAmp->setText(QStringLiteral("1"));
        lineAmp->setMaxLength(8);
        lineAmp->setClearButtonEnabled(false);

        gridLayout_11->addWidget(lineAmp, 3, 1, 1, 1);

        labelN = new QLabel(groupEntrada);
        labelN->setObjectName(QStringLiteral("labelN"));
        sizePolicy4.setHeightForWidth(labelN->sizePolicy().hasHeightForWidth());
        labelN->setSizePolicy(sizePolicy4);
        labelN->setMinimumSize(QSize(50, 0));
        labelN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(labelN, 4, 0, 1, 1);

        labelTo = new QLabel(groupEntrada);
        labelTo->setObjectName(QStringLiteral("labelTo"));
        sizePolicy4.setHeightForWidth(labelTo->sizePolicy().hasHeightForWidth());
        labelTo->setSizePolicy(sizePolicy4);
        labelTo->setMinimumSize(QSize(50, 0));
        labelTo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(labelTo, 2, 0, 1, 1);

        lineN = new QLineEdit(groupEntrada);
        lineN->setObjectName(QStringLiteral("lineN"));
        sizePolicy3.setHeightForWidth(lineN->sizePolicy().hasHeightForWidth());
        lineN->setSizePolicy(sizePolicy3);
        lineN->setMinimumSize(QSize(75, 0));
        lineN->setMaxLength(15);
        lineN->setReadOnly(true);

        gridLayout_11->addWidget(lineN, 4, 1, 1, 1);

        labelTf = new QLabel(groupEntrada);
        labelTf->setObjectName(QStringLiteral("labelTf"));
        sizePolicy4.setHeightForWidth(labelTf->sizePolicy().hasHeightForWidth());
        labelTf->setSizePolicy(sizePolicy4);
        labelTf->setMinimumSize(QSize(50, 0));
        labelTf->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(labelTf, 1, 0, 1, 1);

        lineTf = new QLineEdit(groupEntrada);
        lineTf->setObjectName(QStringLiteral("lineTf"));
        sizePolicy3.setHeightForWidth(lineTf->sizePolicy().hasHeightForWidth());
        lineTf->setSizePolicy(sizePolicy3);
        lineTf->setMinimumSize(QSize(75, 0));
        lineTf->setInputMask(QStringLiteral(""));
        lineTf->setText(QStringLiteral("1"));
        lineTf->setMaxLength(8);
        lineTf->setClearButtonEnabled(false);

        gridLayout_11->addWidget(lineTf, 1, 1, 1, 1);

        labelTipo = new QLabel(groupEntrada);
        labelTipo->setObjectName(QStringLiteral("labelTipo"));
        sizePolicy3.setHeightForWidth(labelTipo->sizePolicy().hasHeightForWidth());
        labelTipo->setSizePolicy(sizePolicy3);
        labelTipo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_11->addWidget(labelTipo, 0, 0, 1, 1);

        comboTipoSenial = new QComboBox(groupEntrada);
        comboTipoSenial->setObjectName(QStringLiteral("comboTipoSenial"));
        sizePolicy4.setHeightForWidth(comboTipoSenial->sizePolicy().hasHeightForWidth());
        comboTipoSenial->setSizePolicy(sizePolicy4);
        comboTipoSenial->setMinimumSize(QSize(150, 0));

        gridLayout_11->addWidget(comboTipoSenial, 0, 1, 1, 1);


        horizontalLayout_9->addLayout(gridLayout_11);


        gridLayout_6->addWidget(groupEntrada, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 3, 1, 1);

        imagenEntrada = new QLabel(tabSimulacion);
        imagenEntrada->setObjectName(QStringLiteral("imagenEntrada"));
        sizePolicy2.setHeightForWidth(imagenEntrada->sizePolicy().hasHeightForWidth());
        imagenEntrada->setSizePolicy(sizePolicy2);
        imagenEntrada->setMinimumSize(QSize(250, 250));
        imagenEntrada->setMaximumSize(QSize(400, 1000));
        imagenEntrada->setStyleSheet(QStringLiteral("image: url(:/imagenes/Entrada.svg);"));
        imagenEntrada->setText(QStringLiteral(""));

        gridLayout_6->addWidget(imagenEntrada, 0, 1, 1, 1);

        pushSimular = new QPushButton(tabSimulacion);
        pushSimular->setObjectName(QStringLiteral("pushSimular"));
        sizePolicy3.setHeightForWidth(pushSimular->sizePolicy().hasHeightForWidth());
        pushSimular->setSizePolicy(sizePolicy3);
        pushSimular->setLayoutDirection(Qt::RightToLeft);

        gridLayout_6->addWidget(pushSimular, 1, 0, 1, 4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 2, 0, 1, 4);

        tabWidget->addTab(tabSimulacion, QString());
        tabControl = new QWidget();
        tabControl->setObjectName(QStringLiteral("tabControl"));
        gridLayout_3 = new QGridLayout(tabControl);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 7, 0, 1, 1);

        pushControl = new QPushButton(tabControl);
        pushControl->setObjectName(QStringLiteral("pushControl"));
        sizePolicy3.setHeightForWidth(pushControl->sizePolicy().hasHeightForWidth());
        pushControl->setSizePolicy(sizePolicy3);
        pushControl->setLayoutDirection(Qt::RightToLeft);
        pushControl->setCheckable(true);
        pushControl->setAutoRepeat(false);

        gridLayout_3->addWidget(pushControl, 5, 0, 1, 5);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        x0Label = new QLabel(tabControl);
        x0Label->setObjectName(QStringLiteral("x0Label"));
        sizePolicy3.setHeightForWidth(x0Label->sizePolicy().hasHeightForWidth());
        x0Label->setSizePolicy(sizePolicy3);

        gridLayout_10->addWidget(x0Label, 0, 0, 1, 1);

        x0Slider = new QSlider(tabControl);
        x0Slider->setObjectName(QStringLiteral("x0Slider"));
        sizePolicy3.setHeightForWidth(x0Slider->sizePolicy().hasHeightForWidth());
        x0Slider->setSizePolicy(sizePolicy3);
        x0Slider->setMinimumSize(QSize(400, 0));
        x0Slider->setMaximum(6260);
        x0Slider->setSingleStep(10);
        x0Slider->setPageStep(50);
        x0Slider->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(x0Slider, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_10, 6, 0, 1, 5);

        groupBoxK = new QGroupBox(tabControl);
        groupBoxK->setObjectName(QStringLiteral("groupBoxK"));
        sizePolicy3.setHeightForWidth(groupBoxK->sizePolicy().hasHeightForWidth());
        groupBoxK->setSizePolicy(sizePolicy3);
        groupBoxK->setMinimumSize(QSize(150, 75));
        gridLayout_7 = new QGridLayout(groupBoxK);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        textK = new QTextEdit(groupBoxK);
        textK->setObjectName(QStringLiteral("textK"));
        sizePolicy2.setHeightForWidth(textK->sizePolicy().hasHeightForWidth());
        textK->setSizePolicy(sizePolicy2);
        textK->setMaximumSize(QSize(500, 50));
        textK->setReadOnly(false);

        gridLayout_7->addWidget(textK, 0, 1, 1, 2);

        labelK = new QLabel(groupBoxK);
        labelK->setObjectName(QStringLiteral("labelK"));
        sizePolicy2.setHeightForWidth(labelK->sizePolicy().hasHeightForWidth());
        labelK->setSizePolicy(sizePolicy2);
        labelK->setMinimumSize(QSize(50, 50));
        labelK->setMaximumSize(QSize(50, 50));

        gridLayout_7->addWidget(labelK, 0, 0, 1, 1);

        pushGuardarK = new QPushButton(groupBoxK);
        pushGuardarK->setObjectName(QStringLiteral("pushGuardarK"));
        sizePolicy3.setHeightForWidth(pushGuardarK->sizePolicy().hasHeightForWidth());
        pushGuardarK->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(pushGuardarK, 1, 0, 1, 3);


        gridLayout_3->addWidget(groupBoxK, 0, 1, 1, 1);

        groupPolos = new QGroupBox(tabControl);
        groupPolos->setObjectName(QStringLiteral("groupPolos"));
        sizePolicy2.setHeightForWidth(groupPolos->sizePolicy().hasHeightForWidth());
        groupPolos->setSizePolicy(sizePolicy2);
        gridLayout_8 = new QGridLayout(groupPolos);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushGuardarPolos = new QPushButton(groupPolos);
        pushGuardarPolos->setObjectName(QStringLiteral("pushGuardarPolos"));
        sizePolicy3.setHeightForWidth(pushGuardarPolos->sizePolicy().hasHeightForWidth());
        pushGuardarPolos->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(pushGuardarPolos, 1, 0, 1, 1);

        formPolos = new QFormLayout();
        formPolos->setObjectName(QStringLiteral("formPolos"));

        gridLayout_8->addLayout(formPolos, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupPolos, 0, 0, 1, 1);

        groupBoxL = new QGroupBox(tabControl);
        groupBoxL->setObjectName(QStringLiteral("groupBoxL"));
        sizePolicy3.setHeightForWidth(groupBoxL->sizePolicy().hasHeightForWidth());
        groupBoxL->setSizePolicy(sizePolicy3);
        groupBoxL->setMinimumSize(QSize(150, 75));
        gridLayout_13 = new QGridLayout(groupBoxL);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        labelL = new QLabel(groupBoxL);
        labelL->setObjectName(QStringLiteral("labelL"));
        sizePolicy2.setHeightForWidth(labelL->sizePolicy().hasHeightForWidth());
        labelL->setSizePolicy(sizePolicy2);
        labelL->setMinimumSize(QSize(50, 50));
        labelL->setMaximumSize(QSize(50, 50));

        gridLayout_13->addWidget(labelL, 0, 0, 1, 1);

        textL = new QTextEdit(groupBoxL);
        textL->setObjectName(QStringLiteral("textL"));
        sizePolicy2.setHeightForWidth(textL->sizePolicy().hasHeightForWidth());
        textL->setSizePolicy(sizePolicy2);
        textL->setMaximumSize(QSize(500, 50));
        textL->setReadOnly(false);

        gridLayout_13->addWidget(textL, 0, 1, 1, 2);


        gridLayout_3->addWidget(groupBoxL, 3, 1, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(tabControl);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        comboTipoObs = new QComboBox(tabControl);
        comboTipoObs->setObjectName(QStringLiteral("comboTipoObs"));
        sizePolicy3.setHeightForWidth(comboTipoObs->sizePolicy().hasHeightForWidth());
        comboTipoObs->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(comboTipoObs);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout_3->addLayout(verticalLayout_2, 3, 0, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        tabWidget->addTab(tabControl, QString());
        tabPlot = new QWidget();
        tabPlot->setObjectName(QStringLiteral("tabPlot"));
        gridPlot = new QGridLayout(tabPlot);
        gridPlot->setObjectName(QStringLiteral("gridPlot"));
        tabWidget->addTab(tabPlot, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        ControlModerno->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ControlModerno);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 20));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        ControlModerno->setMenuBar(menubar);
        statusbar = new QStatusBar(ControlModerno);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ControlModerno->setStatusBar(statusbar);
        toolBar = new QToolBar(ControlModerno);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar->setFloatable(false);
        ControlModerno->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(spinEntradas, spinSalidas);
        QWidget::setTabOrder(spinSalidas, spinVE);
        QWidget::setTabOrder(spinVE, textA);
        QWidget::setTabOrder(textA, textB);
        QWidget::setTabOrder(textB, textC);
        QWidget::setTabOrder(textC, textD);
        QWidget::setTabOrder(textD, pushAplicar);
        QWidget::setTabOrder(pushAplicar, textPsi);
        QWidget::setTabOrder(textPsi, textPhi);

        menubar->addAction(menuMenu->menuAction());
        toolBar->addAction(actionAplicar);
        toolBar->addAction(actionSimular);
        toolBar->addAction(actionGuardarPolos);
        toolBar->addAction(actionExportar);
        toolBar->addSeparator();

        retranslateUi(ControlModerno);
        QObject::connect(pushAplicar, SIGNAL(clicked()), actionAplicar, SLOT(trigger()));
        QObject::connect(pushSimular, SIGNAL(clicked()), actionSimular, SLOT(trigger()));
        QObject::connect(pushGuardarPolos, SIGNAL(clicked()), actionGuardarPolos, SLOT(trigger()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ControlModerno);
    } // setupUi

    void retranslateUi(QMainWindow *ControlModerno)
    {
        ControlModerno->setWindowTitle(QApplication::translate("ControlModerno", "Control Moderno", 0));
        actionSimular->setText(QApplication::translate("ControlModerno", "Simular ", 0));
#ifndef QT_NO_TOOLTIP
        actionSimular->setToolTip(QApplication::translate("ControlModerno", "Simular Salidas", 0));
#endif // QT_NO_TOOLTIP
        actionSimular->setShortcut(QApplication::translate("ControlModerno", "Ctrl+S", 0));
        actionAplicar->setText(QApplication::translate("ControlModerno", "Aplicar", 0));
#ifndef QT_NO_TOOLTIP
        actionAplicar->setToolTip(QApplication::translate("ControlModerno", "Aplicar cambios", 0));
#endif // QT_NO_TOOLTIP
        actionAplicar->setShortcut(QApplication::translate("ControlModerno", "Ctrl+A", 0));
        actionGuardarPolos->setText(QApplication::translate("ControlModerno", "Guardar Polos", 0));
#ifndef QT_NO_TOOLTIP
        actionGuardarPolos->setToolTip(QApplication::translate("ControlModerno", "Guardar condiciones Iniciales", 0));
#endif // QT_NO_TOOLTIP
        actionGuardarPolos->setShortcut(QApplication::translate("ControlModerno", "Ctrl+Shift+G", 0));
        actionExportar->setText(QApplication::translate("ControlModerno", "Exportar", 0));
#ifndef QT_NO_TOOLTIP
        actionExportar->setToolTip(QApplication::translate("ControlModerno", "Exportar datos", 0));
#endif // QT_NO_TOOLTIP
        actionExportar->setShortcut(QApplication::translate("ControlModerno", "Ctrl+E", 0));
        actionCopy_for_Matlab->setText(QApplication::translate("ControlModerno", "Copy for Matlab", 0));
#ifndef QT_NO_TOOLTIP
        actionCopy_for_Matlab->setToolTip(QApplication::translate("ControlModerno", "Copiar en formato Matlab", 0));
#endif // QT_NO_TOOLTIP
        groupParametros->setTitle(QApplication::translate("ControlModerno", "Parametros del sistema", 0));
        labelD->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">D =</span></p></body></html>", 0));
        pushAplicar->setText(QApplication::translate("ControlModerno", "Aplicar", 0));
        labelB->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">B = </span></p></body></html>", 0));
        labelC->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">C =</span></p></body></html>", 0));
        labelEntradas->setText(QApplication::translate("ControlModerno", "Entradas", 0));
        labelSalidas->setText(QApplication::translate("ControlModerno", "Salidas", 0));
        labelVE->setText(QApplication::translate("ControlModerno", "Variables de Estado", 0));
        LabelTs->setText(QApplication::translate("ControlModerno", "T Sample", 0));
        labelA->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">A =</span></p></body></html>", 0));
        groupBoxPHI->setTitle(QApplication::translate("ControlModerno", "Matriz Fundamental:", 0));
        labelPHI->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">\317\225 =</span></p></body></html>", 0));
        groupBoxPSI->setTitle(QApplication::translate("ControlModerno", "Matriz de Transici\303\263n:", 0));
        labelPSI->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">\317\210 = </span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabParametros), QApplication::translate("ControlModerno", "Parametros", 0));
        groupIniciales->setTitle(QApplication::translate("ControlModerno", "Condiciones Iniciales", 0));
        groupEntrada->setTitle(QApplication::translate("ControlModerno", "Se\303\261al de Entrada", 0));
        labelAmp->setText(QApplication::translate("ControlModerno", "A =", 0));
        labelN->setText(QApplication::translate("ControlModerno", "N =", 0));
        labelTo->setText(QApplication::translate("ControlModerno", "To =", 0));
        labelTf->setText(QApplication::translate("ControlModerno", "Tf =", 0));
        labelTipo->setText(QApplication::translate("ControlModerno", "Tipo:", 0));
        comboTipoSenial->clear();
        comboTipoSenial->insertItems(0, QStringList()
         << QApplication::translate("ControlModerno", "Escal\303\263n", 0)
         << QApplication::translate("ControlModerno", "Rampa", 0)
         << QApplication::translate("ControlModerno", "Parabola", 0)
        );
        pushSimular->setText(QApplication::translate("ControlModerno", "Simular", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSimulacion), QApplication::translate("ControlModerno", "Simulacion", 0));
        pushControl->setText(QApplication::translate("ControlModerno", "Controlar", 0));
        x0Label->setText(QApplication::translate("ControlModerno", "X0", 0));
        groupBoxK->setTitle(QApplication::translate("ControlModerno", "Matriz K de control", 0));
        labelK->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">K =</span></p></body></html>", 0));
        pushGuardarK->setText(QApplication::translate("ControlModerno", "Guardar", 0));
        groupPolos->setTitle(QApplication::translate("ControlModerno", "Polos de lazo Cerrado", 0));
        pushGuardarPolos->setText(QApplication::translate("ControlModerno", "Guardar", 0));
        groupBoxL->setTitle(QApplication::translate("ControlModerno", "Matriz L del observador", 0));
        labelL->setText(QApplication::translate("ControlModerno", "<html><head/><body><p><span style=\" font-size:14pt;\">L =</span></p></body></html>", 0));
        label->setText(QApplication::translate("ControlModerno", "Tipo de observador:", 0));
        comboTipoObs->clear();
        comboTipoObs->insertItems(0, QStringList()
         << QApplication::translate("ControlModerno", "Sin observador", 0)
         << QApplication::translate("ControlModerno", "Completo", 0)
         << QApplication::translate("ControlModerno", "Reducido", 0)
         << QApplication::translate("ControlModerno", "Filtro de Kalman", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tabControl), QApplication::translate("ControlModerno", "Control", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabPlot), QApplication::translate("ControlModerno", "Gr\303\241fico", 0));
        menuMenu->setTitle(QApplication::translate("ControlModerno", "Menu", 0));
        toolBar->setWindowTitle(QApplication::translate("ControlModerno", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlModerno: public Ui_ControlModerno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
