#include "routinewindow.h"
#include "ui_routinewindow.h"
#include"mainwindow.h"
#include"adminwindow.h"
#include<qmessagebox.h>
#include"QMessageBox"
#include<Qstring>
#include<QPixmap>
#include<QPalette>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>

RoutineWindow::RoutineWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoutineWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../../DATABASE/FACULTY.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database: " + db.lastError().text());
    }

    connect(ui->ok, &QPushButton::clicked, this, &RoutineWindow::on_ok_clicked);
    connect(ui->back1, &QPushButton::clicked, this, &RoutineWindow::on_back1_clicked);
    connect(ui->Save, &QPushButton::clicked, this, &RoutineWindow::on_Save_clicked);
    connect(ui->back4, &QPushButton::clicked, this, &RoutineWindow::on_back4_clicked);
    connect(ui->show, &QPushButton::clicked, this, &RoutineWindow::on_show_clicked);
    connect(ui->load1, &QPushButton::clicked, this, &RoutineWindow::on_load1_clicked);
     connect(ui->Load, &QPushButton::clicked, this, &RoutineWindow::on_Load_clicked);
     connect(ui->back4_2, &QPushButton::clicked, this, &RoutineWindow::on_back4_2_clicked);
       connect(ui->del, &QPushButton::clicked, this, &RoutineWindow::on_del_clicked);
}

RoutineWindow::~RoutineWindow()
{
    delete ui;

}

void RoutineWindow::on_home_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void RoutineWindow::on_back_clicked()
{
    AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
}

void RoutineWindow::on_home4_2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void RoutineWindow::on_ok_clicked()
{
    if(ui->radioButton->isChecked()){
            ui->stackedWidget->setCurrentIndex(1);
    }
    if(ui->radioButton_2->isChecked()){
        ui->stackedWidget->setCurrentIndex(2);
    }
    if(ui->radioButton_3->isChecked()){
            ui->stackedWidget->setCurrentIndex(3);
    }
    if(ui->radioButton_4->isChecked()){
            ui->stackedWidget->setCurrentIndex(4);
    }
}


void RoutineWindow::on_back1_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
void RoutineWindow::on_back4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void RoutineWindow::on_back4_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void RoutineWindow::on_home1_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}
void RoutineWindow::on_home4_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void RoutineWindow::on_Load_clicked()
{
    // Clear the combobox to avoid duplicate entries
    ui->comboBox->clear();

    // Prepare a query to fetch all Teacher_IDs
    QSqlQuery qry;
    qry.prepare("SELECT Name FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Teacher_ID and add it to the combobox
            QString name = qry.value(0).toString();
            ui->comboBox->addItem(name);
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve Teacher IDs: " + qry.lastError().text());
    }
}


