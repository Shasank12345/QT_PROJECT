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

void EditRoutine::popu()
{

    QSqlQuery query;
    if (query.exec("SELECT Teacher_Name FROM routine")) {
        while (query.next()) {
            ui->comboBox->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }

    ui->comboBox_2->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});



}




