#include "viewroutine.h"
#include "ui_viewroutine.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include"qmessagebox.h"
#include"mainwindow.h"
#include<Qstring>
#include<QPixmap>
#include<QPalette>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>

VIEWROUTINE::VIEWROUTINE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VIEWROUTINE)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

void VIEWROUTINE::day()
{
    ui->comboBox_3->addItems({"Sunday", "Monday", "Tuseday", "Wednesday", "Thrusday", "Friday"});
}


VIEWROUTINE::~VIEWROUTINE()
{
    delete ui;
}








void VIEWROUTINE::on_pushButton_clicked()
{
    QString day;
    day=ui->comboBox_3->currentText().trimmed();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(QSqlDatabase::database());

    // Prepare SQL query with the correct number of placeholders
    QString sql = "SELECT Teacher_Name,Subject,Class_start,Class_end FROM routine WHERE  DAY = ? ";
    query.prepare(sql);

    query.addBindValue(day);

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

    model->setHeaderData(0, Qt::Horizontal, "Teacher_Name");
    model->setHeaderData(1, Qt::Horizontal, "Subject");
    model->setHeaderData(2, Qt::Horizontal, "Class_start");
    model->setHeaderData(3, Qt::Horizontal, "Class_end");

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


void VIEWROUTINE::on_pushButton_3_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->hide();
}

