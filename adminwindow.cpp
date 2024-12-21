#include "adminwindow.h"
#include "ui_adminwindow.h"
#include<QMenuBar>
#include<QPushButton>
#include<QHBoxLayout>
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

void AdminWindow::on_teacherpart_clicked()
{
    adminTeacher_edit =new AdminTeacher_Edit(this);
    adminTeacher_edit->show();
}




void AdminWindow::on_studentEdit_clicked()
{
    adminStudent_edit =new AdminStudent_Edit(this);
    adminStudent_edit->show();
}

