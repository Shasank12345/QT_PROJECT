#include "adminstudent_edit.h"
#include "ui_adminstudent_edit.h"
#include "mainwindow.h"
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

AdminStudent_Edit::AdminStudent_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminStudent_Edit)
{
    ui->setupUi(this);

}

AdminStudent_Edit::~AdminStudent_Edit()
{
    delete ui;
}

void AdminStudent_Edit::on_add_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void AdminStudent_Edit::on_view_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void AdminStudent_Edit::on_edit_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    populatecombo();
}



void AdminStudent_Edit::on_delet_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    populatecombo1();

}



void AdminStudent_Edit::on_back1_clicked()
{
    AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
    this->hide();

}


void AdminStudent_Edit::on_home1_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}


void AdminStudent_Edit::on_back2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void AdminStudent_Edit::on_home2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}



void AdminStudent_Edit::on_back3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_home3_2_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}



void AdminStudent_Edit::on_back3_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_home4_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}



void AdminStudent_Edit::on_back4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void AdminStudent_Edit::on_home5_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}


void AdminStudent_Edit::on_back5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_home6_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}



void AdminStudent_Edit::on_bak6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_home7_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
}


void AdminStudent_Edit::on_back7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_home11_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}


void AdminStudent_Edit::on_back8_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void AdminStudent_Edit::on_home9_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();

}




void AdminStudent_Edit::on_back9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void AdminStudent_Edit::on_home10_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}

void AdminStudent_Edit::populatecombo()
{
    ui->comboBox_2->clear();

    // Prepare a query to fetch all Student_IDs
    QSqlQuery qry;
    qry.prepare("SELECT Student_id FROM STUDENT_ENTRY");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Student_ID and add it to the combobox
            QString Student_id = qry.value(0).toString();
            ui->comboBox_2->addItem(Student_id);
        }
    } else {


        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Student IDs: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}

void AdminStudent_Edit::populatecombo1()
{
    ui->comboBox1->clear();

    // Prepare a query to fetch all Student_IDs
    QSqlQuery qry;
    qry.prepare("SELECT Student_id FROM STUDENT_ENTRY");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Student_ID and add it to the combobox
            QString Student_id = qry.value(0).toString();
            ui->comboBox1->addItem(Student_id);
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Student IDs: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

}

