#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H
#include <QMainWindow>
#include<viewroutinestudent.h>
#include"mainwindow.h"

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(const QString &studentemail, QWidget *parent = nullptr);
    ~StudentWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::StudentWindow *ui;
    MainWindow *main=new MainWindow;
    QString Studentemail;
    QString studentname;
    void loadstudentname();
};

#endif // STUDENTWINDOW_H
