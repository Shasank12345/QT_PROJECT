#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginWindow.h"
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>
#include<QObject>

//#include <QSqlDatabase>
//#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class adminwindow;
class teacherwindow;
class studentwindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
private:
    Ui::MainWindow *ui;
    LOGINWINDOW *loginwindow;

};
#endif // MAINWINDOW_H
