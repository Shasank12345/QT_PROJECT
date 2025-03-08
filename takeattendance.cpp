#include "takeattendance.h"
#include "ui_takeattendance.h"
#include<QDateEdit>
#include<QMessageBox>
#include"qmessagebox.h"
takeattendance::takeattendance(const QString &teacherEmail, const QString &teacherSubject,QWidget *parent)
    : QMainWindow(parent)
    , teacherEmail(teacherEmail)
    ,teacherSubject(teacherSubject)
    ,ui(new Ui::takeattendance)
{
   // connect(ui->pushButton_2, &QPushButton::clicked, this, &takeattendance::on_pushButton_2_clicked);
    ui->setupUi(this);
    this->setWindowTitle(" Attendance of- " + teacherSubject);
     ui->dateEdit->setDate(QDate::currentDate());

    ui->comboBox_3->clear();

    ui->comboBox_3->addItem(teacherSubject);

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



/*void takeattendance::populatecombo3()
{

}*/



void takeattendance::populatecombo4()
{
     ui->comboBox_4->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});

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
   //ui->dateEdit->setDisplayFormat("yyyy-MM-dd");  // Show only the date
   // ui->dateEdit->setDate(QDate::currentDate());
 QString studentName = ui->comboBox->currentText();
        QString studentId =ui->comboBox_2->currentText();
        QString subject =ui->comboBox_3->currentText();
        QString date =ui->dateEdit->date().toString("yyyy-MM-dd");

        QString day = ui->comboBox_4->currentText();
        QString status =ui->radioButton->isChecked() ? "Absent" :ui->radioButton_2->isChecked() ? "Present" : "";

        // Check if all required fields are filled
        if (studentName.isEmpty() || studentId.isEmpty() || subject.isEmpty() || day.isEmpty() || status.isEmpty()) {
              // QMessageBox::warning(this, "Error", "fill all fields :");
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("INPUT ERROR");
            msgBox.setText("PLEASE FILL ALL FIELDS");
            // Apply a stylesheet to change text color in QLabel (which displays the text)
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;

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
         // QMessageBox::warning(this, "Sucess", "Attendance taken sucessfully :");
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("SUCESS");
            msgBox.setText("ATTENDANCE TAKEN SUCESSFULLY");

            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;


        } else {
           // QMessageBox::warning(this, "Error", "Failed to Save Data :"+ query.lastError().text());
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("ERROR");
            msgBox.setText("FAILED TO SAVE DATA"+ query.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;

            qDebug() << "Insert failed:" << query.lastError().text();
        }
}


/*void takeattendance::on_pushButton_2_clicked()
{
    TeacherWindow *t=new TeacherWindow;
    t->show();
    this->hide();
}
*/





void takeattendance::on_comboBox_currentTextChanged(const QString &Name)
{
    ui->comboBox_2->clear();

    // Prepare query to retrieve the student ID corresponding to the selected name
    QSqlQuery query;
    query.prepare("SELECT Student_id FROM STUDENT_ENTRY WHERE Name = :Name");
    query.bindValue(":Name", Name);

    if(query.exec()) {
        // If multiple IDs exist (unlikely for unique names), they will all be added
        while(query.next()) {
            QString studentId = query.value(0).toString();
            ui->comboBox_2->addItem(studentId);
        }
        // Optionally, check if no IDs were returned
        if(ui->comboBox_2->count() == 0) {
            ui->comboBox_2->addItem("No ID found");
        }
    } else {
        qDebug() << "Error retrieving student ID:" << query.lastError().text();
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("DATABASE ERROR");
        msgBox.setText("FAILED TO LOAD STUDENT ID"+ query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }


}



void takeattendance::on_pushButton_2_clicked()
{
    qDebug()<<"BACK CLICKED";

   if (QWidget *parent = this->parentWidget()) {
        parent->show();
   }
    this->hide();
}

















