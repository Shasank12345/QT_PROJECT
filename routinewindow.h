#ifndef ROUTINEWINDOW_H
#define ROUTINEWINDOW_H
#include"mainwindow.h"

#include <QDialog>

namespace Ui {
class RoutineWindow;
}

class RoutineWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RoutineWindow(QWidget *parent = nullptr);
    ~RoutineWindow();

private slots:
    void on_home_clicked();

    void on_back_clicked();

  // void on_ok_clicked();

   // void on_back1_clicked();

   // void on_home1_clicked();

    //void on_Load_clicked();

  //  void on_Save_clicked();

  // void on_back4_clicked();

   //void on_home4_clicked();

   // void on_show_clicked();

   // void on_load_clicked();

    //void on_load1_clicked();

   // void on_back4_2_clicked();

   // void on_home4_2_clicked();

    //void on_del_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();
    void day();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::RoutineWindow *ui;
    MainWindow *mainWindow =new MainWindow();
};

#endif // ROUTINEWINDOW_H
