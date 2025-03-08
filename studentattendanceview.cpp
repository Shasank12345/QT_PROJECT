#include "studentattendanceview.h"
#include "ui_studentattendanceview.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"QSqlQueryModel"
#include"qmessagebox.h"

Studentattendanceview::Studentattendanceview(const QString &studentemail,const QString &studentname,QWidget *parent)
    : QMainWindow(parent)
    ,studentgmail(studentemail)
    ,studentname(studentname)

, ui(new Ui::Studentattendanceview)

{
    ui->setupUi(this);
      this->setFixedSize(this->size());
    this->setWindowTitle("ATTENTANCE RECORD OF :" + studentname);



}

Studentattendanceview::~Studentattendanceview()
{
    delete ui;
}

void Studentattendanceview::on_pushButton_5_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->hide();
}


void Studentattendanceview::days()
{
    ui->comboBox_4->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});
}


void Studentattendanceview::populatecombo2()
{
    QSqlQuery query;
    query.prepare("SELECT Name FROM STUDENT_ENTRY WHERE Email = :Smail");
    query.bindValue(":Smail", studentgmail);
    if (query.exec()) {
        qDebug() << "DATA SUCESSFULLY LOADEDD";
        while (query.next()) {
            ui->comboBox->addItem(query.value(0).toString());
        }

    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }

}

void Studentattendanceview::subject()
{
    QSqlQuery q;
    q.prepare("SELECT Subject FROM Teacher_data");
    if(q.exec()){
        while (q.next()){
            ui->comboBox_2->addItem(q.value(0).toString());
        }
    }
    else
    {
        qDebug() <<"ERROR LOOADING DATA :"<<q.lastError().text();
    }




}


void Studentattendanceview::on_pushButton_4_clicked()
{
    if (QWidget *parent = this->parentWidget()) {
        parent->show();
    }
    this->hide();

}
void Studentattendanceview::on_pushButton_6_clicked() {

    QString subject = ui->comboBox_2->currentText();
    QString day = ui->comboBox_4->currentText().trimmed();
    QString date = ui->dateEdit_2->date().toString("yyyy-MM-dd");
    QString name = ui->comboBox->currentText().trimmed();

    if (subject.isEmpty() || day.isEmpty() || date.isEmpty() || name.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("INPUT ERROR");
        msgBox.setText("PLEASE FILL ALL FIELDS");
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query(QSqlDatabase::database());

    QString sql = "SELECT STUDENT_ID, STUDENT_NAME, SUBJECT, STATUS FROM ATTENDANCE WHERE STUDENT_NAME = ? AND SUBJECT = ? AND DATE = ? AND DAY = ?";
    query.prepare(sql);
    query.addBindValue(name);
    query.addBindValue(subject);
    query.addBindValue(date);
    query.addBindValue(day);

    // Debugging - Print query parameters
    qDebug() << "Executing SQL Query:";
    qDebug() << "STUDENT_NAME: " << name;
    qDebug() << "SUBJECT: " << subject;
    qDebug() << "DATE: " << date;
    qDebug() << "DAY: " << day;

    if (!query.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("INPUT ERROR");
        msgBox.setText("FAILED TO EXCEUTE QUERY"+query.lastError().text());
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }

    model->setQuery(query);

    if (model->rowCount() == 0) {
        QMessageBox::warning(this, "No Data", "No records found for the selected criteria.");
        qDebug() << "No data found!";
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, "STUDENT_ID");
    model->setHeaderData(1, Qt::Horizontal, "STUDENT_NAME");
    model->setHeaderData(2, Qt::Horizontal, "SUBJECT");
    model->setHeaderData(3, Qt::Horizontal, "STATUS");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setFont(QFont("Times New Roman", 10));

   // QMessageBox::information(this, "Success", "Data retrieved and displayed successfully.");
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("SUCESS");
    msgBox.setText("DATA RETRIEVED AND DISPLAYED SUCESSFULLY");
    // Apply a stylesheet to change text color in QLabel (which displays the text)
    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;
}
