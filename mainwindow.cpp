#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qstring>
#include<QPixmap>
#include<QPalette>
#include "adminwindow.h"
#include "teacherwindow.h"
#include "studentwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Remove layout margins
    if (ui->centralwidget->layout()) {
        ui->centralwidget->layout()->setContentsMargins(0, 0, 0, 0);
        ui->centralwidget->layout()->setSpacing(0);
    }





    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../../DATABASE/FACULTY.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database: " + db.lastError().text());
    }
    ui->lineEdit_1->setStyleSheet(
        "QLineEdit {"
        "   color: black;"
        "   background-color:black;"
        "   border: 2px solid black;"
        "   border-radius: 10px;"
        "   font-size:12px;"
        "   padding: 4px;"
        "}"
        "QLineEdit:hover {"
        "   border: 2px solid black;"  // Green border on hover
        "}"
        "QLineEdit:focus {"
        "   background-color: brown;"  // Light green background on focus
        "   border: 2px solid brown;"  // Green border on focus
        "}"
        );

ui->lineEdit_2->setStyleSheet(
    "QLineEdit {"
    "   color: black;"
    "   background-color:black;"
    "   border: 2px solid black;"
    "   border-radius: 10px;"
    "   font-size:12px;"
    "   padding: 4px;"
    "}"
    "QLineEdit:hover {"
    "   border: 2px solid black;"  // Green border on hover
    "}"
    "QLineEdit:focus {"
    "   background-color:brown;"  // Light green background on focus
    "   border: 2px solid brown;"  // Green border on focus
    "}"
    );





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString selectedRole = getSelectedRole();
    /*QString role;

    // Determine selected role
    if (ui->radioButton->isChecked()) {
        role = "TEACHER";
    } else if (ui->radioButton_2->isChecked()) {
        role = "ADMIN";

    } else if (ui->radioButton_3->isChecked()) {
        role = "STUDENT";

    }*/
    QString username;
    QString password;
    username=ui->lineEdit_1->text();
    password=ui->lineEdit_2->text();

    if (username.isEmpty() || password.isEmpty()) {
        //QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
       QMessageBox msgBox;
        msgBox.setWindowTitle("Input Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel { color:grey;"
                             "font:italic; }");
        msgBox.setText("Please enter both username and password");
        msgBox.exec();
        return;
    }
    if (selectedRole.isEmpty()) {
       // QMessageBox::warning(this, "Role Error", "Please select a role.");
        QMessageBox msgBox;
        msgBox.setWindowTitle("login failed");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel { color:grey;"
                             "font:italic; }");
        msgBox.setText("Please select a role.");
        msgBox.exec();
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM USER WHERE USERNAME= :username AND PASSWORD = :password AND ROLE= :role");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role", selectedRole);

    if (query.exec() && query.next() && query.value(0).toInt() == 1) {
       // QMessageBox::(this, "Login Success", "Welcome " + username + "!");

        QMessageBox msgBox;
        msgBox.setWindowTitle("login Sucess");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel { color:grey; "
                             "font:italic;}");
        msgBox.setText("WELCOME "+username+";");
        msgBox.exec();
        openRoleWindow(selectedRole);





    } else {
        //QMessageBox::warning(this, "Login Failed", "Invalid username, password, or role.");
        QMessageBox msgBox;
        msgBox.setWindowTitle("login failed");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel { color:grey;"
                             "font:italic; }");
        msgBox.setText("Invalid username,password,or role.");
        msgBox.exec();

    }
}












void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked){
        ui->lineEdit_1->setPlaceholderText("example@teacher.ku.edu.np");
        ui->lineEdit_2->setPlaceholderText("Enter your password");

        ui->label_4->setText("SELECTED ROLE: \"TEACHER\"");
        ui->label_4->setFont(QFont("BOLD",12));
        ui->label_4->setStyleSheet("color: darkgreen;");
        ui->label_5->setText("STATUS:");
        ui->label_5->setFont(QFont("BOLD",14));

        ui->label_5->setStyleSheet("color:GREEN;");



    }


}



void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if(checked){

        ui->lineEdit_1->setPlaceholderText("example@admin.ku.edu.np");
        ui->lineEdit_2->setPlaceholderText("Enter your password");
        ui->label_4->setText("SELECTED ROLE: \"ADMIN\"");
        ui->label_4->setFont(QFont("BOLD",12));
        ui->label_4->setStyleSheet("color: darkgreen;");
        ui->label_5->setText("STATUS:");
        ui->label_5->setFont(QFont("BOLD",14));

        ui->label_5->setStyleSheet("color: green;");
    }


}


void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if(checked){
         ui->lineEdit_1->setPlaceholderText("example@student.ku.edu.np");
         ui->lineEdit_2->setPlaceholderText("Enter your password...");
         ui->label_4->setText("SELECTED ROLE: \"STUDENT\"");
         ui->label_4->setFont(QFont("BOLD",12));
         ui->label_4->setStyleSheet("color: darkgreen;");
         ui->label_5->setStyleSheet("color: green;");
         ui->label_5->setText("STATUS:");
         ui->label_5->setFont(QFont("BOLD",14));





    }

}

QString MainWindow::getSelectedRole()
{
    if (ui->radioButton_2->isChecked())
        return "ADMIN";
    if (ui->radioButton->isChecked())
        return "TEACHER";
    if (ui->radioButton_3->isChecked())
        return "STUDENT";
    else
    return "";
}

void MainWindow::openRoleWindow(const QString &role)
{
    if(role=="ADMIN"){
        AdminWindow *adminWindow = new AdminWindow();
        adminWindow->show();
         this->close();
    }
    else if(role=="TEACHER"){
        TeacherWindow *teacherWindow =new TeacherWindow();
        teacherWindow->show();
         this->close();





    }
    else if(role=="STUDENT"){
        StudentWindow *studentWindow =new StudentWindow();
        studentWindow->show();
        this->close();



    }




    else
        this->close(); // Close login window
    }
