#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBoxClavier->setChecked(true);
    ui->checkBoxBip->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::afficheTexte(QString &text){
    for(unsigned int i=0; i<5 ; i++){
        //Implementation de la pile avec QStack
    }
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

void MainWindow::on_pushButtonEnter_released(){
    QString const text = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (text != ""){
        ui->labelPile1->setText(text);
    }
}
void MainWindow::on_pushButtonUndo_released(){ui->lineEdit->undo();}
void MainWindow::on_pushButtonRedo_released(){ui->lineEdit->redo();}


//****************
//Boutton Speciaux
//****************
void MainWindow::on_pushButtonDollar_released(){ui->lineEdit->insert("$");}
void MainWindow::on_pushButtonDiv_released(){ui->lineEdit->insert("DIV");}
void MainWindow::on_pushButtonNeg_released(){ui->lineEdit->insert("NEG");}



void MainWindow::on_checkBoxClavier_clicked()
{
  ui->vue4CalcClavier->setDisabled(ui->checkBoxClavier->isChecked());
  ui->vue4CalcClavier->setEnabled(ui->checkBoxClavier->isChecked());

}

