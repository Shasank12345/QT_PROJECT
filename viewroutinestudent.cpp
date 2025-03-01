#include "viewroutinestudent.h"
#include "ui_viewroutinestudent.h"

viewroutinestudent::viewroutinestudent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::viewroutinestudent)
{
    ui->setupUi(this);
}

viewroutinestudent::~viewroutinestudent()
{
    delete ui;
}
