#include "adminstudent_edit.h"
#include "ui_adminstudent_edit.h"

AdminStudent_Edit::AdminStudent_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminStudent_Edit)
{
    ui->setupUi(this);
}

AdminStudent_Edit::~AdminStudent_Edit()
{
    delete ui;
}
