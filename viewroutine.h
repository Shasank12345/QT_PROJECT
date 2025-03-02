#ifndef VIEWROUTINE_H
#define VIEWROUTINE_H

#include <QMainWindow>
#include<QObject>

namespace Ui {
class VIEWROUTINE;
}

class VIEWROUTINE : public QMainWindow
{
    Q_OBJECT

public:
    explicit VIEWROUTINE(QString t,QString s,QWidget *parent = nullptr);
    void day();
   // void shows();
    ~VIEWROUTINE();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::VIEWROUTINE *ui;
    QString teacher;
    QString Subject;
};

#endif // VIEWROUTINE_H
