#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include"adminstudent_edit.h"
#include"adminteacher_edit.h"
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


    void on_teacherpart_clicked();

    //void on_adminpart_clicked();

    void on_studentEdit_clicked();

private:
    Ui::AdminWindow *ui;
    AdminTeacher_Edit *adminTeacher_edit;
    AdminStudent_Edit *adminStudent_edit;
};

#endif // ADMINWINDOW_H
