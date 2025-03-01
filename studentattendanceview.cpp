#include "studentattendanceview.h"
#include "ui_studentattendanceview.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"QSqlQueryModel"


Studentattendanceview::Studentattendanceview(const QString &studentemail,const QString &studentname,QWidget *parent)
    : QMainWindow(parent)
    ,studentname(studentname)
, ui(new Ui::Studentattendanceview)

{
    ui->setupUi(this);
    this->setWindowTitle(" Attendance of- " + studentname);
    ui->dateEdit_2->setDate(QDate::currentDate());
    //u.0i->comboBox->clear();
    ui->comboBox->addItem(studentname);

}

Studentattendanceview::~Studentattendanceview()
{
    delete ui;
}

void Studentattendanceview::fetchdata()
{
    QString name=ui->comboBox->currentText().trimmed();
    QString day=ui->comboBox_4->currentText().trimmed();
    QString date=ui->dateEdit_2->date().toString("yyyy-MM-dd");
    if (name.isEmpty() || day.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Please select name, Day, and Date.");
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(QSqlDatabase::database());

    // Prepare SQL query with the correct number of placeholders
    QString sql = "SELECT STUDENT_ID,STUDENT_NAME,STATUS FROM ATTENDANCE WHERE name = ? AND DAY = ? AND DATE= ?";
    query.prepare(sql);
    query.addBindValue(name);
    query.addBindValue(day);
    query.addBindValue(date);

    if (!query.exec()) {
        //QMessageBox::critical(nullptr, "Query Error", "Failed to execute query: " + query.lastError().text());
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("FAILED TO EXCEUTE QUERY"+ query.lastError().text());

        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }
    else{
        QMessageBox::information(nullptr, "Query Sucess", "SUCESFULLY EXECUTED QUERY");

    }
    //model->setQuery(query);

    // Debugging: Check if data exists
    if (model->rowCount() == 0) {
        //QMessageBox::warning(nullptr, "No Data", "No records found for the selected criteria.");
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("NO DATA");
        msgBox.setText("NO RECORDS FOUND FOR THE SELECTED CRITERIA");

        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

        qDebug() << "No data found!";
        return;
    }

    // Set column headers

    //model->setHeaderData(0, Qt::Horizontal, "STUDENT_ID");
    model->setHeaderData(1, Qt::Horizontal, "STUDENT_NAME");
    model->setHeaderData(2, Qt::Horizontal, "STATUS");
    //model->setHeaderData(3, Qt::Horizontal, "Subject");


    // Ensure tableView is not NULL
    if (!ui->tableView) {
        // QMessageBox::critical(nullptr, "Error", "TableView is not initialized!");
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("TABLEVIEW IS NOT INITIALIZED");

        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

        return;
    }

    // Set model to tableView
    ui->tableView->setModel(model);

    // Resize columns to fit content
    ui-> tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();

    // Enable alternating row colors for better visibility
    ui->tableView->setAlternatingRowColors(true);

    // Stretch last column to fit better
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    ui->tableView->setSortingEnabled(true);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set grid style for a clean look
    ui->tableView->setStyleSheet("QTableView { gridline-color: Black; }");

    // Hide vertical header (optional, for cleaner UI)
    // ui-> tableView->verticalHeader()->setVisible(false);


    ui->tableView->setFont(QFont("Times New Roman", 10));

    // Debugging: Print row count
    //qDebug() << "Rows Retrieved:" << model->rowCount();

    // Show success message
    // QMessageBox::information(nullptr, "Success", "Data retrieved and displayed successfully!");
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("ERROR");
    msgBox.setText("SUCESS, DATA RETRIEVED AND DISPLAYED SUCESFULLY");

    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;

}

void Studentattendanceview::on_pushButton_5_clicked()
{
    MainWindow *Home=new MainWindow();
    Home->show();
    this->hide();
}

/*
void Studentattendanceview::on_pushButton_4_clicked()
{
    StudentWindow *back=new StudentWindow();
    back->show();
    this->hide();
}*/





/*void Studentattendanceview::on_comboBox_currentTextChanged(const QString &arg1)
{

}


void Studentattendanceview::on_tableView_activated(const QModelIndex &index)
{

}
*/


void Studentattendanceview::days()
{
    ui->comboBox_4->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});
}


void Studentattendanceview::populatecombo2()
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


void Studentattendanceview::on_pushButton_4_clicked()
{
    MainWindow *main=new MainWindow();
    main->show();
    this->hide();

}


void Studentattendanceview::on_pushButton_6_clicked()
{

    qDebug() << "Submit button clicked!";
    fetchdata();
    qDebug() << "Fetch data executed!";
    this->show();
    qDebug() << "Window Visibility: " << this->isVisible();
    fetchdata();
      this->raise(); // Brings the window to the front
    this->activateWindow();

}

