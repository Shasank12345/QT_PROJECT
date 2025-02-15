#include "takeattendance.h"
#include "teacherwindow.h"
#include "ui_takeattendance.h"
#include<QDateEdit>
#include<QMessageBox>
#include"qmessagebox.h"
takeattendance::takeattendance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::takeattendance)
{
    ui->setupUi(this);
}

void takeattendance::populatecombox1()
{
    QSqlQuery query;
    if (query.exec("SELECT NAME FROM STUDENT_ENTRY")) {
        while (query.next()) {
            ui->comboBox->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }

}

void takeattendance::populatecombox2()
{
    QSqlQuery query;
    if (query.exec("SELECT Student_id FROM STUDENT_ENTRY")) {
        while (query.next()) {
            ui->comboBox_2->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }

}

void takeattendance::populatecombo3()
{
    QSqlQuery query;
    if (query.exec("SELECT Subject FROM Teacher_data")) {
        while (query.next()) {
            ui->comboBox_3->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }

}

void takeattendance::populatecombo4()
{
     ui->comboBox_4->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});

}

takeattendance::~takeattendance()
{
    delete ui;
}

void takeattendance::on_pushButton_3_clicked()
{
    main->show();
    this->hide();

}


void takeattendance::on_pushButton_clicked()
{
 QString studentName = ui->comboBox->currentText();
        QString studentId =ui->comboBox_2->currentText();
        QString subject =ui->comboBox_3->currentText();
        QString date =ui->dateEdit->date().toString("yyyy-MM-dd");
        QString day = ui->comboBox_4->currentText();
        QString status =ui->radioButton->isChecked() ? "Absent" :ui->radioButton_2->isChecked() ? "Present" : "";

        // Check if all required fields are filled
        if (studentName.isEmpty() || studentId.isEmpty() || subject.isEmpty() || day.isEmpty() || status.isEmpty()) {
               QMessageBox::warning(this, "Error", "fill all fields :");

            return;
        }

        // Insert into database
        QSqlQuery query;
        query.prepare(R"(
            INSERT INTO ATTENDANCE (STUDENT_NAME,STUDENT_ID,SUBJECT,DATE,DAY,STATUS)
            VALUES (:student_name, :student_id, :subject, :date, :day, :status)
        )");
        query.bindValue(":student_name", studentName);
        query.bindValue(":student_id", studentId);
        query.bindValue(":subject", subject);
        query.bindValue(":date", date);
        query.bindValue(":day", day);
        query.bindValue(":status", status);

        if (query.exec()) {
          QMessageBox::warning(this, "Sucess", "Attendance taken sucessfully :");


        } else {
            QMessageBox::warning(this, "Error", "Failed to Save Data :"+ query.lastError().text());

            qDebug() << "Insert failed:" << query.lastError().text();
        }
}


void takeattendance::on_pushButton_2_clicked()
{
    TeacherWindow *t=new TeacherWindow;
    t->show();
    this->hide();
}


