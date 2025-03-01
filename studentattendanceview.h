#ifndef STUDENTATTENDANCEVIEW_H
#define STUDENTATTENDANCEVIEW_H
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

    ~Studentattendanceview();

private slots:
    void fetchdata();
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
    void on_tableView_activated(const QModelIndex &index);


    void on_pushButton_6_clicked();

private:
    QString studentgmail;
    QString studentname;
    MainWindow *main=new MainWindow;
    Ui::Studentattendanceview *ui;
};

#endif // STUDENTATTENDANCEVIEW_H
