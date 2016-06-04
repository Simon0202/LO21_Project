#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pile.h"
#include "litteraleabstraite.h"
#include <QVector>
#include <qiterator.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Pile* pile = Pile::getInstance();
    QSettings settings;
    ui->setupUi(this);

    ui->vuePile->setRowCount(pile->getMaxAffiche());
    settings.setValue("Pile", pile->getMaxAffiche());
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
    pile->setMessage("Bienvenue !");

    //keyboard enabled at start
    settings.setValue("Clavier", true);

    refresh();
}

void MainWindow::refresh(){
    Pile* pile = Pile::getInstance();
    unsigned int nb = 0;
    // delete everything
    for(unsigned int i=0; i<pile->getMaxAffiche(); i++)
        ui->vuePile->item(i,0)->setText("");
    // update
    QVectorIterator<LitteraleAbstraite*> it(*pile->getStack());
    for(it.toBack() ; it.hasPrevious() && nb<pile->getMaxAffiche(); nb++){
    ui->vuePile->item(pile->getMaxAffiche()-1-nb,0)->setText(it.previous()->toString());
    }
}

void MainWindow::setMaxAffiche(int i) {
    Pile* pile = Pile::getInstance();
    pile->setMaxAffiche(i);
    ui->vuePile->setRowCount(i);
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
void MainWindow::on_pushButtonDiv1_released(){ui->lineEdit->insert("/");}
void MainWindow::on_pushButtonMul_released(){ui->lineEdit->insert("*");}
void MainWindow::on_pushButtonMoins_released(){ui->lineEdit->insert("-");}
void MainWindow::on_pushButtonPlus_released(){ui->lineEdit->insert("+");}


//******************************
//Clear && Enter && Undo && Redo
//******************************
void MainWindow::on_pushButtonClear_released(){ui->lineEdit->clear();}

//void MainWindow::on_pushButtonEnter_released(){}
void MainWindow::on_pushButtonUndo_released(){ui->lineEdit->undo();}
void MainWindow::on_pushButtonRedo_released(){ui->lineEdit->redo();}


//****************
//Boutton Speciaux
//****************
void MainWindow::on_pushButtonDollar_released(){ui->lineEdit->insert("$");}
void MainWindow::on_pushButtonDiv_released(){ui->lineEdit->insert("DIV");}
void MainWindow::on_pushButtonNeg_released(){ui->lineEdit->insert("NEG");}


//********
//CheckBox
//********
void MainWindow::on_pushButtonSpace_released()
{    ui->lineEdit->insert(" ");
}




