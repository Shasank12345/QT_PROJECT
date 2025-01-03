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

   // void on_radioButton_clicked();
    void on_radioButton_4_clicked(bool checked);


private:

    QString getSelectedRole();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
