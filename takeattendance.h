#ifndef TAKEATTENDANCE_H
#define TAKEATTENDANCE_H

#include <QMainWindow>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>
#include"mainwindow.h"

namespace Ui {
class takeattendance;
}

class takeattendance : public QMainWindow
{
    Q_OBJECT

public:

    explicit takeattendance(QWidget *parent = nullptr);
    void populatecombox1();
    void populatecombox2();
    void populatecombo3();
    void populatecombo4();
    ~takeattendance();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

private:
    MainWindow *main=new MainWindow;

    Ui::takeattendance *ui;
};

#endif // TAKEATTENDANCE_H