void RoutineWindow::on_Save_clicked()
{
    QString name;
    QString subject;
    QString day;
    QString class_time;


    name=ui->comboBox->currentText();
    subject=ui->comboBox_2->currentText();
    day = ui->comboBox_3->currentText();
    class_time=ui->lineEdit->text();
     if (subject=="Not_Selected" ){
        QMessageBox::warning(this, "Input Error", "Please Select Subject.");
        return;
    }

    else if (day=="Not_Selected" ){
         QMessageBox::warning(this, "Input Error", "Please Select Day.");
         return;
     }
    else if (class_time.isEmpty()){
        QMessageBox::warning(this, "Input Error", "Please Select Class Time.");
        return;
    }
     QSqlQuery checkQuery;
     checkQuery.prepare("SELECT COUNT(*) FROM teacher_data WHERE Name = :name AND Subject = :subject");
     checkQuery.bindValue(":name", name);
     checkQuery.bindValue(":subject", subject);

     if (checkQuery.exec() && checkQuery.next()) {
         int count = checkQuery.value(0).toInt();
         if (count == 0) {
             QMessageBox::warning(this, "Validation Error", "The entered Name and Subject do not match any records in the database.");
             return;
         }
     } else {
         QMessageBox::critical(this, "Database Error", "Failed to validate Name and Subject: " + checkQuery.lastError().text());
         return;
     }

     // Check for conflicting day and class time
     QSqlQuery conflictCheckQuery;
     conflictCheckQuery.prepare("SELECT COUNT(*) FROM routine WHERE Day = :day AND Class_Time = :class_time");
     conflictCheckQuery.bindValue(":day", day);
     conflictCheckQuery.bindValue(":class_time", class_time);

     if (conflictCheckQuery.exec() && conflictCheckQuery.next()) {
         int count = conflictCheckQuery.value(0).toInt();
         if (count > 0) {
             QMessageBox::warning(this, "Conflict", "This Day and Class Time combination is already occupied.");
             return;
         }
     } else {
         QMessageBox::critical(this, "Database Error", "Failed to check for schedule conflicts: " + conflictCheckQuery.lastError().text());
         return;
     }
    //checking Teacher name and Day
     QSqlQuery checkquyredata;
     checkquyredata.prepare("SELECT COUNT(*) FROM routine WHERE Day = :day AND Teacher_Name = :name");
     checkquyredata.bindValue(":day", day);
     checkquyredata.bindValue(":name", name);

     if (checkquyredata.exec() && checkquyredata.next()) {
         int count = checkquyredata.value(0).toInt();
         if (count > 0) {
             QMessageBox::warning(this, "Conflict", name+"has class on "+day);
             return;
         }
     } else {
         QMessageBox::critical(this, "Database Error", "Failed to check for schedule conflicts: " + checkquyredata.lastError().text());
         return;
     }

    // Prepare the SQL query for insertion
    QSqlQuery insertqry;
    insertqry.prepare("INSERT INTO routine (Teacher_Name, Subject,Day,Class_Time) "
                "VALUES (:name, :subject, :day, :class_time)");
    insertqry.bindValue(":name", name);
    insertqry.bindValue(":subject", subject);
    insertqry.bindValue(":day",day );
    insertqry.bindValue(":class_time", class_time);
    // Execute the query and check for success
    if (insertqry.exec()) {
        QMessageBox::information(this, "Success", "Teacher information saved successfully.");

    } else {
        QMessageBox::critical(this, "Database Error", "Failed to save teacher information: " + insertqry.lastError().text());
    }
}

void RoutineWindow::on_show_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("routine");
    model->select();  // Fetch the data from the database

    // Set the model for the QTableView
    ui->tableView->setModel(model);

    // Optional: Customize the table view (e.g., hiding certain columns)
    model->setHeaderData(0, Qt::Horizontal, "Teacher Name");
    model->setHeaderData(1, Qt::Horizontal, "Subject");
    model->setHeaderData(2, Qt::Horizontal, "Day");
    model->setHeaderData(3, Qt::Horizontal, "Class Time");
    // Adjust the view's presentation
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
}





void RoutineWindow::on_load1_clicked()
{
    // Clear the combobox to avoid duplicate entries
    ui->comboBox_4->clear();

    // Prepare a query to fetch all Teacher name
    QSqlQuery qry;
    qry.prepare("SELECT Teacher_Name FROM routine");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each teacher name and add it to the combobox
            QString name = qry.value(0).toString();
            ui->comboBox_4->addItem(name);
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve Teacher IDs: " + qry.lastError().text());
    }
}




void RoutineWindow::on_del_clicked()
{
    // Get the selected name from the combobox
    QString name = ui->comboBox_4->currentText();

    // Check if a valid name is selected
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select a valid name to delete.");
        return;
    }

    // Confirm deletion with the user
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Confirmation",
        "Are you sure you want to delete  " + name +  "routine"+ "?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return; // User canceled the deletion
    }

    // Prepare the SQL query to delete the teacher record
    QSqlQuery qry;
    qry.prepare("DELETE FROM routine WHERE Teacher_Name = :name");
    qry.bindValue(":name", name);

    // Execute the query
    if (qry.exec()) {
        QMessageBox::information(this, "Success", "Teacher record deleted successfully.");

        // Refresh the combobox to reflect changes
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to delete the teacher record: " + qry.lastError().text());
    }
}

