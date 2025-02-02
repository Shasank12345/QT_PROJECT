#ifndef VIEWATTENDANCE_H
#define VIEWATTENDANCE_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>
#include<QSqlQueryModel>
#include"mainwindow.h"
#include"takeattendance.h"

namespace Ui {
class VIEWATTENDANCE;
}

class VIEWATTENDANCE : public QMainWindow
{
    Q_OBJECT

public:
    explicit VIEWATTENDANCE(QWidget *parent = nullptr);
    void populatecombo1();
    void populatecombo2();
    ~VIEWATTENDANCE();

private slots:
    void fetchdata();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    takeattendance *take=new takeattendance;
    MainWindow *main=new MainWindow;
    Ui::VIEWATTENDANCE *ui;
};

#endif // VIEWATTENDANCE_H
