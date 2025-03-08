#include "editroutine.h"
#include "ui_editroutine.h"
#include"qmessagebox.h"
#include "editroutine.h"
#include "ui_editroutine.h"
#include"qmessagebox.h"
#include"mainwindow.h"
#include"routinewindow.h"
#include <QPalette>
#include <QPixmap>
#include <QSqlDatabase>
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
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to retrieve Teacher IDs:  " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }");
        msgBox.exec();
        return;
    }

    ui->comboBox_2->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});
}
void EditRoutine::popo()
{

    ui->comboBox_9->clear();
    QSqlQuery qry;
    qry.prepare("SELECT Name FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            QString name = qry.value(0).toString();
            ui->comboBox_9->addItem(name);
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to retrieve Teacher IDs:  " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

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

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to load: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
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
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to load: " + Q.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

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
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to load: " + Q.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }


}


void EditRoutine::on_pushButton_2_clicked()
{
    RoutineWindow *routine = new RoutineWindow();
    routine->show();
    this->hide();
}


void EditRoutine::on_pushButton_8_clicked()
{
    RoutineWindow *routine = new RoutineWindow();
    routine->show();
    this->hide();
}


void EditRoutine::on_pushButton_9_clicked()
{
    MainWindow *main =new MainWindow();
    main->show();
    this->hide();
}


void EditRoutine::on_pushButton_clicked()
{
    MainWindow *main =new MainWindow();
    main->show();
    this->hide();
}


void EditRoutine::on_comboBox_9_currentTextChanged(const QString &arg1)
{
    ui->comboBox_10->clear();

    QSqlQuery query;
    query.prepare("SELECT Subject FROM Teacher_data WHERE Name = :Name");
    query.bindValue(":Name", arg1);

    if(query.exec()) {
        while(query.next()) {

            ui->comboBox_10->addItem(query.value(0).toString());
        }

        if(ui->comboBox_10->count() == 0) {
            ui->comboBox_10->addItem("No ID found");
        }
    }
    else {

        qDebug() << "Error retrieving:" << query.lastError().text();
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to Load: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void EditRoutine::on_pushButton_3_clicked()
{
    QString name=ui->comboBox->currentText();
    QString sub=ui->comboBox_3->currentText();
    QString day=ui->comboBox_2->currentText();
    QString cs=ui->lineEdit->text();
    QString ce=ui->lineEdit_2->text();

    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    popo();
    ui->lineEdit_8->setText(name);
    ui->lineEdit_9->setText(sub);
    ui->lineEdit_10->setText(day);
    ui->lineEdit_11->setText(cs);
    ui->lineEdit_12->setText(ce);


    ui->stackedWidget->setCurrentIndex(1);
}


void EditRoutine::on_pushButton_10_clicked()
{
    QString name=ui->comboBox_9->currentText();
    QString day=ui->lineEdit_10->text();
    QString cs=ui->lineEdit_11->text();
    QString ce=ui->lineEdit_12->text();
    QString subject=ui->comboBox_10->currentText();

    QSqlQuery checkmultipleclass;
    checkmultipleclass.prepare("SELECT COUNT(*) FROM routine WHERE Day = :day AND Teacher_Name = :name");
    checkmultipleclass.bindValue(":day", day);
    checkmultipleclass.bindValue(":name", name);

    if (checkmultipleclass.exec() && checkmultipleclass.next()) {
        int count = checkmultipleclass.value(0).toInt();
        if (count > 0) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("  Conflict  ");
            msgBox.setText( name +"has class on "+ day);
            msgBox.setStyleSheet("QLabel { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to check for schedule conflicts: " + checkmultipleclass.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }");
        msgBox.exec();
        return;
    }


    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM routine WHERE Day = :day AND Class_Start = :cs AND Class_End = :ce");
    qry.bindValue(":day", day);
    qry.bindValue(":cs", cs);
    qry.bindValue(":ce", ce);

    if (!qry.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Data Error");
        msgBox.setText("Failed to execute query: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (!qry.next()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Data Error");
        msgBox.setText("No record found with the given day and class time");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    qry.prepare("UPDATE routine SET Teacher_Name = :name, Subject = :subject WHERE Day = :day AND Class_Start = :cs AND Class_End = :ce");
    qry.bindValue(":name", name);
    qry.bindValue(":subject", subject);
    qry.bindValue(":day", day);
    qry.bindValue(":cs", cs);
    qry.bindValue(":ce", ce);

    if (!qry.exec()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Update Failed");
        msgBox.setText("Could not update the Student_data: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Success");
    msgBox.setText(" updated successfully.");
    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;
}

