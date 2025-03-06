#include "editroutine.h"
#include "ui_editroutine.h"
#include"qmessagebox.h"

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





void EditRoutine::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_3->clear();

    QSqlQuery query;
    query.prepare("SELECT Subject FROM Teacher_data WHERE Name = :Name");
    query.bindValue(":Name", arg1);

    if(query.exec()) {
        while(query.next()) {

            ui->comboBox_3->addItem(query.value(0).toString());
        }

        if(ui->comboBox_3->count() == 0) {
            ui->comboBox_3->addItem("No ID found");
        }
    }
    else {

        qDebug() << "Error retrieving:" << query.lastError().text();
        QMessageBox::warning(this, "Database Error", "Failed to load: " + query.lastError().text());
    }



}


void EditRoutine::on_pushButton_4_clicked()
{
    QString a;
    QString b;
    a=ui->comboBox->currentText().trimmed();
    b=ui->comboBox_2->currentText().trimmed();
    QSqlQuery Q;
    Q.prepare("SELECT Class_start FROM routine WHERE Teacher_name = ? AND Day = ?");
    Q.addBindValue(a);
    Q.addBindValue(b);
    if(Q.exec()){
        while(Q.next()){
            ui->lineEdit->setText(Q.value(0).toString());
        }
    }
    else{
        qDebug() << "Error retrieving:" << Q.lastError().text();
        QMessageBox::warning(this, "Database Error", "Failed to load: " + Q.lastError().text());

    }
    Q.prepare("SELECT Class_end FROM routine WHERE Teacher_name = ? AND Day = ?");
    Q.addBindValue(a);
    Q.addBindValue(b);
    if(Q.exec()){
        while(Q.next()){
            ui->lineEdit_2->setText(Q.value(0).toString());
        }
    }
    else{
        qDebug() << "Error retrieving:" << Q.lastError().text();
        QMessageBox::warning(this, "Database Error", "Failed to load: " + Q.lastError().text());

    }


}

