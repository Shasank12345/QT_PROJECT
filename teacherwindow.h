#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H
#include <QMainWindow>
#include<QStackedWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QDateEdit>
#include<QSqlTableModel>
#include"takeattendance.h"
#include"viewattendance.h"
#include"viewroutine.h"
#include"mainwindow.h"




namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(const QString &teacheremail,QWidget *parent = nullptr);
    ~TeacherWindow();


private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

   // void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TeacherWindow *ui;
    MainWindow *main=new MainWindow;
    //takeattendance *take=new takeattendance;
    //VIEWATTENDANCE *view=new VIEWATTENDANCE;
   // VIEWROUTINE *view2=new VIEWROUTINE;
    QString teacheremail;
    QString teacherSubject;
    void loadTeacherSubject();
    //QSqlQueryModel *model;
};

#endif // TEACHERWINDOW_H
