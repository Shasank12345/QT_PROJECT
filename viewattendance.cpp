#include "viewattendance.h"
#include "ui_viewattendance.h"
#include<QMessageBox>
#include"qmessagebox.h"

VIEWATTENDANCE::VIEWATTENDANCE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VIEWATTENDANCE)
{
    ui->setupUi(this);
}

void VIEWATTENDANCE::populatecombo1()
{
    QSqlQuery query;
    if (query.exec("SELECT Subject FROM Teacher_data")) {
        while (query.next()) {
            ui->comboBox->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Error loading data:" << query.lastError().text();
    }
}

void VIEWATTENDANCE::populatecombo2()
{
    ui->comboBox_3->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});
}



VIEWATTENDANCE::~VIEWATTENDANCE()
{
    delete ui;
}

void VIEWATTENDANCE::fetchdata()
{
    QString subject=ui->comboBox->currentText().trimmed();
    QString day=ui->comboBox_3->currentText().trimmed();
    QString date=ui->dateEdit->date().toString("yyyy-MM-dd");
    if (subject.isEmpty() || day.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "Please select Subject, Day, and Date.");
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(QSqlDatabase::database());

    // Prepare SQL query with the correct number of placeholders
    QString sql = "SELECT STUDENT_ID,STUDENT_NAME,STATUS FROM ATTENDANCE WHERE SUBJECT = ? AND DAY = ? AND DATE= ?";
    query.prepare(sql);

    query.addBindValue(subject);
    query.addBindValue(day);
    query.addBindValue(date);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Query Error", "Failed to execute query: " + query.lastError().text());
        qDebug() << "Query Error:" << query.lastError().text();
        return;
    }
    else{
        QMessageBox::information(nullptr, "Query Sucess", "SUCESFULLY EXECUTED QUERY");

    }
    model->setQuery(query);

    // Debugging: Check if data exists
    if (model->rowCount() == 0) {
        QMessageBox::warning(nullptr, "No Data", "No records found for the selected criteria.");
        qDebug() << "No data found!";
        return;
    }

    // Set column headers

    model->setHeaderData(0, Qt::Horizontal, "STUDENT_ID");
    model->setHeaderData(1, Qt::Horizontal, "STUDENT_NAME");
    model->setHeaderData(2, Qt::Horizontal, "STATUS");
    //model->setHeaderData(3, Qt::Horizontal, "Subject");


    // Ensure tableView is not NULL
    if (!ui->tableView) {
        QMessageBox::critical(nullptr, "Error", "TableView is not initialized!");
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
    QMessageBox::information(nullptr, "Success", "Data retrieved and displayed successfully!");
}




void VIEWATTENDANCE::on_pushButton_clicked()
{
    fetchdata();



}


void VIEWATTENDANCE::on_pushButton_3_clicked()
{
    main->show();
    this->hide();

}


void VIEWATTENDANCE::on_pushButton_2_clicked()
{
    take->show();
    this->hide();
}

