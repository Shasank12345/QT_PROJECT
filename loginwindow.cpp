#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<QMessageBox>
#include<QSqlError>
#include<teacherwindow.h>
#include<studentwindow.h>
#include<adminwindow.h>
//#include <QCryptographicHash>
#include<qmessagebox.h>


LOGINWINDOW::LOGINWINDOW(QString role,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LOGINWINDOW)
    ,userRole(role)
{
    ui->setupUi(this);
     this->setFixedSize(this->size());
    this->setWindowTitle("LOGIN AS : "+role);
    QString connectionName = "connection_" + QString::number(QDateTime::currentMSecsSinceEpoch());
    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("../../FACULTY.db");

    if (!db.open()) {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(" Database Error  ");
        msgBox.setText("Failed to open the database: " + db.lastError().text());
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    qDebug() << "Database connection established with name: " << connectionName;
}

LOGINWINDOW::~LOGINWINDOW()
{
    delete ui;

}
void LOGINWINDOW::on_pushButton_clicked()
{
    QString EMAIL = ui->lineEdit->text().trimmed();
    QString PASSWORD = ui->lineEdit_2->text().trimmed();

    if (EMAIL.isEmpty() && PASSWORD.isEmpty()) {
       // QMessageBox::warning(this, "INPUT ERROR", "");
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("INPUT ERROR");
        msgBox.setText("PLEASE ENTER BOTH EMAIL AND PASSWORD");
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }
    else if(EMAIL.isEmpty()){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("INPUT ERROR");
        msgBox.setText("PLEASE ENTER  EMAIL");
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }
    else if(PASSWORD.isEmpty()){
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("INPUT ERROR");
        msgBox.setText("PLEASE ENTER PASWORD");
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;

    }

    // Determine the table based on user role
    QString table;
    if (userRole == "admin") {
        table = "LOGINADMIN";
    } else if (userRole == "teacher") {
        table = "LOGINTEACHER";
    } else if (userRole == "student") {
        table = "LOGINSTUDENT";
    } else {

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("LOGIN ERROR");
        msgBox.setText("INVALID USER ROLE SELECTED");
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();
        return;
    }

    // Prepare SQL query with correct spacing
    QSqlQuery query;
    QString queryStr = QString("SELECT * FROM %1 WHERE EMAIL = :A AND PASSWORD = :B").arg(table);

    qDebug() << "Prepared Query: " << queryStr; // Log query string for debugging

    query.prepare(queryStr);
    query.bindValue(":A", EMAIL);
    query.bindValue(":B", PASSWORD);

    if (query.exec()) {
        if (query.next()) {
           // QMessageBox::information(this, "LOGIN SUCCESSFUL", "WELCOME " + EMAIL);
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("LOGIN SUCCESSFUL");
            msgBox.setText("WELCOME" + EMAIL);
            // Apply a stylesheet to change text color in QLabel (which displays the text)
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();


            if (userRole == "admin") {
                AdminWindow *adminwindow = new AdminWindow();
                qDebug() << "OPENING ADMIN WINDOW";
                adminwindow->show();

                this->hide();
            } else if (userRole == "teacher") {
                TeacherWindow *teacherWindow = new TeacherWindow(EMAIL);
                qDebug() << "OPENING TEACHER WINDOW";
                teacherWindow->show();
                teacherWindow->setAttribute(Qt::WA_DeleteOnClose);
                this->hide();
            } else if (userRole == "student") {
                StudentWindow *studentWindow = new StudentWindow(EMAIL);
                qDebug() << "OPENING STUDENT WINDOW";
                studentWindow->show();
                studentWindow->setAttribute(Qt::WA_DeleteOnClose);
                this->hide();
            }
        } else {
          //  QMessageBox::warning(this, "LOGIN FAILED", "Invalid credentials, please try again.");
            QMessageBox msgBox(this);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("LOGIN FAILED");
            msgBox.setText("Invalid credentials, please try again. " + query.lastError().text());
            // Apply a stylesheet to change text color in QLabel (which displays the text)
            msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
            msgBox.exec();
        }
    } else {
       // QMessageBox::warning(this, "DATABASE ERROR", "Query execution failed: " + query.lastError().text());
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("DATABASE ERROR");
        msgBox.setText("Query execution failed: " + query.lastError().text());
        // Apply a stylesheet to change text color in QLabel (which displays the text)
        msgBox.setStyleSheet("QLabel { color: black; }QPushButton { color: black; }");
        msgBox.exec();

    }
}


void LOGINWINDOW::on_pushButton_2_clicked()
{
    MainWindow *main=new MainWindow();
    main->show();
    this->hide();

}

