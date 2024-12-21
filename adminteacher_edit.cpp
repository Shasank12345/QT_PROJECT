#include "adminteacher_edit.h"
#include "ui_adminteacher_edit.h"

AdminTeacher_Edit::AdminTeacher_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminTeacher_Edit)
{
    ui->setupUi(this);
}

AdminTeacher_Edit::~AdminTeacher_Edit()
{
    delete ui;
}
