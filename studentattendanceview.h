#ifndef STUDENTATTENDANCEVIEW_H
#define STUDENTATTENDANCEVIEW_H
#include "qsqlquerymodel.h"
#include"studentwindow.h"
#include"mainwindow.h"
#include <QMainWindow>

namespace Ui {
class Studentattendanceview;
}

class Studentattendanceview : public QMainWindow
{
    Q_OBJECT

public:
    explicit Studentattendanceview(const QString &studentgmail,const QString &studentname,QWidget *parent = nullptr);
    void days();
    void populatecombo2();
    void subject();

    ~Studentattendanceview();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_6_clicked();

private:
    QString studentgmail;
    QString studentname;
  //  QSqlQueryModel *model;

    MainWindow *main=new MainWindow;
    Ui::Studentattendanceview *ui;
};

#endif // STUDENTATTENDANCEVIEW_H
