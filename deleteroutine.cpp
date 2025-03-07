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

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("DATABASE ERROR");
        msgBox.setText("FAILED TO RETRIVE TEACHER IDS"+ qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
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
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Input Error  ");
        msgBox.setText("Please select both name and day: ");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
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

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle(" Success  ");
        msgBox.setText("Routine deleted successfully: ");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to delete routine: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}




void deleteroutine::on_delete_2_clicked()
{

    QString name = ui->comboBox->currentText();
    QString day = ui->comboBox_2->currentText();

    if (name.isEmpty() || day.isEmpty()) {

        return;
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Input Error  ");
        msgBox.setText("Please select both name and day: ");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
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
        ;
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle(" Success  ");
        msgBox.setText("Routine deleted successfully: ");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to delete routine: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}





