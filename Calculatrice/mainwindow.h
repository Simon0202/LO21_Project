#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //*********
    //Clavier09
    //*********
    void on_pushButton0_released();
    void on_pushButton1_released();
    void on_pushButton2_released();
    void on_pushButton3_released();
    void on_pushButton4_released();
    void on_pushButton5_released();
    void on_pushButton6_released();
    void on_pushButton7_released();
    void on_pushButton8_released();
    void on_pushButton9_released();


    //********
    //LineEdit
    //********
    void on_pushBoutonDel_clicked();


    //**********
    //ClavierOpe
    //**********
    void on_pushButtonDiv1_released();
    void on_pushButtonPlus_released();
    void on_pushButtonMoins_released();
    void on_pushButtonMul_released();


    //******************************
    //Clear && Enter && Undo && Redo
    //******************************
    void on_pushButtonClear_released();
    void on_pushButtonEnter_released();
    void on_pushButtonUndo_released();
    void on_pushButtonRedo_released();



    void on_checkBoxClavier_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
