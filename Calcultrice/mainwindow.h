#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QTableView>
#include <QAction>
#include <QMenuBar>
#include <QTableWidgetItem>
#include <QSettings>
#include <QStandardPaths>
#include <QShortcut>
#include <QSlider>
#include "pile.h"
#include "controleur.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void playSound();
    ~MainWindow();

public slots:
    void refresh();
    void on_lineEdit_returnPressed();
    void activerBipOpt(bool s);



private slots:
    void setMaxAffiche(int);


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


    //*************
    //ClavierLettre
    //*************
    void on_pushButtonA_released();
    void on_pushButtonB_released();
    void on_pushButtonC_released();
    void on_pushButtonD_released();
    void on_pushButtonE_released();
    void on_pushButtonF_released();
    void on_pushButtonG_released();
    void on_pushButtonH_released();
    void on_pushButtonI_released();
    void on_pushButtonJ_released();
    void on_pushButtonK_released();
    void on_pushButtonL_released();
    void on_pushButtonM_released();
    void on_pushButtonN_released();
    void on_pushButtonO_released();
    void on_pushButtonP_released();
    void on_pushButtonQ_released();
    void on_pushButtonR_released();
    void on_pushButtonS_released();
    void on_pushButtonT_released();
    void on_pushButtonU_released();
    void on_pushButtonV_released();
    void on_pushButtonW_released();
    void on_pushButtonX_released();
    void on_pushButtonY_released();
    void on_pushButtonZ_released();


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
    void on_pushButtonUndo_released();
    void on_pushButtonRedo_released();

    //**********************
    //ClavierBouttonSpeciaux
    //**********************
    void on_pushButtonDollar_released();
    void on_pushButtonDiv_released();
    void on_pushButtonNeg_released();

    void on_pushButtonSpace_released();
    void on_checkClavier_clicked();

    void on_verticalSlider_valueChanged(int value);


    void on_pushButtonDup_released();

    void on_pushButtonSwap_released();

    void on_pushButtonDrop_released();

    void on_pushButtoNot_released();

    void on_pushButtonNeg_clicked();

    void on_pushButtonRe_clicked();

    void on_pushButtonNum_released();

    void on_pushButtonIm_released();

    void on_pushButtonDen_released();

    void on_pushButtonEnter_released();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
