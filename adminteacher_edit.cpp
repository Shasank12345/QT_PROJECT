#include "adminteacher_edit.h"
#include "ui_adminteacher_edit.h"

AdminTeacher_Edit::AdminTeacher_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminTeacher_Edit)
{
    ui->setupUi(this);
    connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Add_data_clicked);
     connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Edit_clicked);
      connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Delet_clicked);
     connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_addback_clicked);
     connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_editback_clicked);
    connect(ui->Add_data, &QPushButton::clicked, this, &AdminTeacher_Edit::on_deletback_clicked);

}

AdminTeacher_Edit::~AdminTeacher_Edit()
{
    delete ui;
}


void AdminTeacher_Edit::on_Add_data_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AdminTeacher_Edit::on_Edit_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void AdminTeacher_Edit::on_Delet_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}





void AdminTeacher_Edit::on_addback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}




void AdminTeacher_Edit::on_deletback_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}



