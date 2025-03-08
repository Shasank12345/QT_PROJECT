#include "routinewindow.h"
#include "ui_routinewindow.h"
#include"adminwindow.h"
#include"add_routine.h"
#include <QDebug>
#include"deleteroutine.h"
#include"editroutine.h"
#include"qmessagebox.h"
#include <QSqlTableModel>
#include <QWidget>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<Qstring>
#include<QPixmap>
#include<QPalette>
RoutineWindow::RoutineWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoutineWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &RoutineWindow::on_pushButton_2_clicked);
     connect(ui->pushButton_5, &QPushButton::clicked, this, &RoutineWindow::on_pushButton_5_clicked);
}

RoutineWindow::~RoutineWindow()
{
    delete ui;

}

void RoutineWindow::on_home_clicked()
{

    mainWindow->show();
    this->hide();
}


void RoutineWindow::on_back_clicked()
{
    AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
    this->hide();
}



void RoutineWindow::on_pushButton_clicked()
{
    Add_routine *add =new Add_routine();
    add->show();
    add->adddata();
    add->day();

    this->hide();
}


void RoutineWindow::on_pushButton_3_clicked()
{
    deleteroutine *del = new deleteroutine();
     del->show();
   // del->adddata();
    del->day();

    this->hide();
}




void RoutineWindow::on_pushButton_4_clicked()
{
    EditRoutine *edit= new EditRoutine();
    edit->show();
    edit->popu();
      this->hide();
}



void RoutineWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void RoutineWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void RoutineWindow::on_pushButton_6_clicked()
{
    mainWindow->show();
    this->hide();
}


void RoutineWindow::on_pushButton_7_clicked()
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

