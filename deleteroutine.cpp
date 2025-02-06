#include "deleteroutine.h"
#include "ui_deleteroutine.h"
#include <QDebug>

deleteroutine::deleteroutine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteroutine)
{
    ui->setupUi(this);
}



deleteroutine::~deleteroutine()
{
    delete ui;
}


