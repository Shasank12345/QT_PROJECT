#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include<QStackedWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<loginWindow.h>
#include <QStandardItemModel>
#include<takeattendance.h>
#include<qmessagebox.h>
TeacherWindow::TeacherWindow(const QString &EMAIL,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
    ,teacheremail(EMAIL)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());


    loadTeacherSubject();

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::loadTeacherSubject()
{
    QSqlQuery query;
    query.prepare("SELECT subject FROM Teacher_data WHERE email = :email");
    query.bindValue(":email", teacheremail);
    if (query.exec() && query.next()) {
        teacherSubject = query.value(0).toString();
        qDebug() << "Teacher subject loaded:" << teacherSubject;
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Failed to load teacher subject: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
    }
}


void TeacherWindow::on_pushButton_clicked()
{
    VIEWATTENDANCE *view=new VIEWATTENDANCE(teacheremail,teacherSubject,this);

    view->setAttribute(Qt::WA_DeleteOnClose,false);
     view->show();
  // view->populatecombo1();
    view->populatecombo2();
   // view->show();
    this->hide();



}


void TeacherWindow::on_pushButton_2_clicked()
{
    VIEWROUTINE *view2=new VIEWROUTINE(teacheremail,teacherSubject,this);
    view2->setAttribute(Qt::WA_DeleteOnClose,false);
    view2->show();
    view2->day();
    this->hide();

}



void TeacherWindow::on_pushButton_6_clicked()
{
    main->show();
    this->hide();
}


void TeacherWindow::on_pushButton_4_clicked()
{

}

void TeacherWindow::on_pushButton_3_clicked()
{
    takeattendance *take = new takeattendance(teacheremail, teacherSubject, this);
  //  take->setAttribute(Qt::WA_DeleteOnClose); // Auto-delete when closed
    take->populatecombox1();
    // take->populatecombox2();
    // take->populatecombo3();
    take->populatecombo4();
    take->show();
    this->hide();

}

