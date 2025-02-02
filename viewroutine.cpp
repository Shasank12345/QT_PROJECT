#include "viewroutine.h"
#include "ui_viewroutine.h"

VIEWROUTINE::VIEWROUTINE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VIEWROUTINE)
{
    ui->setupUi(this);
}

VIEWROUTINE::~VIEWROUTINE()
{
    delete ui;
}
