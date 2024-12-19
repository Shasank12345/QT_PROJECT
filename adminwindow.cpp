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

void AdminWindow::on_pushButton_clicked()
{
    QPushButton *p1=new QPushButton(this);
    p1->setText("ADD STUDENT");

    QPushButton *p2=new QPushButton(this);

    p2->setText("DELETE STUDENT");

    QHBoxLayout *p=new QHBoxLayout(this);
    p->addWidget(p1);
    p->addWidget(p2);




}

