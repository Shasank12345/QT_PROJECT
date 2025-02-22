#include "routinewindow.h"
#include "ui_routinewindow.h"
#include"mainwindow.h"
#include"adminwindow.h"
#include"add_routine.h"
#include <QDebug>
#include"deleteroutine.h"
#include"viewroutine.h"
#include"editroutine.h"
RoutineWindow::RoutineWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoutineWindow)
{
    ui->setupUi(this);
}

RoutineWindow::~RoutineWindow()
{
    delete ui;

}

void RoutineWindow::on_home_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}


void RoutineWindow::on_back_clicked()
{
    AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
    this->hide();
}



void RoutineWindow::on_pushButton_clicked()
{
    Add_routine *add =new Add_routine();
    add->show();
    add->adddata();
    add->day();

    this->hide();
}


void RoutineWindow::on_pushButton_3_clicked()
{
    deleteroutine *del = new deleteroutine();
     del->show();
    del->adddata();
    del->day();

    this->hide();
}


void RoutineWindow::on_pushButton_2_clicked()
{
    VIEWROUTINE *view= new VIEWROUTINE();
    view->show();
   view->day();

    this->hide();
}


void RoutineWindow::on_pushButton_4_clicked()
{
    EditRoutine *edit= new EditRoutine();
    edit->show();
      this->hide();
}


