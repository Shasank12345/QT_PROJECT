#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>

//#include <QSqlDatabase>
//#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class adminwindow;
class teacherwindow;
class studentwindow;
class crwindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openRoleWindow(const QString &role);
private slots:
    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);
//<<<<<<< HEAD
//<<<<<<< HEAD
    void on_radioButton_clicked();
//=======
    void on_radioButton_4_clicked(bool checked);
//>>>>>>> 4481b371cd5e7552da5308ae0ead6c1adfbe7f54
//=======

    //void on_radioButton_clicked();

    //void on_radioButton_4_clicked(bool checked);

// >>>>>>> 75fa5a418d762f7f0180e1dcbb65ff3d8b8c84b7

private:

    QString getSelectedRole();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
