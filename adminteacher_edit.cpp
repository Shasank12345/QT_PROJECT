#include "adminteacher_edit.h"
#include "ui_adminteacher_edit.h"
#include"mainwindow.h"
#include"adminwindow.h"
#include<Qstring>
#include<QPixmap>
#include<QPalette>
#include <QSqlTableModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>
#include"QMessageBox"
#include<qmessagebox.h>

AdminTeacher_Edit::AdminTeacher_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminTeacher_Edit)
{
    ui->setupUi(this);
    connect(ui->Edit, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Edit_clicked);
    connect(ui->Delet, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Delet_clicked);
    connect(ui->addback, &QPushButton::clicked, this, &AdminTeacher_Edit::on_addback_clicked);
    connect(ui->editback, &QPushButton::clicked, this, &AdminTeacher_Edit::on_editback_clicked);
    connect(ui->deletback, &QPushButton::clicked, this, &AdminTeacher_Edit::on_deletback_clicked);
    connect(ui->add, &QPushButton::clicked, this, &AdminTeacher_Edit::on_add_clicked);
    connect(ui->View, &QPushButton::clicked, this, &AdminTeacher_Edit::on_View_clicked);
    connect(ui->show, &QPushButton::clicked, this, &AdminTeacher_Edit::on_show_clicked);
    connect(ui->viewback, &QPushButton::clicked, this, &AdminTeacher_Edit::on_viewback_clicked);
    connect(ui->save, &QPushButton::clicked, this, &AdminTeacher_Edit::on_save_clicked);
    connect(ui->view5, &QPushButton::clicked, this, &AdminTeacher_Edit::on_view5_clicked);
    connect(ui->delet, &QPushButton::clicked, this, &AdminTeacher_Edit::on_delet_clicked);
    connect(ui->back5, &QPushButton::clicked, this, &AdminTeacher_Edit::on_back5_clicked);
    connect(ui->ok, &QPushButton::clicked, this, &AdminTeacher_Edit::on_ok_clicked);
    connect(ui->editback_2, &QPushButton::clicked, this, &AdminTeacher_Edit::on_editback_2_clicked);
    connect(ui->editback_3, &QPushButton::clicked, this, &AdminTeacher_Edit::on_editback_3_clicked);
    connect(ui->back5_2, &QPushButton::clicked, this, &AdminTeacher_Edit::on_back5_2_clicked);
    connect(ui->Edit5, &QPushButton::clicked, this, &AdminTeacher_Edit::on_Edit5_clicked);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName("../../DATABASE/FACULTY.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database: " + db.lastError().text());
    }
}

AdminTeacher_Edit::~AdminTeacher_Edit()
{
    delete ui;
}


void AdminTeacher_Edit::on_editback_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void AdminTeacher_Edit::on_Edit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void AdminTeacher_Edit::on_Delet_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}



void AdminTeacher_Edit::on_editback_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_addback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void AdminTeacher_Edit::on_deletback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void AdminTeacher_Edit::on_home0_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

void AdminTeacher_Edit::on_View_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void AdminTeacher_Edit::on_back_clicked()
{
    AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
}


void AdminTeacher_Edit::on_add_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void AdminTeacher_Edit::on_home1_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void AdminTeacher_Edit::on_home2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

void AdminTeacher_Edit::on_home4_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void AdminTeacher_Edit::on_viewback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void AdminTeacher_Edit::on_back5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void AdminTeacher_Edit::on_back5_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void AdminTeacher_Edit::on_home3_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}
void AdminTeacher_Edit::on_home5_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

void AdminTeacher_Edit::on_home2_2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

void AdminTeacher_Edit::on_home2_3_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}
void AdminTeacher_Edit::on_home5_2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}

