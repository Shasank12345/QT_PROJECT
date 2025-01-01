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




void AdminWindow::on_OK1_clicked()
{
   if(ui->radioButton4->isChecked()){
        adminTeacher_edit =new AdminTeacher_Edit(this);
          adminTeacher_edit->show();
    }
    if(ui->radioButton5->isChecked()){
        adminStudent_edit =new AdminStudent_Edit(this);
       adminStudent_edit->show();
    }
    if(ui->radioButton6->isChecked()){
        routinewindow =new RoutineWindow(this);
        routinewindow->show();
    }
}





void AdminWindow::on_home_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

