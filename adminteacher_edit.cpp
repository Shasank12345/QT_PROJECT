#include "adminteacher_edit.h"
#include "ui_adminteacher_edit.h"
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

AdminTeacher_Edit::AdminTeacher_Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminTeacher_Edit)
{
    ui->setupUi(this);
}
AdminTeacher_Edit::~AdminTeacher_Edit()
{
    delete ui;
}

void AdminTeacher_Edit::on_home0_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_back_clicked()
{
AdminWindow *adminWindow =new AdminWindow();
    adminWindow->show();
    this->hide();
}


void AdminTeacher_Edit::on_add_clicked()
{
          ui->stackedWidget->setCurrentIndex(1);
}

void AdminTeacher_Edit::on_view1_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void AdminTeacher_Edit::populatecomboboz()
{
    ui->comboBox2->clear();
    QSqlQuery qry;
    qry.prepare("SELECT Teacher_ID FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Teacher_ID and add it to the combobox
            QString teacher_id = qry.value(0).toString();
            ui->comboBox2->addItem(teacher_id);
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Teacher IDs: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }");
        msgBox.exec();
        return;
    }

}
void AdminTeacher_Edit :: email(QString a)
{
    QString id = a;
    ui->lineEdit_37->clear();
    QSqlQuery query;
    query.prepare("SELECT Email FROM teacher_data WHERE Teacher_Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Email = query.value(0).toString();
            ui->lineEdit_37->setText(Email);
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Not Found");
            msgBox.setText("No email found for the given teacher.");
            msgBox.setStyleSheet("QLabel { color: black; }");
            msgBox.exec();
            return;

        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Email: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}

void AdminTeacher_Edit :: oldpassword(QString a)
{
    QString id = a;
    ui->lineEdit_47->clear();
    QSqlQuery query;
    query.prepare("SELECT PASSWORD FROM LOGINTEACHER WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString pass = query.value(0).toString();
            ui->lineEdit_47->setText(pass);
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Not Found");
            msgBox.setText("No Password found for the given teacher ID.");
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
void AdminTeacher_Edit :: phn(QString a)
{
    QString id = a;
    ui->lineEdit_42->clear();
    QSqlQuery query;
    query.prepare("SELECT Phone_Number FROM teacher_data WHERE Teacher_Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Phone_Number = query.value(0).toString();
            ui->lineEdit_42->setText(Phone_Number);
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Not Found");
            msgBox.setText("No Phone Number found for the given teacher ID.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Phone Number: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
    }
}


void AdminTeacher_Edit :: subject(QString a)
{
    QString id = a;
    ui->lineEdit_44->clear();
    QSqlQuery query;
    query.prepare("SELECT Subject FROM teacher_data WHERE Teacher_Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Subject = query.value(0).toString();
            ui->lineEdit_44->setText(Subject);
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Not Found");
            msgBox.setText("No Subject found for the given teacher ID.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Subject: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}
void AdminTeacher_Edit::populatecombox()
{
    ui->comboBox->clear();
    QSqlQuery qry;
    qry.prepare("SELECT Teacher_ID FROM teacher_data");

    if (qry.exec()) {
        while (qry.next()) {
            // Retrieve each Teacher_ID and add it to the combobox
            QString teacher_id = qry.value(0).toString();
            ui->comboBox->addItem(teacher_id);
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to retrieve Teacher id: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

}


void AdminTeacher_Edit::on_Edit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    populatecomboboz();

}


void AdminTeacher_Edit::on_Delet_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    populatecombox();
}


void AdminTeacher_Edit::on_View_clicked()
{
      ui->stackedWidget->setCurrentIndex(8);
}


void AdminTeacher_Edit::on_addback_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_back5_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_editback_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_deletback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_viewback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_home1_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home5_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home2_clicked()
{

    mainWindow->show();
    this->hide();
}


void AdminTeacher_Edit::on_home2_2_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home2_3_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home2_4_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home3_clicked()
{

    mainWindow->show();
    this->hide();

}


void AdminTeacher_Edit::on_home4_clicked()
{

    mainWindow->show();
    this->hide();
}


void AdminTeacher_Edit::on_save_clicked()
{
    QString name;
    QString email;
    QString teacher_id;
    QString phn_no;
    QString subject;
    QString PASSWORD;
    QString EMAIL;
    QString id;
    EMAIL=ui->lineEdit_33->text();
     id = ui->lineEdit_31->text();
    name=ui->lineEdit_16->text();
    email=ui->lineEdit_33->text();
    teacher_id = ui->lineEdit_31->text();
    phn_no=ui->lineEdit_32->text();
    subject=ui->lineEdit->text();
    PASSWORD=ui->pass->text();
    if (name.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Name.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }
    else if (email.isEmpty() ){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Email.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (teacher_id.isEmpty() ){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Teacher Id.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if (phn_no.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Phone Number.");
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
    else if (subject.isEmpty() ){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Subject.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if(PASSWORD.isEmpty()){

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Enter Password.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
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



    QSqlQuery q;
    q.prepare("INSERT INTO LOGINTEACHER (EMAIL, PASSWORD,ID)"
              "VALUES(:email, :password,:id)");
    q.bindValue(":email", EMAIL);
    q.bindValue(":password", PASSWORD);
    q.bindValue(":id", id);


        // Clear the input fields after saving
        ui->lineEdit_16->clear();
        ui->lineEdit_33->clear();
        ui->lineEdit_31->clear();
        ui->lineEdit_32->clear();
        ui->lineEdit->clear();
         ui->pass->clear();

    if(q.exec()&&qry.exec()){
         //QMessageBox::information(this, "Success", "Teacher login information saved successfully.");
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Success");
        msgBox.setText(" Teacher information saved successfully on both table." );
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    } else {
        //QMessageBox::critical(this, "Database Error", "Failed to save teacher information: " + qry.lastError().text());
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Failed to save teacher information: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

}





void AdminTeacher_Edit::on_ok_clicked()
{
    QString selectedTeacherId = ui->comboBox2->currentText();
    QString select = ui->comboBox3->currentText();
    QString name=ui->lineEdit_3->text();

    if (selectedTeacherId.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please select a valid Teacher ID.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    if(select=="NONE SELECTED")
    {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please Select what you want to edit.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
    }
    if(select=="NAME")
    {
         ui->lineEdit_17->clear();
        ui->lineEdit_36->setText(selectedTeacherId);
        ui->lineEdit_4->setText(name);
        ui->stackedWidget->setCurrentIndex(3);
    }

    if(select=="EMAIL")
    {
         ui->lineEdit_18->clear();
       ui->lineEdit_35->setText(selectedTeacherId);
        email(selectedTeacherId);
       ui->lineEdit_40->setText(name);
        ui->stackedWidget->setCurrentIndex(4);
    }

    if(select=="PHONE NUMBER")
    {
         ui->lineEdit_38->clear();
       ui->lineEdit_20->setText(selectedTeacherId);
        ui->lineEdit_41->setText(name);
       phn(selectedTeacherId);
        ui->stackedWidget->setCurrentIndex(5);
    }
    if(select=="SUBJECT")
    {
         ui->lineEdit_2->clear();
        ui->lineEdit_39->setText(selectedTeacherId);
        ui->lineEdit_43->setText(name);
        subject(selectedTeacherId);
        ui->stackedWidget->setCurrentIndex(6);
    }
    if(select=="PASSWORD")
    {
        ui->lineEdit_5->clear();
        ui->lineEdit_45->setText(selectedTeacherId);
        ui->lineEdit_46->setText(name);
        oldpassword(selectedTeacherId);
        ui->stackedWidget->setCurrentIndex(9);
    }
}






void AdminTeacher_Edit::on_name_edit_clicked()
{
    QString name;
    QString teacher_id;


    name=ui->lineEdit_17->text();
    teacher_id = ui->lineEdit_36->text();

    if (name.isEmpty() ) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Input Error");
        msgBox.setText("Please fill name.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    QSqlQuery qry;

    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to execute query: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (qry.next()) {
        qry.prepare("UPDATE teacher_data SET Name = :name WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":name", name);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Success");
            msgBox.setText("Name updated successfully");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("Could not update the record: " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
             return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("No Match Found");
        msgBox.setText("No record found with the given Teacher ID.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
         return;
    }
}



void AdminTeacher_Edit::on_email_edit_clicked()
{
        QString email = ui->lineEdit_18->text();
        QString teacher_id = ui->lineEdit_35->text();
        QString id = teacher_id;

        if (email.isEmpty() ) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Input Error");
            msgBox.setText("Please fill Email.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        QSqlQuery qry;
        qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":teacher_id", teacher_id);
        QSqlQuery qry2;
        qry2.prepare("SELECT * FROM LOGINTEACHER WHERE ID = :id");
        qry2.bindValue(":id", id);
        if (!qry.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Error");
            msgBox.setText("Failed to execute query: " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        if (!qry.next()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Error");
            msgBox.setText("No record found with the given Teacher ID in teacher_data.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }


        if (!qry2.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Error");
            msgBox.setText("Failed to execute query: " + qry2.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        if (!qry2.next()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" No Match Found");
            msgBox.setText("No record found with the given ID in LOGINTEACHER.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        qry.prepare("UPDATE teacher_data SET Email = :email WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":email", email);
        qry.bindValue(":teacher_id", teacher_id);

        if (!qry.exec()) {
           // QMessageBox::warning(this, "Update Failed", "Could not update teacher_data: " + qry.lastError().text());
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Update Failed");
            msgBox.setText("Could not update teacher_data: " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        qry2.prepare("UPDATE LOGINTEACHER SET Email = :email WHERE ID = :id");
        qry2.bindValue(":email", email);
        qry2.bindValue(":id", id);

        if (!qry2.exec()) {
             QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Update Failed");
            msgBox.setText("Could not update teacher_data: " + qry2.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Success");
        msgBox.setText("Email updated successfully in both tables.");
         msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }




void AdminTeacher_Edit::on_phn_edit_clicked()
{
    QString phn_no;
    QString teacher_id;


    phn_no=ui->lineEdit_38->text();
    teacher_id = ui->lineEdit_20->text();

    if (phn_no.length() == 10 ) {

        QSqlQuery qry;

        qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
        qry.bindValue(":teacher_id", teacher_id);


        if (!qry.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Database Error");
            msgBox.setText("Failed to execute query: " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
        if (qry.next()) {
            qry.prepare("UPDATE teacher_data SET Phone_Number = :phn_no WHERE Teacher_ID = :teacher_id");
            qry.bindValue(":phn_no", phn_no);
            qry.bindValue(":teacher_id", teacher_id);


            if (qry.exec()) {
                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setWindowTitle(" Success");
                msgBox.setText("Phone Number updated successfully.");
                msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
                msgBox.exec();
                return;
            } else {
                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.setWindowTitle(" Update Failed");
                msgBox.setText("Could not update the record: " + qry.lastError().text());
                msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
                msgBox.exec();
                return;
            }
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" No Match Found");
            msgBox.setText("No record found with the given Teacher ID.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }


    } else {
        QMessageBox::warning(this, "Invalid Input", "Phone number must be exactly 10 digits.");
        return;
    }


    // QSqlQuery qry;

    // qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    // qry.bindValue(":teacher_id", teacher_id);


    // if (!qry.exec()) {
    //     QMessageBox msgBox(this);
    //     msgBox.setIcon(QMessageBox::Warning);
    //     msgBox.setWindowTitle("Database Error");
    //     msgBox.setText("Failed to execute query: " + qry.lastError().text());
    //     msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //     msgBox.exec();
    //     return;
    // }

    // if (qry.next()) {
    //     qry.prepare("UPDATE teacher_data SET Phone_Number = :phn_no WHERE Teacher_ID = :teacher_id");
    //     qry.bindValue(":phn_no", phn_no);
    //     qry.bindValue(":teacher_id", teacher_id);


    //     if (qry.exec()) {
    //         QMessageBox msgBox(this);
    //         msgBox.setIcon(QMessageBox::Information);
    //         msgBox.setWindowTitle(" Success");
    //         msgBox.setText("Phone Number updated successfully.");
    //         msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //         msgBox.exec();
    //         return;
    //     } else {
    //         QMessageBox msgBox(this);
    //         msgBox.setIcon(QMessageBox::Warning);
    //         msgBox.setWindowTitle(" Update Failed");
    //         msgBox.setText("Could not update the record: " + qry.lastError().text());
    //         msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //         msgBox.exec();
    //         return;
    //     }
    // } else {
    //     QMessageBox msgBox(this);
    //     msgBox.setIcon(QMessageBox::Warning);
    //     msgBox.setWindowTitle(" No Match Found");
    //     msgBox.setText("No record found with the given Teacher ID.");
    //     msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
    //     msgBox.exec();
    //     return;
    // }
}


void AdminTeacher_Edit::on_sub_edit_clicked()
{
    QString subject;
    QString teacher_id;


    subject=ui->lineEdit_2->text();
    teacher_id = ui->lineEdit_39->text();


    QSqlQuery qry;

    qry.prepare("SELECT * FROM teacher_data WHERE Teacher_ID = :teacher_id ");
    qry.bindValue(":teacher_id", teacher_id);


    if (!qry.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to execute query: " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    if (qry.next()) {
        qry.prepare("UPDATE teacher_data SET Subject = :subject WHERE Teacher_ID = :teacher_id");
        qry.bindValue(":subject", subject);
        qry.bindValue(":teacher_id", teacher_id);


        if (qry.exec()) {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle(" Success");
            msgBox.setText("Subject updated successfully.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle(" Update Failed");
            msgBox.setText("Could not update the record: " + qry.lastError().text());
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" No Match Found");
        msgBox.setText("No record found with the given Teacher ID.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}






void AdminTeacher_Edit::on_delet_clicked()
{


    QString teacher_id = ui->comboBox->currentText();
    QString name=ui->lineEdit_85->text();
    QString id=teacher_id;

    if (teacher_id.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("input error");
        msgBox.setText("Please select a valid Teacher ID to delete.");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;


    }


    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Delete Confirmation",
        "Are you sure you want to delete " + name + " detail ?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return;
    }

    // Prepare the SQL query to delete the teacher record
    QSqlQuery qry;
    qry.prepare("DELETE FROM teacher_data WHERE Teacher_ID = :teacher_id");
    qry.bindValue(":teacher_id", teacher_id);
    QSqlQuery qry1;
    qry1.prepare("DELETE FROM LOGINTEACHER WHERE ID = :id");
    qry1.bindValue(":id", id);
    // Execute the query
    if (qry.exec() && qry1.exec()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle(" Success");
        msgBox.setText("Teacher record deleted successfully from both table.");
        msgBox.setStyleSheet("QLabel { color: black; }");
        msgBox.exec();
        return;
        // Refresh the combobox to reflect changes
    } else {
        QMessageBox msgBox(this);
       msgBox.setIcon(QMessageBox::Warning);
       msgBox.setWindowTitle("Database Error");
       msgBox.setText("Failed to delete the teacher record: " + qry.lastError().text()+ qry1.lastError().text());
       msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
       msgBox.exec();
       return;
    }
}




void AdminTeacher_Edit::on_show_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("Teacher_data");
    model->select();

    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Teacher ID");
    model->setHeaderData(2, Qt::Horizontal, "Phone Number");
    model->setHeaderData(3, Qt::Horizontal, "Email");
    model->setHeaderData(4, Qt::Horizontal, "Subject");
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
}





void AdminTeacher_Edit::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_pushButton_clicked()
{
    QString id = ui->comboBox2->currentText();

    if (id.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("input error");
        msgBox.setText("Please select  Teacher ID ");
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT Name FROM teacher_data WHERE Teacher_Id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_3->setText(Name);
        } else {
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle(" Not Found");
            msgBox.setText("No Name found for the given teacher.");
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
            return;
        }
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("CFailed to delete the teacher record: " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}




void AdminTeacher_Edit::on_comboBox2_currentTextChanged(const QString &Teacher_Id)
{
    ui->lineEdit_3->clear();

    QSqlQuery query;
    query.prepare("SELECT Name FROM Teacher_data WHERE Teacher_Id = :Teacher_Id");
    query.bindValue(":Teacher_Id", Teacher_Id);

    if(query.exec()) {
        while(query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_3->setText(Name);
        }
    } else {
        qDebug() << "Error retrieving student ID:" << query.lastError().text();
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to load Teacher ID:  " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void AdminTeacher_Edit::on_comboBox_currentTextChanged(const QString &Teacher_Id)
{
    ui->lineEdit_85->clear();

    QSqlQuery query;
    query.prepare("SELECT Name FROM Teacher_data WHERE Teacher_Id = :Teacher_Id");
    query.bindValue(":Teacher_Id", Teacher_Id);

    if(query.exec()) {
        while(query.next()) {
            QString Name = query.value(0).toString();
            ui->lineEdit_85->setText(Name);
        }
    } else {
        qDebug() << "Error retrieving student ID:" << query.lastError().text();
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Database Error");
        msgBox.setText("Failed to load Teacher ID:  " + query.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


void AdminTeacher_Edit::on_editback_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void AdminTeacher_Edit::on_sub_edit_2_clicked()
{
    QString old;
    QString id;


    old=ui->lineEdit_5->text();
    id = ui->lineEdit_45->text();


    QSqlQuery qry;

    qry.prepare("SELECT * FROM LOGINTEACHER WHERE ID = :id ");
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
        qry.prepare("UPDATE LOGINTEACHER SET PASSWORD = :old WHERE ID = :id");
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
        msgBox.setText("No record found with the given TEACHER ID.  " + qry.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
}


