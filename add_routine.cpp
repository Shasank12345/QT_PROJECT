#include "add_routine.h"
#include "ui_add_routine.h"
#include <QDebug>
#include <QPalette>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>
#include <Qstring>
#include "QMessageBox"
#include <routinewindow.h>
#include <mainwindow.h>
#include <qmessagebox.h>
#include<QTime>
Add_routine::Add_routine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_routine)
{
    ui->setupUi(this);
}


void Add_routine::adddata()
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
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}

void Add_routine::day()
{
    ui->comboBox_3->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});
}



Add_routine::~Add_routine()
{
    delete ui;
}

void Add_routine::on_back1_clicked()
{
    RoutineWindow *routine = new RoutineWindow();
    routine->show();
    this->hide();
}


void Add_routine::on_home1_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->hide();
}


void Add_routine::on_search_clicked()
{
    QString teacherName = ui->comboBox->currentText();

    if (teacherName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a teacher's name.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT Subject FROM teacher_data WHERE Name = :name");
    query.bindValue(":name", teacherName);

    if (query.exec()) {
        if (query.next()) {
            QString subject = query.value(0).toString();
            ui->lineEdit_2->setText(subject);
        } else {
            QMessageBox::information(this, "Not Found", "No subject found for the given teacher.");
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to retrieve Teacher IDs:  " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void Add_routine::on_Save_clicked()
{
    QString name;
    QString subject;
    QString day;
    QString start;
    QString end;


    name=ui->comboBox->currentText();
    subject=ui->lineEdit_2->text();
    day = ui->comboBox_3->currentText();
    QTime startTime = ui->timeEdit->time();
    start = startTime.toString("hh:mm");

    QTime endTime = ui->timeEdit_2->time();
    end = endTime.toString("hh:mm");

    if (subject=="Not_Selected" ){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("  Input Error ");
        msgBox.setText( "Please Select Subject.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    else if (day=="Not_Selected" ){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("  Input Error ");
        msgBox.setText( "Please Select Day.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (start.isEmpty()){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("  Input Error ");
        msgBox.setText( "Please Select Class Start Time.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    else if (end.isEmpty()){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("  Input Error ");
        msgBox.setText( "Please Select Class end Time.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    // Check for the class time which is enter in already in database or not of that day
    QSqlQuery checkClassTime;
    checkClassTime.prepare(
        "SELECT COUNT(*) FROM routine "
        "WHERE Day = :day AND NOT (Class_end <= :start OR Class_start >= :end)");
    checkClassTime.bindValue(":day", day);
    checkClassTime.bindValue(":start", start);
    checkClassTime.bindValue(":end", end);

    if (checkClassTime.exec() && checkClassTime.next()) {
        int count = checkClassTime.value(0).toInt();
        if (count > 0) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("  Conflict  ");
            msgBox.setText( "This time slot is already occupied on " + day + ".");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to check schedule conflicts: " + checkClassTime.lastError().text());
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to check schedule conflicts: " + checkClassTime.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
        return;
    }



    //checking the teacher has multiple class or not on that day
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
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to check for schedule conflicts: " + checkmultipleclass.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    QSqlQuery insert;
    insert.prepare("INSERT INTO routine (Teacher_Name, Subject,Day,Class_start,Class_end) "
                      "VALUES (:name, :subject, :day, :start,:end)");
    insert.bindValue(":name", name);
    insert.bindValue(":subject", subject);
    insert.bindValue(":day",day );
    insert.bindValue(":start", start);
    insert.bindValue(":end", end);

    if (insert.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("  Success");
        msgBox.setText("Teacher Routine saved successfully.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to save teacher information: " + insert.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void Add_routine::on_comboBox_currentTextChanged(const QString &Name)
{
    ui->lineEdit_2->clear();

    QSqlQuery query;
    query.prepare("SELECT Subject FROM Teacher_data WHERE Name = :Name");
    query.bindValue(":Name", Name);

    if(query.exec()) {
        while(query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_2->setText(Name);
        }
    } else {
        qDebug() << "Error retriveing subject:" << query.lastError().text();
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to retrive subject: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

}
}

