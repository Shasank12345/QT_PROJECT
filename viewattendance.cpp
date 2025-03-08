#include "viewattendance.h"
#include "ui_viewattendance.h"
#include<QMessageBox>
#include"qmessagebox.h"

VIEWATTENDANCE::VIEWATTENDANCE(const QString &teacherEmail, const QString &teacherSubject,QWidget *parent)
    : QMainWindow(parent)
    ,teacherEmail(teacherEmail)
    ,teacherSubject(teacherSubject)
    , ui(new Ui::VIEWATTENDANCE)

{
    ui->setupUi(this);
    this->setWindowTitle(" Attendance of- " + teacherSubject);

    ui->comboBox->clear();

    ui->comboBox->addItem(teacherSubject);

}



void VIEWATTENDANCE::populatecombo2()
{
    ui->comboBox_3->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});
}



VIEWATTENDANCE::~VIEWATTENDANCE()
{
    delete ui;
}

void VIEWATTENDANCE::fetchdata()
{

    QString subject = ui->comboBox->currentText();
    QString day = ui->comboBox_3->currentText().trimmed();
     QString date = ui->dateEdit->date().toString("yyyy-MM-dd");

    if (subject.isEmpty() || day.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select Subject, Day, and Date.");
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query(QSqlDatabase::database());

    QString sql = "SELECT STUDENT_ID, STUDENT_NAME, SUBJECT, STATUS FROM ATTENDANCE WHERE SUBJECT = ? AND DATE = ? AND DAY = ?";
    query.prepare(sql);
    query.addBindValue(subject);
    query.addBindValue(date);
    query.addBindValue(day);

    // Debugging - Print query parameters
    qDebug() << "Executing SQL Query:";
    qDebug() << "SUBJECT: " << subject;
    qDebug() << "DATE: " << date;
    qDebug() << "DAY: " << day;

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + query.lastError().text());
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
    model->setHeaderData(2, Qt::Horizontal, "STATUS");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setFont(QFont("Times New Roman", 10));
    //QMessageBox::information(this, "Success", "Data retrieved and displayed successfully.");
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("SUCESS");
    msgBox.setText("DATA RETRIEVED AND DISPLAYED SUCESSFULLY");
    // Apply a stylesheet to change text color in QLabel (which displays the text)
    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;

}


void VIEWATTENDANCE::on_pushButton_3_clicked()
{
    main->show();
    this->hide();

}
void VIEWATTENDANCE::on_pushButton_clicked()
{
    qDebug() << "Submit button clicked!";
    fetchdata();
    qDebug() << "Fetch data executed!";
    //this->show();
    qDebug() << "Window Visibility: " << this->isVisible();
    //fetchdata();
  //  this->raise(); // Brings the window to the front
    this->activateWindow();
}


void VIEWATTENDANCE::on_pushButton_2_clicked()
{
    if (QWidget *parent = this->parentWidget()){
        parent->show();
    }
    this->hide();
}



