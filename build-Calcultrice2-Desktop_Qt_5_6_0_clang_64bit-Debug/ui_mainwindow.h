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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *Application;
    QWidget *calc;
    QWidget *layoutWidget;
    QVBoxLayout *vue1Calc;
    QLabel *AffichagePile;
    QVBoxLayout *vue2Calc;
    QFormLayout *etatPile;
    QLabel *label5;
    QLabel *labelPile5;
    QLabel *label4;
    QLabel *labelPile4;
    QLabel *label3;
    QLabel *label2;
    QLabel *labelPile2;
    QLabel *label1;
    QLabel *labelPile1;
    QLabel *labelPile3;
    QVBoxLayout *vue3Calc;
    QHBoxLayout *saisieClavier;
    QLineEdit *lineEdit;
    QPushButton *pushBoutonDel;
    QWidget *vue4CalcClavier;
    QVBoxLayout *vue4Calc;
    QHBoxLayout *vue5Calc;
    QVBoxLayout *clavierNumerique09;
    QHBoxLayout *clavierNumerique19;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton1;
    QPushButton *pushButton4;
    QPushButton *pushButton7;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton2;
    QPushButton *pushButton5;
    QPushButton *pushButton8;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushButton3;
    QPushButton *pushButton6;
    QPushButton *pushButton9;
    QPushButton *pushButton0;
    QVBoxLayout *clavierOp;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonMoins;
    QPushButton *pushButtonMul;
    QPushButton *pushButtonDiv1;
    QHBoxLayout *clavierUndoRedoEnter;
    QHBoxLayout *clavierUndoRedo;
    QVBoxLayout *clavierUndo;
    QPushButton *pushButtonEval;
    QPushButton *pushButtonSto;
    QPushButton *pushButtonUndo;
    QVBoxLayout *clavierRedo;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonForget;
    QPushButton *pushButtonRedo;
    QPushButton *pushButtonEnter;
    QHBoxLayout *vue6Calc;
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
    QPushButton *pushButtonClear;
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
    QWidget *param;
    QWidget *layoutWidget1;
    QVBoxLayout *vue1Param;
    QVBoxLayout *parametre;
    QLabel *labelParam;
    QCheckBox *checkBoxClavier;
    QCheckBox *checkBoxBip;
    QHBoxLayout *vue2Param;
    QVBoxLayout *variables;
    QLabel *labelVar;
    QTextEdit *textEditVar;
    QVBoxLayout *programmes;
    QLabel *labelProg;
    QTextEdit *textEditProg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 720);
        MainWindow->setMinimumSize(QSize(600, 720));
        MainWindow->setMaximumSize(QSize(600, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(593, 581));
        Application = new QTabWidget(centralWidget);
        Application->setObjectName(QStringLiteral("Application"));
        Application->setGeometry(QRect(10, 10, 571, 690));
        Application->setTabShape(QTabWidget::Rounded);
        Application->setUsesScrollButtons(false);
        calc = new QWidget();
        calc->setObjectName(QStringLiteral("calc"));
        layoutWidget = new QWidget(calc);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 570, 678));
        vue1Calc = new QVBoxLayout(layoutWidget);
        vue1Calc->setSpacing(6);
        vue1Calc->setContentsMargins(11, 11, 11, 11);
        vue1Calc->setObjectName(QStringLiteral("vue1Calc"));
        vue1Calc->setContentsMargins(0, 0, 0, 0);
        AffichagePile = new QLabel(layoutWidget);
        AffichagePile->setObjectName(QStringLiteral("AffichagePile"));
        AffichagePile->setMinimumSize(QSize(546, 0));

        vue1Calc->addWidget(AffichagePile);

        vue2Calc = new QVBoxLayout();
        vue2Calc->setSpacing(6);
        vue2Calc->setObjectName(QStringLiteral("vue2Calc"));
        etatPile = new QFormLayout();
        etatPile->setSpacing(6);
        etatPile->setObjectName(QStringLiteral("etatPile"));
        label5 = new QLabel(layoutWidget);
        label5->setObjectName(QStringLiteral("label5"));

        etatPile->setWidget(0, QFormLayout::LabelRole, label5);

        labelPile5 = new QLabel(layoutWidget);
        labelPile5->setObjectName(QStringLiteral("labelPile5"));
        labelPile5->setMinimumSize(QSize(525, 0));

        etatPile->setWidget(0, QFormLayout::FieldRole, labelPile5);

        label4 = new QLabel(layoutWidget);
        label4->setObjectName(QStringLiteral("label4"));

        etatPile->setWidget(1, QFormLayout::LabelRole, label4);

        labelPile4 = new QLabel(layoutWidget);
        labelPile4->setObjectName(QStringLiteral("labelPile4"));
        labelPile4->setMinimumSize(QSize(525, 0));

        etatPile->setWidget(1, QFormLayout::FieldRole, labelPile4);

        label3 = new QLabel(layoutWidget);
        label3->setObjectName(QStringLiteral("label3"));

        etatPile->setWidget(2, QFormLayout::LabelRole, label3);

        label2 = new QLabel(layoutWidget);
        label2->setObjectName(QStringLiteral("label2"));

        etatPile->setWidget(3, QFormLayout::LabelRole, label2);

        labelPile2 = new QLabel(layoutWidget);
        labelPile2->setObjectName(QStringLiteral("labelPile2"));
        labelPile2->setMinimumSize(QSize(525, 0));

        etatPile->setWidget(3, QFormLayout::FieldRole, labelPile2);

        label1 = new QLabel(layoutWidget);
        label1->setObjectName(QStringLiteral("label1"));

        etatPile->setWidget(4, QFormLayout::LabelRole, label1);

        labelPile1 = new QLabel(layoutWidget);
        labelPile1->setObjectName(QStringLiteral("labelPile1"));
        labelPile1->setMinimumSize(QSize(525, 0));

        etatPile->setWidget(4, QFormLayout::FieldRole, labelPile1);

        labelPile3 = new QLabel(layoutWidget);
        labelPile3->setObjectName(QStringLiteral("labelPile3"));
        labelPile3->setMinimumSize(QSize(525, 0));

        etatPile->setWidget(2, QFormLayout::FieldRole, labelPile3);


        vue2Calc->addLayout(etatPile);

        vue3Calc = new QVBoxLayout();
        vue3Calc->setSpacing(6);
        vue3Calc->setObjectName(QStringLiteral("vue3Calc"));
        saisieClavier = new QHBoxLayout();
        saisieClavier->setSpacing(6);
        saisieClavier->setObjectName(QStringLiteral("saisieClavier"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        saisieClavier->addWidget(lineEdit);

        pushBoutonDel = new QPushButton(layoutWidget);
        pushBoutonDel->setObjectName(QStringLiteral("pushBoutonDel"));

        saisieClavier->addWidget(pushBoutonDel);


        vue3Calc->addLayout(saisieClavier);

        vue4CalcClavier = new QWidget(layoutWidget);
        vue4CalcClavier->setObjectName(QStringLiteral("vue4CalcClavier"));
        vue4Calc = new QVBoxLayout(vue4CalcClavier);
        vue4Calc->setSpacing(6);
        vue4Calc->setContentsMargins(11, 11, 11, 11);
        vue4Calc->setObjectName(QStringLiteral("vue4Calc"));
        vue5Calc = new QHBoxLayout();
        vue5Calc->setSpacing(6);
        vue5Calc->setObjectName(QStringLiteral("vue5Calc"));
        clavierNumerique09 = new QVBoxLayout();
        clavierNumerique09->setSpacing(6);
        clavierNumerique09->setObjectName(QStringLiteral("clavierNumerique09"));
        clavierNumerique19 = new QHBoxLayout();
        clavierNumerique19->setSpacing(6);
        clavierNumerique19->setObjectName(QStringLiteral("clavierNumerique19"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButton1 = new QPushButton(vue4CalcClavier);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));

        verticalLayout_6->addWidget(pushButton1);

        pushButton4 = new QPushButton(vue4CalcClavier);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));

        verticalLayout_6->addWidget(pushButton4);

        pushButton7 = new QPushButton(vue4CalcClavier);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));

        verticalLayout_6->addWidget(pushButton7);


        clavierNumerique19->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton2 = new QPushButton(vue4CalcClavier);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));

        verticalLayout_7->addWidget(pushButton2);

        pushButton5 = new QPushButton(vue4CalcClavier);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));

        verticalLayout_7->addWidget(pushButton5);

        pushButton8 = new QPushButton(vue4CalcClavier);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));

        verticalLayout_7->addWidget(pushButton8);


        clavierNumerique19->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        pushButton3 = new QPushButton(vue4CalcClavier);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));

        verticalLayout_8->addWidget(pushButton3);

        pushButton6 = new QPushButton(vue4CalcClavier);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));

        verticalLayout_8->addWidget(pushButton6);

        pushButton9 = new QPushButton(vue4CalcClavier);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));

        verticalLayout_8->addWidget(pushButton9);


        clavierNumerique19->addLayout(verticalLayout_8);


        clavierNumerique09->addLayout(clavierNumerique19);

        pushButton0 = new QPushButton(vue4CalcClavier);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));

        clavierNumerique09->addWidget(pushButton0);


        vue5Calc->addLayout(clavierNumerique09);

        clavierOp = new QVBoxLayout();
        clavierOp->setSpacing(6);
        clavierOp->setObjectName(QStringLiteral("clavierOp"));
        pushButtonPlus = new QPushButton(vue4CalcClavier);
        pushButtonPlus->setObjectName(QStringLiteral("pushButtonPlus"));

        clavierOp->addWidget(pushButtonPlus);

        pushButtonMoins = new QPushButton(vue4CalcClavier);
        pushButtonMoins->setObjectName(QStringLiteral("pushButtonMoins"));

        clavierOp->addWidget(pushButtonMoins);

        pushButtonMul = new QPushButton(vue4CalcClavier);
        pushButtonMul->setObjectName(QStringLiteral("pushButtonMul"));

        clavierOp->addWidget(pushButtonMul);

        pushButtonDiv1 = new QPushButton(vue4CalcClavier);
        pushButtonDiv1->setObjectName(QStringLiteral("pushButtonDiv1"));

        clavierOp->addWidget(pushButtonDiv1);


        vue5Calc->addLayout(clavierOp);

        clavierUndoRedoEnter = new QHBoxLayout();
        clavierUndoRedoEnter->setSpacing(6);
        clavierUndoRedoEnter->setObjectName(QStringLiteral("clavierUndoRedoEnter"));
        clavierUndoRedo = new QHBoxLayout();
        clavierUndoRedo->setSpacing(6);
        clavierUndoRedo->setObjectName(QStringLiteral("clavierUndoRedo"));
        clavierUndo = new QVBoxLayout();
        clavierUndo->setSpacing(6);
        clavierUndo->setObjectName(QStringLiteral("clavierUndo"));
        pushButtonEval = new QPushButton(vue4CalcClavier);
        pushButtonEval->setObjectName(QStringLiteral("pushButtonEval"));

        clavierUndo->addWidget(pushButtonEval);

        pushButtonSto = new QPushButton(vue4CalcClavier);
        pushButtonSto->setObjectName(QStringLiteral("pushButtonSto"));

        clavierUndo->addWidget(pushButtonSto);

        pushButtonUndo = new QPushButton(vue4CalcClavier);
        pushButtonUndo->setObjectName(QStringLiteral("pushButtonUndo"));

        clavierUndo->addWidget(pushButtonUndo);


        clavierUndoRedo->addLayout(clavierUndo);

        clavierRedo = new QVBoxLayout();
        clavierRedo->setSpacing(6);
        clavierRedo->setObjectName(QStringLiteral("clavierRedo"));
        pushButtonEdit = new QPushButton(vue4CalcClavier);
        pushButtonEdit->setObjectName(QStringLiteral("pushButtonEdit"));

        clavierRedo->addWidget(pushButtonEdit);

        pushButtonForget = new QPushButton(vue4CalcClavier);
        pushButtonForget->setObjectName(QStringLiteral("pushButtonForget"));

        clavierRedo->addWidget(pushButtonForget);

        pushButtonRedo = new QPushButton(vue4CalcClavier);
        pushButtonRedo->setObjectName(QStringLiteral("pushButtonRedo"));

        clavierRedo->addWidget(pushButtonRedo);


        clavierUndoRedo->addLayout(clavierRedo);


        clavierUndoRedoEnter->addLayout(clavierUndoRedo);

        pushButtonEnter = new QPushButton(vue4CalcClavier);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));

        clavierUndoRedoEnter->addWidget(pushButtonEnter);


        vue5Calc->addLayout(clavierUndoRedoEnter);


        vue4Calc->addLayout(vue5Calc);

        vue6Calc = new QHBoxLayout();
        vue6Calc->setSpacing(6);
        vue6Calc->setObjectName(QStringLiteral("vue6Calc"));
        boutonSpeciaux = new QGridLayout();
        boutonSpeciaux->setSpacing(6);
        boutonSpeciaux->setObjectName(QStringLiteral("boutonSpeciaux"));
        pushButtonSwap = new QPushButton(vue4CalcClavier);
        pushButtonSwap->setObjectName(QStringLiteral("pushButtonSwap"));
        pushButtonSwap->setAutoRepeatDelay(300);
        pushButtonSwap->setAutoDefault(false);
        pushButtonSwap->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonSwap, 3, 0, 1, 1);

        pushButtonDen = new QPushButton(vue4CalcClavier);
        pushButtonDen->setObjectName(QStringLiteral("pushButtonDen"));
        pushButtonDen->setAutoRepeatDelay(300);
        pushButtonDen->setAutoDefault(false);
        pushButtonDen->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDen, 0, 3, 1, 1);

        pushButtonLastArg = new QPushButton(vue4CalcClavier);
        pushButtonLastArg->setObjectName(QStringLiteral("pushButtonLastArg"));
        pushButtonLastArg->setAutoRepeatDelay(300);
        pushButtonLastArg->setAutoDefault(false);
        pushButtonLastArg->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonLastArg, 3, 2, 1, 1);

        pushButtoNot = new QPushButton(vue4CalcClavier);
        pushButtoNot->setObjectName(QStringLiteral("pushButtoNot"));
        pushButtoNot->setAutoRepeatDelay(300);
        pushButtoNot->setAutoDefault(false);
        pushButtoNot->setFlat(false);

        boutonSpeciaux->addWidget(pushButtoNot, 2, 1, 1, 1);

        pushButtonAnd = new QPushButton(vue4CalcClavier);
        pushButtonAnd->setObjectName(QStringLiteral("pushButtonAnd"));
        pushButtonAnd->setAutoRepeatDelay(300);
        pushButtonAnd->setAutoDefault(false);
        pushButtonAnd->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonAnd, 1, 3, 1, 1);

        pushButtonNeg = new QPushButton(vue4CalcClavier);
        pushButtonNeg->setObjectName(QStringLiteral("pushButtonNeg"));
        pushButtonNeg->setAutoRepeatDelay(300);
        pushButtonNeg->setAutoDefault(false);
        pushButtonNeg->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonNeg, 0, 1, 1, 1);

        pushButtonNum = new QPushButton(vue4CalcClavier);
        pushButtonNum->setObjectName(QStringLiteral("pushButtonNum"));
        pushButtonNum->setAutoRepeatDelay(300);
        pushButtonNum->setAutoDefault(false);
        pushButtonNum->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonNum, 0, 2, 1, 1);

        pushButtonDup = new QPushButton(vue4CalcClavier);
        pushButtonDup->setObjectName(QStringLiteral("pushButtonDup"));
        pushButtonDup->setAutoRepeatDelay(300);
        pushButtonDup->setAutoDefault(false);
        pushButtonDup->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDup, 2, 2, 1, 1);

        pushButtonDrop = new QPushButton(vue4CalcClavier);
        pushButtonDrop->setObjectName(QStringLiteral("pushButtonDrop"));
        pushButtonDrop->setAutoRepeatDelay(300);
        pushButtonDrop->setAutoDefault(false);
        pushButtonDrop->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDrop, 2, 3, 1, 1);

        pushButtonIm = new QPushButton(vue4CalcClavier);
        pushButtonIm->setObjectName(QStringLiteral("pushButtonIm"));
        pushButtonIm->setAutoRepeatDelay(300);
        pushButtonIm->setAutoDefault(false);
        pushButtonIm->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonIm, 1, 2, 1, 1);

        pushButtonLastop = new QPushButton(vue4CalcClavier);
        pushButtonLastop->setObjectName(QStringLiteral("pushButtonLastop"));
        pushButtonLastop->setAutoRepeatDelay(300);
        pushButtonLastop->setAutoDefault(false);
        pushButtonLastop->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonLastop, 3, 1, 1, 1);

        pushButtonIft = new QPushButton(vue4CalcClavier);
        pushButtonIft->setObjectName(QStringLiteral("pushButtonIft"));
        pushButtonIft->setAutoRepeatDelay(300);
        pushButtonIft->setAutoDefault(false);
        pushButtonIft->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonIft, 3, 3, 1, 1);

        pushButtonDollar = new QPushButton(vue4CalcClavier);
        pushButtonDollar->setObjectName(QStringLiteral("pushButtonDollar"));
        pushButtonDollar->setAutoRepeatDelay(300);
        pushButtonDollar->setAutoDefault(false);
        pushButtonDollar->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDollar, 1, 0, 1, 1);

        pushButtonRe = new QPushButton(vue4CalcClavier);
        pushButtonRe->setObjectName(QStringLiteral("pushButtonRe"));
        pushButtonRe->setAutoRepeatDelay(300);
        pushButtonRe->setAutoDefault(false);
        pushButtonRe->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonRe, 1, 1, 1, 1);

        pushButtonOr = new QPushButton(vue4CalcClavier);
        pushButtonOr->setObjectName(QStringLiteral("pushButtonOr"));
        pushButtonOr->setAutoRepeatDelay(300);
        pushButtonOr->setAutoDefault(false);
        pushButtonOr->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonOr, 2, 0, 1, 1);

        pushButtonDiv = new QPushButton(vue4CalcClavier);
        pushButtonDiv->setObjectName(QStringLiteral("pushButtonDiv"));
        pushButtonDiv->setAutoRepeatDelay(300);
        pushButtonDiv->setAutoDefault(false);
        pushButtonDiv->setFlat(false);

        boutonSpeciaux->addWidget(pushButtonDiv, 0, 0, 1, 1);


        vue6Calc->addLayout(boutonSpeciaux);

        pushButtonClear = new QPushButton(vue4CalcClavier);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));

        vue6Calc->addWidget(pushButtonClear);


        vue4Calc->addLayout(vue6Calc);

        clavierLettres = new QGridLayout();
        clavierLettres->setSpacing(6);
        clavierLettres->setObjectName(QStringLiteral("clavierLettres"));
        pushButtonQ = new QPushButton(vue4CalcClavier);
        pushButtonQ->setObjectName(QStringLiteral("pushButtonQ"));
        pushButtonQ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonQ, 2, 2, 1, 1);

        pushButtonR = new QPushButton(vue4CalcClavier);
        pushButtonR->setObjectName(QStringLiteral("pushButtonR"));
        pushButtonR->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonR, 2, 3, 1, 1);

        pushButtonJ = new QPushButton(vue4CalcClavier);
        pushButtonJ->setObjectName(QStringLiteral("pushButtonJ"));
        pushButtonJ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonJ, 1, 2, 1, 1);

        pushButtonO = new QPushButton(vue4CalcClavier);
        pushButtonO->setObjectName(QStringLiteral("pushButtonO"));
        pushButtonO->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonO, 2, 0, 1, 1);

        pushButtonX = new QPushButton(vue4CalcClavier);
        pushButtonX->setObjectName(QStringLiteral("pushButtonX"));
        pushButtonX->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonX, 3, 2, 1, 1);

        pushButtonS = new QPushButton(vue4CalcClavier);
        pushButtonS->setObjectName(QStringLiteral("pushButtonS"));
        pushButtonS->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonS, 2, 4, 1, 1);

        pushButtonD = new QPushButton(vue4CalcClavier);
        pushButtonD->setObjectName(QStringLiteral("pushButtonD"));
        pushButtonD->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonD, 0, 3, 1, 1);

        pushButtonH = new QPushButton(vue4CalcClavier);
        pushButtonH->setObjectName(QStringLiteral("pushButtonH"));
        pushButtonH->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonH, 1, 0, 1, 1);

        pushButtonN = new QPushButton(vue4CalcClavier);
        pushButtonN->setObjectName(QStringLiteral("pushButtonN"));
        pushButtonN->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonN, 1, 6, 1, 1);

        pushButtonZ = new QPushButton(vue4CalcClavier);
        pushButtonZ->setObjectName(QStringLiteral("pushButtonZ"));
        pushButtonZ->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonZ, 3, 4, 1, 1);

        pushButtonV = new QPushButton(vue4CalcClavier);
        pushButtonV->setObjectName(QStringLiteral("pushButtonV"));
        pushButtonV->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonV, 3, 0, 1, 1);

        pushButtonI = new QPushButton(vue4CalcClavier);
        pushButtonI->setObjectName(QStringLiteral("pushButtonI"));
        pushButtonI->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonI, 1, 1, 1, 1);

        pushButtonK = new QPushButton(vue4CalcClavier);
        pushButtonK->setObjectName(QStringLiteral("pushButtonK"));
        pushButtonK->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonK, 1, 3, 1, 1);

        pushButtonP = new QPushButton(vue4CalcClavier);
        pushButtonP->setObjectName(QStringLiteral("pushButtonP"));
        pushButtonP->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonP, 2, 1, 1, 1);

        pushButtonB = new QPushButton(vue4CalcClavier);
        pushButtonB->setObjectName(QStringLiteral("pushButtonB"));
        pushButtonB->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonB, 0, 1, 1, 1);

        pushButtonF = new QPushButton(vue4CalcClavier);
        pushButtonF->setObjectName(QStringLiteral("pushButtonF"));
        pushButtonF->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonF, 0, 5, 1, 1);

        pushButtonW = new QPushButton(vue4CalcClavier);
        pushButtonW->setObjectName(QStringLiteral("pushButtonW"));
        pushButtonW->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonW, 3, 1, 1, 1);

        pushButtonL = new QPushButton(vue4CalcClavier);
        pushButtonL->setObjectName(QStringLiteral("pushButtonL"));
        pushButtonL->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonL, 1, 4, 1, 1);

        pushButtonC = new QPushButton(vue4CalcClavier);
        pushButtonC->setObjectName(QStringLiteral("pushButtonC"));
        pushButtonC->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonC, 0, 2, 1, 1);

        pushButtonA = new QPushButton(vue4CalcClavier);
        pushButtonA->setObjectName(QStringLiteral("pushButtonA"));
        pushButtonA->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonA, 0, 0, 1, 1);

        pushButtonU = new QPushButton(vue4CalcClavier);
        pushButtonU->setObjectName(QStringLiteral("pushButtonU"));

        clavierLettres->addWidget(pushButtonU, 2, 6, 1, 1);

        pushButtonT = new QPushButton(vue4CalcClavier);
        pushButtonT->setObjectName(QStringLiteral("pushButtonT"));
        pushButtonT->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonT, 2, 5, 1, 1);

        pushButtonE = new QPushButton(vue4CalcClavier);
        pushButtonE->setObjectName(QStringLiteral("pushButtonE"));
        pushButtonE->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonE, 0, 4, 1, 1);

        pushButtonM = new QPushButton(vue4CalcClavier);
        pushButtonM->setObjectName(QStringLiteral("pushButtonM"));
        pushButtonM->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonM, 1, 5, 1, 1);

        pushButtonY = new QPushButton(vue4CalcClavier);
        pushButtonY->setObjectName(QStringLiteral("pushButtonY"));
        pushButtonY->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonY, 3, 3, 1, 1);

        pushButtonG = new QPushButton(vue4CalcClavier);
        pushButtonG->setObjectName(QStringLiteral("pushButtonG"));
        pushButtonG->setMaximumSize(QSize(50, 16777215));

        clavierLettres->addWidget(pushButtonG, 0, 6, 1, 1);


        vue4Calc->addLayout(clavierLettres);


        vue3Calc->addWidget(vue4CalcClavier);


        vue2Calc->addLayout(vue3Calc);


        vue1Calc->addLayout(vue2Calc);

        Application->addTab(calc, QString());
        param = new QWidget();
        param->setObjectName(QStringLiteral("param"));
        layoutWidget1 = new QWidget(param);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 530, 511));
        vue1Param = new QVBoxLayout(layoutWidget1);
        vue1Param->setSpacing(6);
        vue1Param->setContentsMargins(11, 11, 11, 11);
        vue1Param->setObjectName(QStringLiteral("vue1Param"));
        vue1Param->setContentsMargins(0, 0, 0, 0);
        parametre = new QVBoxLayout();
        parametre->setSpacing(6);
        parametre->setObjectName(QStringLiteral("parametre"));
        labelParam = new QLabel(layoutWidget1);
        labelParam->setObjectName(QStringLiteral("labelParam"));

        parametre->addWidget(labelParam);

        checkBoxClavier = new QCheckBox(layoutWidget1);
        checkBoxClavier->setObjectName(QStringLiteral("checkBoxClavier"));

        parametre->addWidget(checkBoxClavier);

        checkBoxBip = new QCheckBox(layoutWidget1);
        checkBoxBip->setObjectName(QStringLiteral("checkBoxBip"));

        parametre->addWidget(checkBoxBip);


        vue1Param->addLayout(parametre);

        vue2Param = new QHBoxLayout();
        vue2Param->setSpacing(6);
        vue2Param->setObjectName(QStringLiteral("vue2Param"));
        variables = new QVBoxLayout();
        variables->setSpacing(6);
        variables->setObjectName(QStringLiteral("variables"));
        labelVar = new QLabel(layoutWidget1);
        labelVar->setObjectName(QStringLiteral("labelVar"));

        variables->addWidget(labelVar);

        textEditVar = new QTextEdit(layoutWidget1);
        textEditVar->setObjectName(QStringLiteral("textEditVar"));

        variables->addWidget(textEditVar);


        vue2Param->addLayout(variables);

        programmes = new QVBoxLayout();
        programmes->setSpacing(6);
        programmes->setObjectName(QStringLiteral("programmes"));
        labelProg = new QLabel(layoutWidget1);
        labelProg->setObjectName(QStringLiteral("labelProg"));

        programmes->addWidget(labelProg);

        textEditProg = new QTextEdit(layoutWidget1);
        textEditProg->setObjectName(QStringLiteral("textEditProg"));

        programmes->addWidget(textEditProg);


        vue2Param->addLayout(programmes);


        vue1Param->addLayout(vue2Param);

        Application->addTab(param, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        Application->setCurrentIndex(0);
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
        AffichagePile->setText(QApplication::translate("MainWindow", "Messages :", 0));
        label5->setText(QApplication::translate("MainWindow", "5:", 0));
        labelPile5->setText(QString());
        label4->setText(QApplication::translate("MainWindow", "4:", 0));
        labelPile4->setText(QString());
        label3->setText(QApplication::translate("MainWindow", "3:", 0));
        label2->setText(QApplication::translate("MainWindow", "2:", 0));
        labelPile2->setText(QString());
        label1->setText(QApplication::translate("MainWindow", "1:", 0));
        labelPile1->setText(QString());
        labelPile3->setText(QString());
        pushBoutonDel->setText(QApplication::translate("MainWindow", "<--", 0));
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0));
        pushButtonPlus->setText(QApplication::translate("MainWindow", "+", 0));
        pushButtonMoins->setText(QApplication::translate("MainWindow", "-", 0));
        pushButtonMul->setText(QApplication::translate("MainWindow", "*", 0));
        pushButtonDiv1->setText(QApplication::translate("MainWindow", "/", 0));
        pushButtonEval->setText(QApplication::translate("MainWindow", "EVAL", 0));
        pushButtonSto->setText(QApplication::translate("MainWindow", "STO", 0));
        pushButtonUndo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        pushButtonEdit->setText(QApplication::translate("MainWindow", "EDIT", 0));
        pushButtonForget->setText(QApplication::translate("MainWindow", "FORGET", 0));
        pushButtonRedo->setText(QApplication::translate("MainWindow", "REDO", 0));
        pushButtonEnter->setText(QApplication::translate("MainWindow", "ENTER", 0));
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
        pushButtonClear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
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
        Application->setTabText(Application->indexOf(calc), QApplication::translate("MainWindow", "Calc", 0));
        labelParam->setText(QApplication::translate("MainWindow", "Param\303\250tres :", 0));
        checkBoxClavier->setText(QApplication::translate("MainWindow", "Clavier Cliquable", 0));
        checkBoxBip->setText(QApplication::translate("MainWindow", "Bip Sonore", 0));
        labelVar->setText(QApplication::translate("MainWindow", "Variables :", 0));
        labelProg->setText(QApplication::translate("MainWindow", "Programmes :", 0));
        Application->setTabText(Application->indexOf(param), QApplication::translate("MainWindow", "Param", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
