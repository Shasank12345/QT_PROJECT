#include "adminwindow.h"
#include "ui_adminwindow.h"
#include<QMenuBar>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMessageBox>
#include"mainwindow.h"
#include<loginWindow.h>
#include"adminstudent_edit.h"
#include"adminteacher_edit.h"
#include"routinewindow.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    //connect(ui->OK1, &QPushButton::clicked, this, &AdminWindow::on_OK1_clicked);

    ui->setupUi(this);
    this->setFixedSize(this->size());

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
    AdminTeacher_Edit *adminTeacher_edit =new AdminTeacher_Edit(this);
    adminTeacher_edit->show();
    this->hide();



}


void AdminWindow::on_pushButton5_clicked()
{
    AdminStudent_Edit *adminStudent_edit =new AdminStudent_Edit(this);
    adminStudent_edit->show();
    this->hide();
}


void AdminWindow::on_pushButton6_clicked()
{
    RoutineWindow *routinewindow =new RoutineWindow(this);
    routinewindow->show();
    this->hide();
}





void AdminWindow::on_LOGOUT_clicked()
{
    LOGINWINDOW *login=new LOGINWINDOW("");
    login->show();
}