void AdminStudent_Edit::email(QString a)
{
    QString id = a;
    ui->lineEdit_17->clear();
    QSqlQuery query;
    query.prepare("SELECT Email FROM STUDENT_ENTRY WHERE Student_id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Email = query.value(0).toString();
            ui->lineEdit_17->setText(Email); // Replace with your widget for displaying Email
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Not found");
            msgBox.setText("No email found for the given student: ");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Email: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }
}
        void AdminStudent_Edit ::oldpassword(QString a)
    {
        QString id = a;
        ui->lineEdit102->clear();
        QSqlQuery query;
        query.prepare("SELECT PASSWORD FROM LOGINSTUDENT WHERE ID = :id");
        query.bindValue(":id", id);

        if (query.exec()) {
            if (query.next()) {
                QString pass = query.value(0).toString();
                ui->lineEdit102->setText(pass);
            } else {
                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setWindowTitle("Not Found");
                msgBox.setText("No Password found for the given student ID.");
                msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
                msgBox.exec();
                return;
            }
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Database Error");
            msgBox.setText("Failed to retrieve Password: " + query.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    }


void AdminStudent_Edit :: phn(QString a)
{
    QString id = a;
    ui->lineEdit_11->clear();
    QSqlQuery query;
    query.prepare("SELECT Contact_no FROM STUDENT_ENTRY WHERE Student_id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Contact_no = query.value(0).toString();
            ui->lineEdit_11->setText(Contact_no); // Replace with your widget for displaying Contact_no
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Not found");
            msgBox.setText("No contact found for the given student: ");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrive contact number:"+query.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void AdminStudent_Edit :: address(QString a)
{
    QString id = a;
    ui->lineEdit_13->clear();
    QSqlQuery query;
    query.prepare("SELECT Address FROM STUDENT_ENTRY WHERE Student_id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Address = query.value(0).toString();
            ui->lineEdit_13->setText(Address); // Replace with your widget for displaying Address
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Not found");
            msgBox.setText("No address found for the given studdent:");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrive address:"+query.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }
}

void AdminStudent_Edit::on_save1_clicked()
{

    QString name;
    QString email;
    QString student_id;
    QString phn_no;
    QString dept;
    QString address;
    QString password;

    name=ui->lineEdit->text();
    email=ui->lineEdit_3->text();
    student_id = ui->lineEdit_2->text();
    phn_no=ui->lineEdit_5->text();
    address=ui->lineEdit_4->text();
    password=ui->lineEdit_19->text();
    QString id=student_id;
    QString EMAIL=email;
    if (name.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter name:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (email.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter email:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (student_id.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter Student Id:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (phn_no.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please phone number:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    if (phn_no.length() != 10 ) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter valid  number:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (address.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter address:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if(password.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please enter password:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    // Prepare the SQL query for insertion
    QSqlQuery qry;
    qry.prepare("INSERT INTO STUDENT_ENTRY (Student_id,Name,Address,Contact_no,Email) "
                "VALUES (:student_id, :name, :address, :phn_no,:email)");
    qry.bindValue(":name", name);
    qry.bindValue(":student_id", student_id);
    qry.bindValue(":phn_no", phn_no);
    qry.bindValue(":email", email);
    qry.bindValue(":address", address);
    // Execute the query and check for success



        // Clear the input fields after saving
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_19->clear();

    QSqlQuery q;
    q.prepare("INSERT INTO LOGINSTUDENT (EMAIL, PASSWORD,ID)"
              "VALUES(:EMAIL, :password,:id)");
    q.bindValue(":EMAIL", EMAIL);
    q.bindValue(":password", password);
    q.bindValue(":id", id);
    if(q.exec()&& qry.exec()){


        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Success");
        msgBox.setText("Student information saved successfully on both tables:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    } else {
        QMessageBox::critical(this, "Database Error", "Failed to save student information: " + qry.lastError().text());

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Database error");
        msgBox.setText("failed to save student information save on both tables:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

}







void AdminStudent_Edit::on_view1_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("STUDENT_ENTRY");
    model->select();  // Fetch the data from the database

    // Set the model for the QTableView
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "STUDENT ID");
    model->setHeaderData(1, Qt::Horizontal, "NAME");
    model->setHeaderData(2, Qt::Horizontal, "ADDRESS");
    model->setHeaderData(3, Qt::Horizontal, "CONTACT N0");
    model->setHeaderData(4, Qt::Horizontal, "EMAIL");
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
}

void AdminStudent_Edit::on_summit_clicked()
{
    QString choose;
    QString id;
    QString name;
    name=ui->lineEdit_6->text();
    id=ui->comboBox_2->currentText();
    choose=ui->comboBox->currentText();
    if (choose=="NOT SELECTED")
    {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("input Error");
        msgBox.setText("please select what do you want to edit:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }
    if(choose=="NAME")
    {   ui->lineEdit_7->clear();
        ui->lineEdit_8->setText(id);
        ui->lineEdit_9->setText(name);
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(choose=="ADDRESS")
    {   ui->lineEdit_23->clear();
        ui->lineEdit_22->setText(id);
        ui->lineEdit_12->setText(name);
         address(id);
        ui->stackedWidget->setCurrentIndex(6);
    }
    else if(choose=="CONTACT NUMBER")
    {    ui->lineEdit_16->clear();
        ui->lineEdit_15->setText(id);
        ui->lineEdit_10->setText(name);
         phn(id);
        ui->stackedWidget->setCurrentIndex(5);
    }

    else if(choose=="EMAIL")
    {   ui->lineEdit_27->clear();
        ui->lineEdit_26->setText(id);
        ui->lineEdit_14->setText(name);
         email(id);
        ui->stackedWidget->setCurrentIndex(7);
    }
    if(choose=="PASSWORD")
    {
        ui->lineEdit102->clear();
        ui->LINEEDIT100->setText(id);
        ui->lineEdit101->setText(name);
        oldpassword(id);
        ui->stackedWidget->setCurrentIndex(9);
    }

}


void AdminStudent_Edit::on_save2_clicked()
{
    QString name;
    QString student_id;

    name = ui->lineEdit_7->text();
    student_id = ui->lineEdit_8->text();


    QSqlQuery qry;

    // Check if a record with the same student_id
    qry.prepare("SELECT * FROM STUDENT_ENTRY WHERE Student_id = :student_id ");
    qry.bindValue(":student_id", student_id);


    if (!qry.exec()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to execute query:"+qry.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE STUDENT_ENTRY SET Name = :name WHERE Student_id = :student_id");
        qry.bindValue(":name", name);
        qry.bindValue(":student_id", student_id);


        if (qry.exec()) {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Success");
            msgBox.setText("Name updated successfully:");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Update failed");
            msgBox.setText("could not update the record:"+qry.lastError().text() );
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("No match found");
        msgBox.setText("No record found with the given student id.:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void AdminStudent_Edit::on_save3_clicked()
{
    QString contact;
    QString student_id;

    contact = ui->lineEdit_16->text();
    student_id = ui->lineEdit_15->text();


    if (contact.length() == 10 ) {

        QSqlQuery qry;

        // Check if a record with the same student_id
        qry.prepare("SELECT * FROM STUDENT_ENTRY WHERE Student_id = :student_id ");
        qry.bindValue(":student_id", student_id);


        if (!qry.exec()) {


            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Database Error");
            msgBox.setText("Failed to execute query:"+qry.lastError().text() );
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        if (qry.next()) {
            // Update the existing record
            qry.prepare("UPDATE STUDENT_ENTRY SET Contact_no = :contact WHERE Student_id = :student_id");
            qry.bindValue(":contact", contact);
            qry.bindValue(":student_id", student_id);


            if (qry.exec()) {

                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setWindowTitle("Success");
                msgBox.setText("Contact updated successfully:");
                msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
                msgBox.exec();
                return;
            } else {

                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setWindowTitle("Update failed");
                msgBox.setText("could not update the record:"+qry.lastError().text() );
                msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
                msgBox.exec();
                return;
            }
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("No match found");
            msgBox.setText("No record found with the given student id.:");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox::warning(this, "Invalid Input", "Contact number must be exactly 10 digits.");
        return;
    }


}




void AdminStudent_Edit::on_save5_clicked()
{
    QString address;
    QString student_id;

    address = ui->lineEdit_23->text();
    student_id = ui->lineEdit_22->text();


    QSqlQuery qry;

    // Check if a record with the same student_id
    qry.prepare("SELECT * FROM STUDENT_ENTRY WHERE Student_id = :student_id ");
    qry.bindValue(":student_id", student_id);


    if (!qry.exec()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to execute query:"+qry.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (qry.next()) {
        // Update the existing record
        qry.prepare("UPDATE STUDENT_ENTRY SET Address = :address WHERE Student_id = :student_id");
        qry.bindValue(":address", address);
        qry.bindValue(":student_id", student_id);


        if (qry.exec()) {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Success");
            msgBox.setText("address updated successfully:");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        } else {

            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Update failed");
            msgBox.setText("couldnot update the record:"+qry.lastError().text() );
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; } ");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("No match found");
        msgBox.setText("No record found with the given student id:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}

void AdminStudent_Edit::on_pushButton_clicked()
{
    QString email = ui->lineEdit_27->text();
    QString student_id = ui->lineEdit_26->text();
    QString id = ui->lineEdit_26->text();

    if (email.isEmpty() ) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please fill the Email.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM STUDENT_ENTRY WHERE Student_id = :student_id");
    qry.bindValue(":student_id", student_id);
    QSqlQuery qry2;
    qry2.prepare("SELECT * FROM LOGINSTUDENT WHERE ID = :id");
    qry2.bindValue(":id", id);

    if (!qry.exec()&&!qry2.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Data Error");
        msgBox.setText("Failed to execute query: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (!qry.next()&&!qry2.next()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Data Error");
        msgBox.setText("No record found with the given Student ID in student_data.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }


    // if (!qry2.exec()) {
    //     QMessageBox msgBox(this);
    //     msgBox.setIcon(QMessageBox::Warning);
    //     msgBox.setWindowTitle("Data Error");
    //     msgBox.setText("Failed to execute query: " + qry2.lastError().text());
    //     msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //     msgBox.exec();
    //     return;
    // }

    // if (!qry2.next()) {
    //     QMessageBox msgBox(this);
    //     msgBox.setIcon(QMessageBox::Warning);
    //     msgBox.setWindowTitle(" No Match Found");
    //     msgBox.setText("No record found with the given ID in LOGINSTUDENT.");
    //     msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //     msgBox.exec();
    //     return;
    // }

    qry.prepare("UPDATE STUDENT_ENTRY SET Email = :email WHERE Student_id = :student_id");
    qry.bindValue(":email", email);
    qry.bindValue(":student_id", student_id);

    if (!qry.exec()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Update Failed");
        msgBox.setText("Could not update the Student_data: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    qry2.prepare("UPDATE LOGINSTUDENT SET EMAIL = :email WHERE ID = :id");
    qry2.bindValue(":email", email);
    qry2.bindValue(":id", id);

    if (!qry2.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Update Failed");
        msgBox.setText("Could not update the student_data: " + qry2.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Success");
    msgBox.setText("Email updated successfully.");
    msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    msgBox.exec();
    return;
}


void AdminStudent_Edit::on_comboBox_2_currentTextChanged(const QString &Student_id)
{
    ui->lineEdit_6->clear();

    // Prepare query to retrieve the teacher name  corresponding to the selected id
    QSqlQuery query;
    query.prepare("SELECT Name FROM STUDENT_ENTRY WHERE Student_id = :Student_id");
    query.bindValue(":Student_id", Student_id);

    if(query.exec()) {
        // If multiple IDs exist (unlikely for unique names), they will all be added
        while(query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_6->setText(Name);
        }
    } else {
        qDebug() << "Error retrieving student ID:" << query.lastError().text();

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to load student Id.:"+query.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void AdminStudent_Edit::on_comboBox1_currentTextChanged(const QString &Student_id)
{
    ui->lineEdit_18->clear();

    // Prepare query to retrieve the teacher name  corresponding to the selected id
    QSqlQuery query;
    query.prepare("SELECT Name FROM STUDENT_ENTRY WHERE Student_id = :Student_id");
    query.bindValue(":Student_id", Student_id);

    if(query.exec()) {
        // If multiple IDs exist (unlikely for unique names), they will all be added
        while(query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_18->setText(Name);
        }
    } else {
        qDebug() << "Error retrieving student ID:" << query.lastError().text();

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to load:"+query.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}





void AdminStudent_Edit::on_home222_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}


void AdminStudent_Edit::on_back99_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_update100_clicked()
{
    QString old;
    QString id;


    old=ui->lineEdit105->text();
    id = ui->LINEEDIT100->text();


    QSqlQuery qry;

    qry.prepare("SELECT * FROM LOGINSTUDENT WHERE ID = :id ");
    qry.bindValue(":id", id);


    if (!qry.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to execute query:  " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (qry.next()) {
        qry.prepare("UPDATE LOGINSTUDENT SET PASSWORD = :old WHERE ID = :id");
        qry.bindValue(":old", old);
        qry.bindValue(":id", id);


        if (qry.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("  Success");
            msgBox.setText("Password updated successfully.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;

        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Update Failed");
            msgBox.setText("Could not update the record:  " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" No Match Found");
        msgBox.setText("No record found with the given STUDENT ID.  " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}

void AdminStudent_Edit::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminStudent_Edit::on_pushButton_4_clicked()
{
    MainWindow *mainWindow =new MainWindow();
    mainWindow->show();
    this->hide();
}

void AdminStudent_Edit::on_delet1_clicked()
{
    QString name=ui->lineEdit_18->text();
    // Get the selected student_id from the combobox
    QString student_id = ui->comboBox1->currentText();
    QString id=student_id;
    // Check if a valid student_id is selected
    if (student_id.isEmpty()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please select a valid student Id to delete:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Delete Confirmation");
    msgBox.setText(QString("Are you sure you want to delete detail of " + name +" ?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);


    msgBox.setStyleSheet(
        "QLabel { color:white; }"
        "QPushButton {color:white; }"
        );

    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());

    if (reply == QMessageBox::No) {
        return;
    }

    // Prepare the SQL query to delete the Student record
    QSqlQuery qry;
    qry.prepare("DELETE FROM STUDENT_ENTRY WHERE Student_id = :student_id");
    qry.bindValue(":student_id", student_id);
    QSqlQuery qry1;
    qry1.prepare("DELETE FROM LOGINSTUDENT WHERE ID = :id");
    qry1.bindValue(":id", id);
    // Execute the query
    if (qry.exec()&& qry1.exec()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Success");
        msgBox.setText("Student record has been deleted successfully:");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

        // Refresh the combobox to reflect changes
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to Delete the student record:"+qry.lastError().text() );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}



