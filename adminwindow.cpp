#include "adminwindow.h"
#include "ui_adminwindow.h"
#include<QMenuBar>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMessageBox>
#include"mainwindow.h"
AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{

    ui->setupUi(this);

}

AdminWindow::~AdminWindow()
{
    delete ui;

}









void AdminWindow::on_home_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}


void AdminWindow::on_pushButton4_clicked()
{
    adminTeacher_edit =new AdminTeacher_Edit(this);
    adminTeacher_edit->show();
    this->hide();


}


void AdminWindow::on_pushButton5_clicked()
{
    adminStudent_edit =new AdminStudent_Edit(this);
    adminStudent_edit->show();
    this->hide();
}


void AdminWindow::on_pushButton6_clicked()
{
    routinewindow =new RoutineWindow(this);
    routinewindow->show();
    this->hide();
}


void AdminWindow::on_OK1_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}

