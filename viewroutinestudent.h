#ifndef VIEWROUTINESTUDENT_H
#define VIEWROUTINESTUDENT_H

#include <QMainWindow>
#include<QString>
#include "mainwindow.h"
namespace Ui {
class viewroutinestudent;
}

class viewroutinestudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewroutinestudent(const QString STD_NAME,QWidget *parent = nullptr);
    ~viewroutinestudent();

private:
    Ui::viewroutinestudent *ui;
    QString Studentsname;
public:
    void populatecombo();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // VIEWROUTINESTUDENT_H
