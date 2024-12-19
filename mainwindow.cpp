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





    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/User/OneDrive/Desktop/proj/DATABASE/FACULTY.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to database: " + db.lastError().text());
    }


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
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }
    if (selectedRole.isEmpty()) {
        QMessageBox::warning(this, "Role Error", "Please select a role.");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM USER WHERE USERNAME= :username AND PASSWORD = :password AND ROLE= :role");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role", selectedRole);

    if (query.exec() && query.next() && query.value(0).toInt() == 1) {
        QMessageBox::information(this, "Login Success", "Welcome " + username + "!");
         openRoleWindow(selectedRole);




    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username, password, or role.");
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
    }
    else if(role=="TEACHER"){
        TeacherWindow *teacherWindow =new TeacherWindow();
        teacherWindow->show();





    }
    else if(role=="STUDENT"){
        StudentWindow *studentWindow =new StudentWindow();
        studentWindow->show();



    }


    else
        this->close(); // Close login window
    }






