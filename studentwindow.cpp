#include "studentwindow.h"
#include "routinewindow.h"
#include "ui_studentwindow.h"
#include "mainwindow.h"
#include "viewroutine.h"
#include"studentattendanceview.h"
#include<QStackedWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<loginWindow.h>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include"qmessagebox.h"

StudentWindow::StudentWindow(const QString &email, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentWindow)
    ,Studentemail(email)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("WELCOME  " +Studentemail);
    loadstudentname();



}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow:: loadstudentname()
{
    QSqlQuery query;

    query.prepare("SELECT Name FROM STUDENT_ENTRY WHERE Email = :Smail");
    query.bindValue(":Smail", Studentemail);
    if (query.exec() && query.next()){
        studentname = query.value(0).toString();
        qDebug() << "student name loaded:" << studentname;
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Failed to load student name: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
    }
}


void StudentWindow::on_pushButton_clicked()
{
    viewroutinestudent *Routine= new viewroutinestudent(studentname,this);
    Routine->setAttribute(Qt::WA_DeleteOnClose,false);
    Routine->populatecombo();


    Routine->show();
    this->hide();

}


void StudentWindow::on_pushButton_3_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->hide();
}


void StudentWindow::on_pushButton_4_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->hide();
}



void StudentWindow::on_pushButton_2_clicked()
{
    Studentattendanceview *next=new Studentattendanceview(Studentemail,studentname,this);
    next->setAttribute(Qt::WA_DeleteOnClose,false);
    next->show();
    next->populatecombo2();
    next->days();
    next->subject();
    this->hide();

}






