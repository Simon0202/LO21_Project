#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pile.h"
#include "litteraleabstraite.h"
#include <QDebug>
#include <QVector>
#include <qiterator.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Pile* pile = Pile::getInstance();
    pile->setMaxAffiche(ui->verticalSlider->value());

    ui->vuePile->setRowCount(pile->getMaxAffiche());
    ui->vuePile->setColumnCount(1);
    ui->vuePile->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    QStringList numberList;

    for(unsigned int i = pile->getMaxAffiche(); i>0; i--) {
        QString str = QString::number(i);
        str += " :";
        numberList << str;
        // creation of the item of each line initialized with an empty string (chaine vide).
        ui->vuePile->setItem(i-1, 0, new QTableWidgetItem(""));
    }
    ui->vuePile->setVerticalHeaderLabels(numberList);
    ui->vuePile->setFixedHeight(pile->getMaxAffiche() * ui->vuePile->rowHeight(0)+2);

    // inhibit modification
    ui->vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // connection
    connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));


    // first message
    ui->message->setText("Bienvenue !");

    ui->lineEdit->setFocus(Qt::OtherFocusReason);

    ui->checkClavier->setChecked(true);
    ui->checkSond->setChecked(true);
    connect(ui->checkSond, SIGNAL(toggled(bool)), this, SLOT(activerBipOpt(bool)));


    refresh();
}


