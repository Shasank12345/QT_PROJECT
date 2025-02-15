#include "studentwindow.h"
#include "ui_studentwindow.h"
#include "mainwindow.h"
#include "viewroutine.h"
#include "viewattendance.h"

StudentWindow::StudentWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::on_pushButton_clicked()
{
    VIEWROUTINE *Routine=new VIEWROUTINE();
    Routine->show();
    this->hide();

}


void StudentWindow::on_pushButton_3_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->show();
}


void StudentWindow::on_pushButton_4_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->show();
}


void StudentWindow::on_pushButton_2_clicked()
{
    VIEWATTENDANCE *Attendance=new VIEWATTENDANCE();
    Attendance->show();
    this->hide();

}

