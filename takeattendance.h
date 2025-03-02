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

    explicit takeattendance(const QString &teacherEmail, const QString &teacherSubject,QWidget *parent = nullptr);
    void populatecombox1();
  /*  void populatecombox2()
    {
        QSqlQuery query;
        if (query.exec("SELECT Student_id FROM STUDENT_ENTRY")) {
            while (query.next()) {
                ui->comboBox_2->addItem(query.value(0).toString());
            }
        } else {
            qDebug() << "Error loading data:" << query.lastError().text();
        }

    }*/
      void populatecombo3();
    void populatecombo4();
    ~takeattendance();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  //  void on_comboBox_activated(int index);

   // void on_comboBox_3_activated(int index);

    void on_comboBox_currentTextChanged(const QString &name);


    void on_comboBox_activated(int index);

private:
    MainWindow *main=new MainWindow;
    QString teacherEmail;
    QString teacherSubject;
   // void loadAttendanceData();

    Ui::takeattendance *ui;
};

#endif // TAKEATTENDANCE_H
