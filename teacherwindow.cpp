#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include<QStackedWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
//#include <QStandardItemModel>




TeacherWindow::TeacherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}










void TeacherWindow::on_pushButton_3_clicked()
{
    take->populatecombox1();
    take->populatecombox2();
    take->populatecombo3();
    take->populatecombo4();
    take->show();
    this->hide();

}


void TeacherWindow::on_pushButton_clicked()
{
    view->populatecombo1();
    view->populatecombo2();
   view->show();
    this->hide();


}


void TeacherWindow::on_pushButton_2_clicked()
{
    view2->show();
    view2->day();
    this->hide();

}


void TeacherWindow::on_pushButton_5_clicked()
{
    main->show();
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

