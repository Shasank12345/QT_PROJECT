#include "deleteroutine.h"
#include "ui_deleteroutine.h"
#include <QDebug>
#include "mainwindow.h"
#include "routinewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include"qmessagebox.h"

deleteroutine::deleteroutine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteroutine)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}


void deleteroutine::adddata()
{
    ui->comboBox->clear();
    QSqlQuery qry;
    qry.prepare("SELECT Name FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            QString name = qry.value(0).toString();
            ui->comboBox->addItem(name);
        }
    } else {
        QMessageBox::critical(this,
                              "Database Error",
                              "Failed to retrieve Teacher IDs: " + qry.lastError().text());
    }
}

void deleteroutine::day()
{
    ui->comboBox_2->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});
}


deleteroutine::~deleteroutine()
{
    delete ui;
}

void deleteroutine::on_Home_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->hide();

}

void deleteroutine::on_Back_clicked()
{
    RoutineWindow *Back=new RoutineWindow();
    Back->show();
    this->hide();
}


void deleteroutine::on_Delete_clicked()
{
    QString name = ui->comboBox->currentText().trimmed();
    QString day = ui->comboBox_2->currentText().trimmed();

    if (name.isEmpty() || day.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select both Name and Day.");
        return;
    }
    // Confirm deletion with the user
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Confirmation",
        "Are you sure you want to delete " + name + "routine ?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return; // User canceled the deletion
    }

    QSqlQuery qry;
    qry.prepare("DELETE FROM routine WHERE Teacher_Name = :name AND Day = :day");
    qry.bindValue(":name", name);
    qry.bindValue(":day", day);

    if (qry.exec()) {
        QMessageBox::information(this, "Success", "Routine deleted successfully.");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to delete routine: " + qry.lastError().text());
    }
}




void deleteroutine::on_delete_2_clicked()
{

    QString name = ui->comboBox->currentText();
    QString day = ui->comboBox_2->currentText();

    if (name.isEmpty() || day.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select both Name and Day.");
        return;
    }
    // Confirm deletion with the user
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Confirmation",
        "Are you sure you want to delete " + name + " routine of " + day +"?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return; // User canceled the deletion
    }

    QSqlQuery qry;
    qry.prepare("DELETE FROM routine WHERE Teacher_Name = :name AND Day = :day");
    qry.bindValue(":name", name);
    qry.bindValue(":day", day);

    if (qry.exec()) {
        QMessageBox::information(this, "Success", "Routine deleted successfully.");
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to delete routine: " + qry.lastError().text());
    }
}