void AdminTeacher_Edit::on_save_clicked()
{
    QString name;
    QString email;
    QString teacher_id;
    QString phn_no;
    QString subject;

    name=ui->lineEdit_16->text();
    email=ui->lineEdit_33->text();
    teacher_id = ui->lineEdit_31->text();
    phn_no=ui->lineEdit_32->text();
    subject=ui->comboBox->currentText();
    if (name.isEmpty() ){
        QMessageBox::warning(this, "Input Error", "Please enter Name.");
        return;
    }
    else if (email.isEmpty() ){
        QMessageBox::warning(this, "Input Error", "Please enter Email.");
        return;
    }
    else if (teacher_id.isEmpty() ){
        QMessageBox::warning(this, "Input Error", "Please enter Teacher Id.");
        return;
    }
    else if (phn_no.isEmpty() ){
        QMessageBox::warning(this, "Input Error", "Please enter Phone Number.");
        return;
    }
    else if (subject=="Not_Selected" ){
        QMessageBox::warning(this, "Input Error", "Please Select Subject.");
        return;
    }

    // Prepare the SQL query for insertion
    QSqlQuery qry;
    qry.prepare("INSERT INTO Teacher_data (Name, Teacher_ID, Phone_Number, Email,Subject) "
                "VALUES (:name, :teacher_id, :phn_no, :email,:subject)");
    qry.bindValue(":name", name);
    qry.bindValue(":teacher_id", teacher_id);
    qry.bindValue(":phn_no", phn_no);
    qry.bindValue(":email", email);
     qry.bindValue(":subject", subject);
    // Execute the query and check for success
    if (qry.exec()) {
        QMessageBox::information(this, "Success", "Teacher information saved successfully.");

        // Clear the input fields after saving
        ui->lineEdit_16->clear();
        ui->lineEdit_33->clear();
        ui->lineEdit_31->clear();
        ui->lineEdit_32->clear();
        ui->comboBox->clearEditText();
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to save teacher information: " + qry.lastError().text());
    }
}







void AdminTeacher_Edit::on_edit_clicked()
{
    QString name;
    QString teacher_id;


    name=ui->lineEdit_17->text();
    teacher_id = ui->lineEdit_36->text();


    QSqlQuery qry;

    // Check if a record with the same Teacher_ID, Phone_Number, or Email exists
    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + qry.lastError().text());
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE teacher_data SET Name = :name WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":name", name);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox::information(this, "Success", "Name updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Failed", "Could not update the record: " + qry.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "No Match Found", "No record found with the given Teacher ID, Phone Number, or Email.");
    }


}









void AdminTeacher_Edit::on_show_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("Teacher_data");
    model->select();  // Fetch the data from the database

    // Set the model for the QTableView
    ui->tableView->setModel(model);

    // Optional: Customize the table view (e.g., hiding certain columns)
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Teacher ID");
    model->setHeaderData(2, Qt::Horizontal, "Phone Number");
    model->setHeaderData(3, Qt::Horizontal, "Email");
     model->setHeaderData(4, Qt::Horizontal, "Subject");
    // Adjust the view's presentation
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();


}
void AdminTeacher_Edit::on_view5_clicked()
{
    // Clear the combobox to avoid duplicate entries
    ui->comboBox1->clear();

    // Prepare a query to fetch all Teacher_IDs
    QSqlQuery qry;
    qry.prepare("SELECT Teacher_ID FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Teacher_ID and add it to the combobox
            QString teacher_id = qry.value(0).toString();
            ui->comboBox1->addItem(teacher_id);
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve Teacher IDs: " + qry.lastError().text());
    }
}





void AdminTeacher_Edit::on_delet_clicked()
{

    // Get the selected Teacher_ID from the combobox
    QString teacher_id = ui->comboBox1->currentText();

    // Check if a valid Teacher_ID is selected
    if (teacher_id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select a valid Teacher ID to delete.");
        return;
    }

    // Confirm deletion with the user
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Confirmation",
        "Are you sure you want to delete Teacher ID: " + teacher_id + "?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return; // User canceled the deletion
    }

    // Prepare the SQL query to delete the teacher record
    QSqlQuery qry;
    qry.prepare("DELETE FROM teacher_data WHERE Teacher_ID = :teacher_id");
    qry.bindValue(":teacher_id", teacher_id);

    // Execute the query
    if (qry.exec()) {
        QMessageBox::information(this, "Success", "Teacher record deleted successfully.");

        // Refresh the combobox to reflect changes
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to delete the teacher record: " + qry.lastError().text());
    }
}





