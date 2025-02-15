#include "editroutine.h"
#include "ui_editroutine.h"

EditRoutine::EditRoutine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditRoutine)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

EditRoutine::~EditRoutine()
{
    delete ui;
}
