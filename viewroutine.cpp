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
#include <QVBoxLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>

VIEWROUTINE::VIEWROUTINE(QString t,QString s,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VIEWROUTINE)
    ,teacher(t)
    ,Subject(s)

{
    ui->setupUi(this);
    this->setWindowTitle("ROUTINE OF "+Subject);
    this->setFixedSize(this->size());
    qDebug()<<Subject;
}

void VIEWROUTINE::day()
{
    ui->comboBox_3->addItems({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"});
}


VIEWROUTINE::~VIEWROUTINE()
{
    delete ui;
}








void VIEWROUTINE::on_pushButton_clicked()
{


    QString day;
    QString s=Subject.trimmed();
    qDebug()<<s;

    day=ui->comboBox_3->currentText().trimmed();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(QSqlDatabase::database());

    // Prepare SQL query with the correct number of placeholders
    QString sql = "SELECT Teacher_Name,Subject,Class_start,Class_end FROM routine WHERE DAY = ? ";
    query.prepare(sql);
    //query.addBindValue(s);
    query.addBindValue(day);

    if (!query.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to execute query: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    model->setQuery(query);

    // Debugging: Check if data exists
    if (model->rowCount() == 0) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("No Data");
        msgBox.setText("No records found for the selected criteria.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
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



    ui->tableView->setFont(QFont("Times New Roman", 10));


    // Show success message
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("  Success");
    msgBox.setText("Data retrieved and displayed successfully!");
    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;


}

void VIEWROUTINE::on_pushButton_3_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->hide();
}


void VIEWROUTINE::on_pushButton_2_clicked()
{
    qDebug()<<"BACK CLIICKED";
    if (QWidget *parent = this->parentWidget()) {
        parent->show();
    }
    this->hide();
}

