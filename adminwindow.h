#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include"adminstudent_edit.h"
#include"adminteacher_edit.h"
#include"routinewindow.h"
namespace Ui {
class AdminWindow;
}


class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:

    void on_OK1_clicked();


    void on_home_clicked();

private:
    Ui::AdminWindow *ui;
    AdminTeacher_Edit *adminTeacher_edit;
    AdminStudent_Edit *adminStudent_edit;
    RoutineWindow *routinewindow;
};

#endif // ADMINWINDOW_H
