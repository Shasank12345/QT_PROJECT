#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "qsqldatabase.h"
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
//#include<teacherwindow.h>
namespace Ui {
class LOGINWINDOW;
}
class LOGINWINDOW : public QMainWindow
{
    Q_OBJECT

public:
    explicit LOGINWINDOW(QString role, QWidget *parent = nullptr);
    //explicit LOGINWINDOW(QWidget *parent = nullptr);
    ~LOGINWINDOW();

private slots:
    void authenticate();
    void on_pushButton_clicked();





    void on_pushButton_2_clicked();

private:
    //teacherwindow *teach;
    Ui::LOGINWINDOW *ui;
    QString userRole;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