void MainWindow::refresh(){
    Pile* pile = Pile::getInstance();

    // the message
    ui->message->setText(pile->getMessage());

    // delete everything
    for(unsigned int i=0; i<pile->getMaxAffiche(); i++)
        ui->vuePile->item(i,0)->setText("");

    // update
    unsigned int nb = 0;
    QStack<LitteraleAbstraite*>::const_iterator it;

    for(it = pile->getIteratorEnd() - 1 ; it != pile->getIteratorBegin() - 1 && nb < pile->getMaxAffiche(); nb++, --it) {
        ui->vuePile->item(pile->getMaxAffiche() - nb - 1, 0)->setText((*it)->toString());
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    Pile* pile = Pile::getInstance();
    Controleur* controleur = Controleur::getInstance();

    //Efface le message d'erreur
    pile->setMessage("");


    QString c = ui->lineEdit->text();

    try {
        controleur->parse(c);
    } catch(ComputerException c) {
        pile->setMessage(c.getInfo());

    }

    ui->lineEdit->clear();
    emit pile->modificationEtat();
}



void MainWindow::setMaxAffiche(int n) {
    Pile* pile = Pile::getInstance();
    pile->setMaxAffiche(n);
    ui->vuePile->setRowCount(n);
    QStringList numberList;

    for(unsigned int i = n; i>0; i--) {
        QString str = QString::number(i);
        str += " :";
        numberList << str;
        // creation of the item of each line initialized with an empty string (chaine vide).
        ui->vuePile->setItem(i-1, 0, new QTableWidgetItem(""));
    }

    ui->vuePile->setVerticalHeaderLabels(numberList);
    ui->vuePile->setFixedHeight(n * ui->vuePile->rowHeight(0)+2);
    emit pile->modificationEtat();

}


MainWindow::~MainWindow()
{
    delete ui;
}



//*********
//Clavier09
//*********
void MainWindow::on_pushButton0_released(){ui->lineEdit->insert("0");}
void MainWindow::on_pushButton1_released(){ui->lineEdit->insert("1");}
void MainWindow::on_pushButton2_released(){ui->lineEdit->insert("2");}
void MainWindow::on_pushButton3_released(){ui->lineEdit->insert("3");}
void MainWindow::on_pushButton4_released(){ui->lineEdit->insert("4");}
void MainWindow::on_pushButton5_released(){ui->lineEdit->insert("5");}
void MainWindow::on_pushButton6_released(){ui->lineEdit->insert("6");}
void MainWindow::on_pushButton7_released(){ui->lineEdit->insert("7");}
void MainWindow::on_pushButton8_released(){ui->lineEdit->insert("8");}
void MainWindow::on_pushButton9_released(){ui->lineEdit->insert("9");}


void MainWindow::on_pushButtonA_released(){ui->lineEdit->insert("A");}
void MainWindow::on_pushButtonB_released(){ui->lineEdit->insert("B");}
void MainWindow::on_pushButtonC_released(){ui->lineEdit->insert("C");}
void MainWindow::on_pushButtonD_released(){ui->lineEdit->insert("D");}
void MainWindow::on_pushButtonE_released(){ui->lineEdit->insert("E");}
void MainWindow::on_pushButtonF_released(){ui->lineEdit->insert("F");}
void MainWindow::on_pushButtonG_released(){ui->lineEdit->insert("G");}
void MainWindow::on_pushButtonH_released(){ui->lineEdit->insert("H");}
void MainWindow::on_pushButtonI_released(){ui->lineEdit->insert("I");}
void MainWindow::on_pushButtonJ_released(){ui->lineEdit->insert("J");}
void MainWindow::on_pushButtonK_released(){ui->lineEdit->insert("K");}
void MainWindow::on_pushButtonL_released(){ui->lineEdit->insert("L");}
void MainWindow::on_pushButtonM_released(){ui->lineEdit->insert("M");}
void MainWindow::on_pushButtonN_released(){ui->lineEdit->insert("N");}
void MainWindow::on_pushButtonO_released(){ui->lineEdit->insert("O");}
void MainWindow::on_pushButtonP_released(){ui->lineEdit->insert("P");}
void MainWindow::on_pushButtonQ_released(){ui->lineEdit->insert("Q");}
void MainWindow::on_pushButtonR_released(){ui->lineEdit->insert("R");}
void MainWindow::on_pushButtonS_released(){ui->lineEdit->insert("S");}
void MainWindow::on_pushButtonT_released(){ui->lineEdit->insert("T");}
void MainWindow::on_pushButtonU_released(){ui->lineEdit->insert("U");}
void MainWindow::on_pushButtonV_released(){ui->lineEdit->insert("V");}
void MainWindow::on_pushButtonW_released(){ui->lineEdit->insert("W");}
void MainWindow::on_pushButtonX_released(){ui->lineEdit->insert("X");}
void MainWindow::on_pushButtonY_released(){ui->lineEdit->insert("Y");}
void MainWindow::on_pushButtonZ_released(){ui->lineEdit->insert("Z");}


//********
//LineEdit
//********
void MainWindow::on_pushBoutonDel_clicked()
{
    ui->lineEdit->backspace();
}



//**********
//ClavierOpe
//**********
void MainWindow::on_pushButtonDiv1_released(){ui->lineEdit->insert("/");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonMul_released(){ui->lineEdit->insert("*");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonMoins_released(){ui->lineEdit->insert("-");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonPlus_released(){ui->lineEdit->insert("+");ui->lineEdit->returnPressed();}


//******************************
//Clear && Enter && Undo && Redo
//******************************

void MainWindow::on_pushButtonClear_released(){ui->lineEdit->insert("CLEAR");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonUndo_released(){ui->lineEdit->insert("UNDO");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonRedo_released(){ui->lineEdit->insert("REDO");ui->lineEdit->returnPressed();}


//****************
//Boutton Speciaux
//****************
void MainWindow::on_pushButtonDollar_released(){ui->lineEdit->insert("$");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonDiv_released(){ui->lineEdit->insert("DIV");ui->lineEdit->returnPressed();}
void MainWindow::on_pushButtonNeg_released(){ui->lineEdit->insert("NEG");ui->lineEdit->returnPressed();}


void MainWindow::on_pushButtonSpace_released()
{    ui->lineEdit->insert(" ");}

//********
//CheckBox
//********





void MainWindow::on_checkClavier_clicked()
{
    ui->clavierSaisie1->setDisabled(ui->checkClavier->isChecked());
    ui->clavierSaisie1->setEnabled(ui->checkClavier->isChecked());
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    Pile *pile = Pile::getInstance();
    pile->setMaxAffiche(value);
    ui->vuePile->setRowCount(pile->getMaxAffiche());
    ui->vuePile->setColumnCount(1);
    ui->vuePile->verticalHeader()->setSectionResizeMode (QHeaderView::Fixed);

    QStringList numberList;

    for(unsigned int i = pile->getMaxAffiche(); i>0; i--) {
        QString str = QString::number(i);
        str += " :";
        numberList << str;
        // creation of the item of each line initialized with an empty string (chaine vide).
        ui->vuePile->setItem(i-1, 0, new QTableWidgetItem(""));
    }
    ui->vuePile->setVerticalHeaderLabels(numberList);


    // inhibit modification
    ui->vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);

    refresh();

}

void MainWindow::activerBipOpt(bool s) {
    QSettings settings;
    settings.setValue("Bip", s);
}

void MainWindow::playSound(){
   QSettings settings;
   if (settings.value("Bip").toBool())
{    qDebug()<<"test";
       QMediaPlayer* player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/beep.wav"));
       player->setVolume(50);
       player->play();
}
}



void MainWindow::on_pushButtonDup_released()
{
    ui->lineEdit->insert("DUP");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonSwap_released()
{
    ui->lineEdit->insert("SWAP");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonDrop_released()
{
    ui->lineEdit->insert("DROP");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtoNot_released()
{
    ui->lineEdit->insert("NOT");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonNeg_clicked()
{
    ui->lineEdit->insert("NEG");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonRe_clicked()
{
    ui->lineEdit->insert("RE");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonNum_released()
{
    ui->lineEdit->insert("NUM");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonIm_released()
{
    ui->lineEdit->insert("IM");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonDen_released()
{
    ui->lineEdit->insert("DEN");
    ui->lineEdit->returnPressed();
}

void MainWindow::on_pushButtonEnter_released()
{
    ui->lineEdit->returnPressed();
}
