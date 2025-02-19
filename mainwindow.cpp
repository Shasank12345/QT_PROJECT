#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qstring>
#include<QPixmap>
#include<QPalette>
#include<QMessageBox>
#include"qmessagebox.h"
#include<loginWindow.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("../../DATABASE/FACULTY.db");
  if (!db.open()) {
      QMessageBox::critical(this, "Database Error", "Failed to connect to database: " + db.lastError().text());
    }





}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    loginwindow =new LOGINWINDOW("admin",this);
    loginwindow->show();
    this->hide();


}



void MainWindow::on_pushButton_2_clicked()

{
     loginwindow =new LOGINWINDOW("teacher",this);
     loginwindow->show();
     this->hide();


}


void MainWindow::on_pushButton_3_clicked()
{
    loginwindow =new LOGINWINDOW("student",this);
    loginwindow->show();
    this->hide();

}

