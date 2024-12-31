#include "crwindow.h"
#include "ui_crwindow.h"

CRWindow::CRWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CRWindow)
{
    ui->setupUi(this);
}

CRWindow::~CRWindow()
{
    delete ui;
}
