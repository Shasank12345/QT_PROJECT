#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
class RoutineWindow;
class AdminTeacher_Edit;
class AdminStudent_Edit;
}


class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:


    void on_home_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();



    void on_LOGOUT_clicked();

private:
    Ui::AdminWindow *ui;

};

#endif // ADMINWINDOW_H
