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
void MainWindow::on_pushButtonEnter_released(){;}
void MainWindow::on_pushButtonUndo_released(){ui->lineEdit->undo();}
void MainWindow::on_pushButtonRedo_released(){ui->lineEdit->redo();}




void MainWindow::on_checkBoxClavier_clicked()
{
  ui->vue4CalcClavier->setDisabled(ui->checkBoxClavier->isChecked());
  ui->vue4CalcClavier->setEnabled(ui->checkBoxClavier->isChecked());

}
