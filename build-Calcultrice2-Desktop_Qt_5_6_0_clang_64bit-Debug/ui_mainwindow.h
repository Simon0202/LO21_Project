/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Calculatrice;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ligneSaisie;
    QLineEdit *lineEdit;
    QPushButton *pushBoutonDel;
    QWidget *clavierSaisie1;
    QHBoxLayout *clavierSaisie;
    QGridLayout *clavierNumerique;
    QPushButton *pushButton7;
    QPushButton *pushButton4;
    QPushButton *pushButton9;
    QPushButton *pushButton1;
    QPushButton *pushButton6;
    QPushButton *pushButton8;
    QPushButton *pushButton3;
    QPushButton *pushButton2;
    QPushButton *pushButton5;
    QPushButton *pushButton0;
    QVBoxLayout *operateurBase;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonMoins;
    QPushButton *pushButtonMul;
    QPushButton *pushButtonDiv1;
    QGridLayout *clavierLettres;
    QPushButton *pushButtonQ;
    QPushButton *pushButtonR;
    QPushButton *pushButtonJ;
    QPushButton *pushButtonO;
    QPushButton *pushButtonX;
    QPushButton *pushButtonS;
    QPushButton *pushButtonD;
    QPushButton *pushButtonH;
    QPushButton *pushButtonN;
    QPushButton *pushButtonZ;
    QPushButton *pushButtonV;
    QPushButton *pushButtonI;
    QPushButton *pushButtonK;
    QPushButton *pushButtonP;
    QPushButton *pushButtonB;
    QPushButton *pushButtonF;
    QPushButton *pushButtonW;
    QPushButton *pushButtonL;
    QPushButton *pushButtonC;
    QPushButton *pushButtonA;
    QPushButton *pushButtonU;
    QPushButton *pushButtonT;
    QPushButton *pushButtonE;
    QPushButton *pushButtonM;
    QPushButton *pushButtonY;
    QPushButton *pushButtonG;
    QPushButton *pushButtonSpace;
    QWidget *layoutWidget;
    QHBoxLayout *operateurSpeciaux;
    QGridLayout *boutonSpeciaux;
    QPushButton *pushButtonSwap;
    QPushButton *pushButtonDen;
    QPushButton *pushButtonLastArg;
    QPushButton *pushButtoNot;
    QPushButton *pushButtonAnd;
    QPushButton *pushButtonNeg;
    QPushButton *pushButtonNum;
    QPushButton *pushButtonDup;
    QPushButton *pushButtonDrop;
    QPushButton *pushButtonIm;
    QPushButton *pushButtonLastop;
    QPushButton *pushButtonIft;
    QPushButton *pushButtonDollar;
    QPushButton *pushButtonRe;
    QPushButton *pushButtonOr;
    QPushButton *pushButtonDiv;
    QVBoxLayout *EvEdStFo;
    QPushButton *pushButtonEval;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonSto;
    QPushButton *pushButtonForget;
    QVBoxLayout *EntCleUndRed;
    QPushButton *pushButtonEnter;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonUndo;
    QPushButton *pushButtonRedo;
    QTableWidget *vuePile;
    QLineEdit *message;
    QWidget *Options;
    QWidget *layoutWidget_3;
    QVBoxLayout *formulaireParam;
    QLabel *label1;
    QVBoxLayout *checkBoxPar;
    QCheckBox *checkClavier;
    QCheckBox *checkSond;
    QLCDNumber *lcdNumber;
    QHBoxLayout *taillePile;
    QLabel *label2;
    QSlider *verticalSlider;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(765, 622);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(610, 581));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 711, 581));
        tabWidget->setMinimumSize(QSize(650, 550));
        Calculatrice = new QWidget();
        Calculatrice->setObjectName(QStringLiteral("Calculatrice"));
        horizontalLayoutWidget = new QWidget(Calculatrice);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(39, 230, 601, 33));
        horizontalLayoutWidget->setMinimumSize(QSize(601, 0));
        ligneSaisie = new QHBoxLayout(horizontalLayoutWidget);
        ligneSaisie->setSpacing(6);
        ligneSaisie->setContentsMargins(11, 11, 11, 11);
        ligneSaisie->setObjectName(QStringLiteral("ligneSaisie"));
        ligneSaisie->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        ligneSaisie->addWidget(lineEdit);

        pushBoutonDel = new QPushButton(horizontalLayoutWidget);
        pushBoutonDel->setObjectName(QStringLiteral("pushBoutonDel"));

        ligneSaisie->addWidget(pushBoutonDel);

        clavierSaisie1 = new QWidget(Calculatrice);
        clavierSaisie1->setObjectName(QStringLiteral("clavierSaisie1"));
        clavierSaisie1->setGeometry(QRect(30, 410, 621, 136));
        clavierSaisie = new QHBoxLayout(clavierSaisie1);
        clavierSaisie->setSpacing(6);
        clavierSaisie->setContentsMargins(11, 11, 11, 11);
        clavierSaisie->setObjectName(QStringLiteral("clavierSaisie"));
        clavierNumerique = new QGridLayout();
        clavierNumerique->setSpacing(6);
        clavierNumerique->setObjectName(QStringLiteral("clavierNumerique"));
        pushButton7 = new QPushButton(clavierSaisie1);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));

        clavierNumerique->addWidget(pushButton7, 2, 0, 1, 1);

        pushButton4 = new QPushButton(clavierSaisie1);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));

        clavierNumerique->addWidget(pushButton4, 1, 0, 1, 1);

        pushButton9 = new QPushButton(clavierSaisie1);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));

        clavierNumerique->addWidget(pushButton9, 2, 2, 1, 1);

        pushButton1 = new QPushButton(clavierSaisie1);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));

        clavierNumerique->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton6 = new QPushButton(clavierSaisie1);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));

        clavierNumerique->addWidget(pushButton6, 1, 2, 1, 1);

        pushButton8 = new QPushButton(clavierSaisie1);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));

        clavierNumerique->addWidget(pushButton8, 2, 1, 1, 1);

        pushButton3 = new QPushButton(clavierSaisie1);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));

        clavierNumerique->addWidget(pushButton3, 0, 2, 1, 1);

        pushButton2 = new QPushButton(clavierSaisie1);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));

        clavierNumerique->addWidget(pushButton2, 0, 1, 1, 1);

        pushButton5 = new QPushButton(clavierSaisie1);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));

        clavierNumerique->addWidget(pushButton5, 1, 1, 1, 1);

        pushButton0 = new QPushButton(clavierSaisie1);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));

        clavierNumerique->addWidget(pushButton0, 3, 1, 1, 1);


        clavierSaisie->addLayout(clavierNumerique);

        operateurBase = new QVBoxLayout();
        operateurBase->setSpacing(6);
        operateurBase->setObjectName(QStringLiteral("operateurBase"));
        pushButtonPlus = new QPushButton(clavierSaisie1);
        pushButtonPlus->setObjectName(QStringLiteral("pushButtonPlus"));

        operateurBase->addWidget(pushButtonPlus);

        pushButtonMoins = new QPushButton(clavierSaisie1);
        pushButtonMoins->setObjectName(QStringLiteral("pushButtonMoins"));

        operateurBase->addWidget(pushButtonMoins);

        pushButtonMul = new QPushButton(clavierSaisie1);
        pushButtonMul->setObjectName(QStringLiteral("pushButtonMul"));

        operateurBase->addWidget(pushButtonMul);

        pushButtonDiv1 = new QPushButton(clavierSaisie1);
        pushButtonDiv1->setObjectName(QStringLiteral("pushButtonDiv1"));

        operateurBase->addWidget(pushButtonDiv1);


        clavierSaisie->addLayout(operateurBase);

        clavierLettres = new QGridLayout();
        clavierLettres->setSpacing(6);
        clavierLettres->setObjectName(QStringLiteral("clavierLettres"));
        pushButtonQ = new QPushButton(clavierSaisie1);
        pushButtonQ->setObjectName(QStringLiteral("pushButtonQ"));
        pushButtonQ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonQ, 2, 2, 1, 1);

        pushButtonR = new QPushButton(clavierSaisie1);
        pushButtonR->setObjectName(QStringLiteral("pushButtonR"));
        pushButtonR->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonR, 2, 3, 1, 1);

        pushButtonJ = new QPushButton(clavierSaisie1);
        pushButtonJ->setObjectName(QStringLiteral("pushButtonJ"));
        pushButtonJ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonJ, 1, 2, 1, 1);

        pushButtonO = new QPushButton(clavierSaisie1);
        pushButtonO->setObjectName(QStringLiteral("pushButtonO"));
        pushButtonO->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonO, 2, 0, 1, 1);

        pushButtonX = new QPushButton(clavierSaisie1);
        pushButtonX->setObjectName(QStringLiteral("pushButtonX"));
        pushButtonX->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonX, 3, 2, 1, 1);

        pushButtonS = new QPushButton(clavierSaisie1);
        pushButtonS->setObjectName(QStringLiteral("pushButtonS"));
        pushButtonS->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonS, 2, 4, 1, 1);

        pushButtonD = new QPushButton(clavierSaisie1);
        pushButtonD->setObjectName(QStringLiteral("pushButtonD"));
        pushButtonD->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonD, 0, 3, 1, 1);

        pushButtonH = new QPushButton(clavierSaisie1);
        pushButtonH->setObjectName(QStringLiteral("pushButtonH"));
        pushButtonH->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonH, 1, 0, 1, 1);

        pushButtonN = new QPushButton(clavierSaisie1);
        pushButtonN->setObjectName(QStringLiteral("pushButtonN"));
        pushButtonN->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonN, 1, 6, 1, 1);

        pushButtonZ = new QPushButton(clavierSaisie1);
        pushButtonZ->setObjectName(QStringLiteral("pushButtonZ"));
        pushButtonZ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonZ, 3, 4, 1, 1);

        pushButtonV = new QPushButton(clavierSaisie1);
        pushButtonV->setObjectName(QStringLiteral("pushButtonV"));
        pushButtonV->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonV, 3, 0, 1, 1);

        pushButtonI = new QPushButton(clavierSaisie1);
        pushButtonI->setObjectName(QStringLiteral("pushButtonI"));
        pushButtonI->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonI, 1, 1, 1, 1);

        pushButtonK = new QPushButton(clavierSaisie1);
        pushButtonK->setObjectName(QStringLiteral("pushButtonK"));
        pushButtonK->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonK, 1, 3, 1, 1);

        pushButtonP = new QPushButton(clavierSaisie1);
        pushButtonP->setObjectName(QStringLiteral("pushButtonP"));
        pushButtonP->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonP, 2, 1, 1, 1);

        pushButtonB = new QPushButton(clavierSaisie1);
        pushButtonB->setObjectName(QStringLiteral("pushButtonB"));
        pushButtonB->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonB, 0, 1, 1, 1);

        pushButtonF = new QPushButton(clavierSaisie1);
        pushButtonF->setObjectName(QStringLiteral("pushButtonF"));
        pushButtonF->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonF, 0, 5, 1, 1);

        pushButtonW = new QPushButton(clavierSaisie1);
        pushButtonW->setObjectName(QStringLiteral("pushButtonW"));
        pushButtonW->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonW, 3, 1, 1, 1);

        pushButtonL = new QPushButton(clavierSaisie1);
        pushButtonL->setObjectName(QStringLiteral("pushButtonL"));
        pushButtonL->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonL, 1, 4, 1, 1);

        pushButtonC = new QPushButton(clavierSaisie1);
        pushButtonC->setObjectName(QStringLiteral("pushButtonC"));
        pushButtonC->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonC, 0, 2, 1, 1);

        pushButtonA = new QPushButton(clavierSaisie1);
        pushButtonA->setObjectName(QStringLiteral("pushButtonA"));
        pushButtonA->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonA, 0, 0, 1, 1);

        pushButtonU = new QPushButton(clavierSaisie1);
        pushButtonU->setObjectName(QStringLiteral("pushButtonU"));

        clavierLettres->addWidget(pushButtonU, 2, 6, 1, 1);

        pushButtonT = new QPushButton(clavierSaisie1);
        pushButtonT->setObjectName(QStringLiteral("pushButtonT"));
        pushButtonT->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonT, 2, 5, 1, 1);

        pushButtonE = new QPushButton(clavierSaisie1);
        pushButtonE->setObjectName(QStringLiteral("pushButtonE"));
        pushButtonE->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonE, 0, 4, 1, 1);

        pushButtonM = new QPushButton(clavierSaisie1);
        pushButtonM->setObjectName(QStringLiteral("pushButtonM"));
        pushButtonM->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonM, 1, 5, 1, 1);

        pushButtonY = new QPushButton(clavierSaisie1);
        pushButtonY->setObjectName(QStringLiteral("pushButtonY"));
        pushButtonY->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonY, 3, 3, 1, 1);

        pushButtonG = new QPushButton(clavierSaisie1);
        pushButtonG->setObjectName(QStringLiteral("pushButtonG"));
        pushButtonG->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonG, 0, 6, 1, 1);

        pushButtonSpace = new QPushButton(clavierSaisie1);
        pushButtonSpace->setObjectName(QStringLiteral("pushButtonSpace"));

        clavierLettres->addWidget(pushButtonSpace, 3, 6, 1, 1);


        clavierSaisie->addLayout(clavierLettres);

        layoutWidget = new QWidget(Calculatrice);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 270, 601, 136));
        layoutWidget->setMinimumSize(QSize(601, 0));
        operateurSpeciaux = new QHBoxLayout(layoutWidget);
        operateurSpeciaux->setSpacing(6);
        operateurSpeciaux->setContentsMargins(11, 11, 11, 11);
        operateurSpeciaux->setObjectName(QStringLiteral("operateurSpeciaux"));
        operateurSpeciaux->setContentsMargins(0, 0, 0, 0);
        boutonSpeciaux = new QGridLayout();
        boutonSpeciaux->setSpacing(6);
        boutonSpeciaux->setObjectName(QStringLiteral("boutonSpeciaux"));
        pushButtonSwap = new QPushButton(layoutWidget);
        pushButtonSwap->setObjectName(QStringLiteral("pushButtonSwap"));
        pushButtonSwap->setAutoRepeatDelay(300);
        pushButtonSwap->setAutoDefault(false);
        pushButtonSwap->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonSwap, 3, 0, 1, 1);

        pushButtonDen = new QPushButton(layoutWidget);
        pushButtonDen->setObjectName(QStringLiteral("pushButtonDen"));
        pushButtonDen->setAutoRepeatDelay(300);
        pushButtonDen->setAutoDefault(false);
        pushButtonDen->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDen, 0, 3, 1, 1);

        pushButtonLastArg = new QPushButton(layoutWidget);
        pushButtonLastArg->setObjectName(QStringLiteral("pushButtonLastArg"));
        pushButtonLastArg->setAutoRepeatDelay(300);
        pushButtonLastArg->setAutoDefault(false);
        pushButtonLastArg->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonLastArg, 3, 2, 1, 1);

        pushButtoNot = new QPushButton(layoutWidget);
        pushButtoNot->setObjectName(QStringLiteral("pushButtoNot"));
        pushButtoNot->setAutoRepeatDelay(300);
        pushButtoNot->setAutoDefault(false);
        pushButtoNot->setFlat(false);

        boutonSpeciaux->addWidget(pushButtoNot, 2, 1, 1, 1);

        pushButtonAnd = new QPushButton(layoutWidget);
        pushButtonAnd->setObjectName(QStringLiteral("pushButtonAnd"));
        pushButtonAnd->setAutoRepeatDelay(300);
        pushButtonAnd->setAutoDefault(false);
        pushButtonAnd->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonAnd, 1, 3, 1, 1);

        pushButtonNeg = new QPushButton(layoutWidget);
        pushButtonNeg->setObjectName(QStringLiteral("pushButtonNeg"));
        pushButtonNeg->setAutoRepeatDelay(300);
        pushButtonNeg->setAutoDefault(false);
        pushButtonNeg->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonNeg, 0, 1, 1, 1);

        pushButtonNum = new QPushButton(layoutWidget);
        pushButtonNum->setObjectName(QStringLiteral("pushButtonNum"));
        pushButtonNum->setAutoRepeatDelay(300);
        pushButtonNum->setAutoDefault(false);
        pushButtonNum->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonNum, 0, 2, 1, 1);

        pushButtonDup = new QPushButton(layoutWidget);
        pushButtonDup->setObjectName(QStringLiteral("pushButtonDup"));
        pushButtonDup->setAutoRepeatDelay(300);
        pushButtonDup->setAutoDefault(false);
        pushButtonDup->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDup, 2, 2, 1, 1);

        pushButtonDrop = new QPushButton(layoutWidget);
        pushButtonDrop->setObjectName(QStringLiteral("pushButtonDrop"));
        pushButtonDrop->setAutoRepeatDelay(300);
        pushButtonDrop->setAutoDefault(false);
        pushButtonDrop->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDrop, 2, 3, 1, 1);

        pushButtonIm = new QPushButton(layoutWidget);
        pushButtonIm->setObjectName(QStringLiteral("pushButtonIm"));
        pushButtonIm->setAutoRepeatDelay(300);
        pushButtonIm->setAutoDefault(false);
        pushButtonIm->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonIm, 1, 2, 1, 1);

        pushButtonLastop = new QPushButton(layoutWidget);
        pushButtonLastop->setObjectName(QStringLiteral("pushButtonLastop"));
        pushButtonLastop->setAutoRepeatDelay(300);
        pushButtonLastop->setAutoDefault(false);
        pushButtonLastop->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonLastop, 3, 1, 1, 1);

        pushButtonIft = new QPushButton(layoutWidget);
        pushButtonIft->setObjectName(QStringLiteral("pushButtonIft"));
        pushButtonIft->setAutoRepeatDelay(300);
        pushButtonIft->setAutoDefault(false);
        pushButtonIft->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonIft, 3, 3, 1, 1);

        pushButtonDollar = new QPushButton(layoutWidget);
        pushButtonDollar->setObjectName(QStringLiteral("pushButtonDollar"));
        pushButtonDollar->setAutoRepeatDelay(300);
        pushButtonDollar->setAutoDefault(false);
        pushButtonDollar->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDollar, 1, 0, 1, 1);

        pushButtonRe = new QPushButton(layoutWidget);
        pushButtonRe->setObjectName(QStringLiteral("pushButtonRe"));
        pushButtonRe->setAutoRepeatDelay(300);
        pushButtonRe->setAutoDefault(false);
        pushButtonRe->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonRe, 1, 1, 1, 1);

        pushButtonOr = new QPushButton(layoutWidget);
        pushButtonOr->setObjectName(QStringLiteral("pushButtonOr"));
        pushButtonOr->setAutoRepeatDelay(300);
        pushButtonOr->setAutoDefault(false);
        pushButtonOr->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonOr, 2, 0, 1, 1);

        pushButtonDiv = new QPushButton(layoutWidget);
        pushButtonDiv->setObjectName(QStringLiteral("pushButtonDiv"));
        pushButtonDiv->setAutoRepeatDelay(300);
        pushButtonDiv->setAutoDefault(false);
        pushButtonDiv->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDiv, 0, 0, 1, 1);


        operateurSpeciaux->addLayout(boutonSpeciaux);

        EvEdStFo = new QVBoxLayout();
        EvEdStFo->setSpacing(6);
        EvEdStFo->setObjectName(QStringLiteral("EvEdStFo"));
        pushButtonEval = new QPushButton(layoutWidget);
        pushButtonEval->setObjectName(QStringLiteral("pushButtonEval"));

        EvEdStFo->addWidget(pushButtonEval);

        pushButtonEdit = new QPushButton(layoutWidget);
        pushButtonEdit->setObjectName(QStringLiteral("pushButtonEdit"));

        EvEdStFo->addWidget(pushButtonEdit);

        pushButtonSto = new QPushButton(layoutWidget);
        pushButtonSto->setObjectName(QStringLiteral("pushButtonSto"));

        EvEdStFo->addWidget(pushButtonSto);

        pushButtonForget = new QPushButton(layoutWidget);
        pushButtonForget->setObjectName(QStringLiteral("pushButtonForget"));

        EvEdStFo->addWidget(pushButtonForget);


        operateurSpeciaux->addLayout(EvEdStFo);

        EntCleUndRed = new QVBoxLayout();
        EntCleUndRed->setSpacing(6);
        EntCleUndRed->setObjectName(QStringLiteral("EntCleUndRed"));
        pushButtonEnter = new QPushButton(layoutWidget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));

        EntCleUndRed->addWidget(pushButtonEnter);

        pushButtonClear = new QPushButton(layoutWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));

        EntCleUndRed->addWidget(pushButtonClear);

        pushButtonUndo = new QPushButton(layoutWidget);
        pushButtonUndo->setObjectName(QStringLiteral("pushButtonUndo"));

        EntCleUndRed->addWidget(pushButtonUndo);

        pushButtonRedo = new QPushButton(layoutWidget);
        pushButtonRedo->setObjectName(QStringLiteral("pushButtonRedo"));

        EntCleUndRed->addWidget(pushButtonRedo);


        operateurSpeciaux->addLayout(EntCleUndRed);

        vuePile = new QTableWidget(Calculatrice);
        vuePile->setObjectName(QStringLiteral("vuePile"));
        vuePile->setGeometry(QRect(39, 70, 601, 141));
        vuePile->horizontalHeader()->setVisible(false);
        vuePile->horizontalHeader()->setStretchLastSection(true);
        message = new QLineEdit(Calculatrice);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(40, 10, 601, 21));
        message->setMinimumSize(QSize(601, 0));
        tabWidget->addTab(Calculatrice, QString());
        Options = new QWidget();
        Options->setObjectName(QStringLiteral("Options"));
        layoutWidget_3 = new QWidget(Options);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 20, 211, 301));
        formulaireParam = new QVBoxLayout(layoutWidget_3);
        formulaireParam->setSpacing(6);
        formulaireParam->setContentsMargins(11, 11, 11, 11);
        formulaireParam->setObjectName(QStringLiteral("formulaireParam"));
        formulaireParam->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(layoutWidget_3);
        label1->setObjectName(QStringLiteral("label1"));

        formulaireParam->addWidget(label1);

        checkBoxPar = new QVBoxLayout();
        checkBoxPar->setSpacing(6);
        checkBoxPar->setObjectName(QStringLiteral("checkBoxPar"));
        checkClavier = new QCheckBox(layoutWidget_3);
        checkClavier->setObjectName(QStringLiteral("checkClavier"));

        checkBoxPar->addWidget(checkClavier);

        checkSond = new QCheckBox(layoutWidget_3);
        checkSond->setObjectName(QStringLiteral("checkSond"));
        checkSond->setMinimumSize(QSize(200, 0));

        checkBoxPar->addWidget(checkSond);


        formulaireParam->addLayout(checkBoxPar);

        lcdNumber = new QLCDNumber(layoutWidget_3);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setProperty("intValue", QVariant(4));

        formulaireParam->addWidget(lcdNumber);

        taillePile = new QHBoxLayout();
        taillePile->setSpacing(6);
        taillePile->setObjectName(QStringLiteral("taillePile"));
        label2 = new QLabel(layoutWidget_3);
        label2->setObjectName(QStringLiteral("label2"));

        taillePile->addWidget(label2);

        verticalSlider = new QSlider(layoutWidget_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(9);
        verticalSlider->setSliderPosition(4);
        verticalSlider->setOrientation(Qt::Vertical);

        taillePile->addWidget(verticalSlider);


        formulaireParam->addLayout(taillePile);

        tabWidget->addTab(Options, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        tabWidget->setCurrentIndex(1);
        pushButtonSwap->setDefault(false);
        pushButtonDen->setDefault(false);
        pushButtonLastArg->setDefault(false);
        pushButtoNot->setDefault(false);
        pushButtonAnd->setDefault(false);
        pushButtonNeg->setDefault(false);
        pushButtonNum->setDefault(false);
        pushButtonDup->setDefault(false);
        pushButtonDrop->setDefault(false);
        pushButtonIm->setDefault(false);
        pushButtonLastop->setDefault(false);
        pushButtonIft->setDefault(false);
        pushButtonDollar->setDefault(false);
        pushButtonRe->setDefault(false);
        pushButtonOr->setDefault(false);
        pushButtonDiv->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushBoutonDel->setText(QApplication::translate("MainWindow", "<--", 0));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0));
        pushButtonPlus->setText(QApplication::translate("MainWindow", "+", 0));
        pushButtonMoins->setText(QApplication::translate("MainWindow", "-", 0));
        pushButtonMul->setText(QApplication::translate("MainWindow", "*", 0));
        pushButtonDiv1->setText(QApplication::translate("MainWindow", "/", 0));
        pushButtonQ->setText(QApplication::translate("MainWindow", "Q", 0));
        pushButtonR->setText(QApplication::translate("MainWindow", "R", 0));
        pushButtonJ->setText(QApplication::translate("MainWindow", "J", 0));
        pushButtonO->setText(QApplication::translate("MainWindow", "O", 0));
        pushButtonX->setText(QApplication::translate("MainWindow", "X", 0));
        pushButtonS->setText(QApplication::translate("MainWindow", "S", 0));
        pushButtonD->setText(QApplication::translate("MainWindow", "D", 0));
        pushButtonH->setText(QApplication::translate("MainWindow", "H", 0));
        pushButtonN->setText(QApplication::translate("MainWindow", "N", 0));
        pushButtonZ->setText(QApplication::translate("MainWindow", "Z", 0));
        pushButtonV->setText(QApplication::translate("MainWindow", "V", 0));
        pushButtonI->setText(QApplication::translate("MainWindow", "I", 0));
        pushButtonK->setText(QApplication::translate("MainWindow", "K", 0));
        pushButtonP->setText(QApplication::translate("MainWindow", "P", 0));
        pushButtonB->setText(QApplication::translate("MainWindow", "B", 0));
        pushButtonF->setText(QApplication::translate("MainWindow", "F", 0));
        pushButtonW->setText(QApplication::translate("MainWindow", "W", 0));
        pushButtonL->setText(QApplication::translate("MainWindow", "L", 0));
        pushButtonC->setText(QApplication::translate("MainWindow", "C", 0));
        pushButtonA->setText(QApplication::translate("MainWindow", "A", 0));
        pushButtonU->setText(QApplication::translate("MainWindow", "U", 0));
        pushButtonT->setText(QApplication::translate("MainWindow", "T", 0));
        pushButtonE->setText(QApplication::translate("MainWindow", "E", 0));
        pushButtonM->setText(QApplication::translate("MainWindow", "M", 0));
        pushButtonY->setText(QApplication::translate("MainWindow", "Y", 0));
        pushButtonG->setText(QApplication::translate("MainWindow", "G", 0));
        pushButtonSpace->setText(QApplication::translate("MainWindow", "_", 0));
        pushButtonSwap->setText(QApplication::translate("MainWindow", "SWAP", 0));
        pushButtonDen->setText(QApplication::translate("MainWindow", "DEN", 0));
        pushButtonLastArg->setText(QApplication::translate("MainWindow", "LASTARG", 0));
        pushButtoNot->setText(QApplication::translate("MainWindow", "NOT", 0));
        pushButtonAnd->setText(QApplication::translate("MainWindow", "AND", 0));
        pushButtonNeg->setText(QApplication::translate("MainWindow", "NEG", 0));
        pushButtonNum->setText(QApplication::translate("MainWindow", "NUM", 0));
        pushButtonDup->setText(QApplication::translate("MainWindow", "DUP", 0));
        pushButtonDrop->setText(QApplication::translate("MainWindow", "DROP", 0));
        pushButtonIm->setText(QApplication::translate("MainWindow", "IM", 0));
        pushButtonLastop->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        pushButtonIft->setText(QApplication::translate("MainWindow", "IFT", 0));
        pushButtonDollar->setText(QApplication::translate("MainWindow", "$", 0));
        pushButtonRe->setText(QApplication::translate("MainWindow", "RE", 0));
        pushButtonOr->setText(QApplication::translate("MainWindow", "OR", 0));
        pushButtonDiv->setText(QApplication::translate("MainWindow", "DIV", 0));
        pushButtonEval->setText(QApplication::translate("MainWindow", "EVAL", 0));
        pushButtonEdit->setText(QApplication::translate("MainWindow", "EDIT", 0));
        pushButtonSto->setText(QApplication::translate("MainWindow", "STO", 0));
        pushButtonForget->setText(QApplication::translate("MainWindow", "FORGET", 0));
        pushButtonEnter->setText(QApplication::translate("MainWindow", "ENTER", 0));
        pushButtonClear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButtonUndo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        pushButtonRedo->setText(QApplication::translate("MainWindow", "REDO", 0));
        tabWidget->setTabText(tabWidget->indexOf(Calculatrice), QApplication::translate("MainWindow", "Calculatrice", 0));
        label1->setText(QApplication::translate("MainWindow", "Modification des param\303\250tres", 0));
        checkClavier->setText(QApplication::translate("MainWindow", "Clavier", 0));
        checkSond->setText(QApplication::translate("MainWindow", "Sonds", 0));
        label2->setText(QApplication::translate("MainWindow", "Taille de la pile :", 0));
        tabWidget->setTabText(tabWidget->indexOf(Options), QApplication::translate("MainWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
