#include "studentattendanceview.h"
#include "ui_studentattendanceview.h"

Studentattendanceview::Studentattendanceview(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Studentattendanceview)
{
    ui->setupUi(this);
}

Studentattendanceview::~Studentattendanceview()
{
    delete ui;
}