void AdminTeacher_Edit::on_show_id_clicked()
{
    // Clear the combobox to avoid duplicate entries
    ui->comboBox2->clear();

    // Prepare a query to fetch all Teacher_IDs
    QSqlQuery qry;
    qry.prepare("SELECT Teacher_ID FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Teacher_ID and add it to the combobox
            QString teacher_id = qry.value(0).toString();
            ui->comboBox2->addItem(teacher_id);
        }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve Teacher IDs: " + qry.lastError().text());
    }
}

void AdminTeacher_Edit::on_ok_clicked()
{
    // Get the selected Teacher_ID from comboBox2
    QString selectedTeacherId = ui->comboBox2->currentText();
     QString select = ui->comboBox3->currentText();
    // Check if a valid Teacher_ID is selected
    if (selectedTeacherId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select a valid Teacher ID.");
        return;
    }
    if(select=="Not_Selected")
    {
        QMessageBox::warning(this, "Not Selected", "Please select ");
    }
    if(select=="Name")
    {
    // Set the selected Teacher_ID to the teacher_id field in the edit section
    ui->lineEdit_36->setText(selectedTeacherId);

    // Switch to the edit section
    ui->stackedWidget->setCurrentIndex(3);
    }

    if(select=="Email")
    {
        // Set the selected Teacher_ID to the teacher_id field in the edit section
        ui->lineEdit_37->setText(selectedTeacherId);

        // Switch to the edit section
        ui->stackedWidget->setCurrentIndex(4);
    }

    if(select=="Phone_Number")
    {
        // Set the selected Teacher_ID to the teacher_id field in the edit section
        ui->lineEdit_38->setText(selectedTeacherId);

        // Switch to the edit section
        ui->stackedWidget->setCurrentIndex(5);
    }
    if(select=="Subject")
    {
        // Set the selected Teacher_ID to the teacher_id field in the edit section
        ui->lineEdit->setText(selectedTeacherId);

        // Switch to the edit section
        ui->stackedWidget->setCurrentIndex(6);
    }
}


void AdminTeacher_Edit::on_edit_2_clicked()
{
    QString email;
    QString teacher_id;


    email=ui->lineEdit_18->text();
    teacher_id = ui->lineEdit_37->text();


    QSqlQuery qry;

    // Check if a record with the same Teacher_ID
    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + qry.lastError().text());
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE teacher_data SET Email= :email WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":email", email);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox::information(this, "Success", "Email updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Failed", "Could not update the record: " + qry.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "No Match Found", "No record found with the given Teacher ID, Phone Number, or Email.");
    }
}


void AdminTeacher_Edit::on_edit_3_clicked()
{
    QString phn_no;
    QString teacher_id;


    phn_no=ui->lineEdit_19->text();
    teacher_id = ui->lineEdit_38->text();


    QSqlQuery qry;

    // Check if a record with the same Teacher_ID
    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + qry.lastError().text());
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE teacher_data SET Phone_NUmber = :phn_no WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":phn_no", phn_no);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox::information(this, "Success", "Phone Number updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Failed", "Could not update the record: " + qry.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "No Match Found", "No record found with the given Teacher ID, Phone Number, or Email.");
    }
}






void AdminTeacher_Edit::on_Edit5_clicked()
{
    QString subject;
    QString teacher_id;


    subject=ui->comboBox_3->currentText();
    teacher_id = ui->lineEdit->text();


    QSqlQuery qry;

    // Check if a record with the same Teacher_ID,
    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + qry.lastError().text());
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE teacher_data SET Subject = :subject WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":subject", subject);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox::information(this, "Success", "Subject updated successfully.");
        } else {
            QMessageBox::warning(this, "Update Failed", "Could not update the record: " + qry.lastError().text());
        }
    } else {
        QMessageBox::warning(this, "No Match Found", "No record found with the given Teacher ID, Phone Number, or Email.");
    }
}

