#ifndef ADMINTEACHER_EDIT_H
#define ADMINTEACHER_EDIT_H
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include<QMessageBox>
namespace Ui {
class AdminTeacher_Edit;
}

class AdminTeacher_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit AdminTeacher_Edit(QWidget *parent = nullptr);
    ~AdminTeacher_Edit();

private slots:
   // void on_Add_clicked();

   // void on_Prev_clicked();

   void on_Edit_clicked();

    //void on_View_3_clicked();

    //void on_Edit_clicked();

  //  void on_delet_clicked();

    //void on_Back_1_clicked();

   // void on_back_2_clicked();

    //void on_Back_3_clicked();

    void on_Delet_clicked();

    void on_addback_clicked();

    void on_editback_clicked();

    void on_deletback_clicked();

    void on_Add_data_clicked();

    void on_home0_clicked();

    void on_pushButton_clicked();

    void on_back_clicked();

    void on_add_clicked();

    void on_home1_clicked();

    void on_home2_clicked();

    void on_pushButton_3_clicked();

    void on_home3_clicked();

    void on_save_clicked();

    void on_editsav_clicked();

    void on_edit_clicked();

    void on_save1_clicked();

    void on_View_clicked();

    void on_show_clicked();

    void on_home4_clicked();

    void on_viewback_clicked();

    void on_delet_clicked();

    void on_view5_clicked();

    void on_ok_clicked();

    void on_show_id_clicked();

    void on_back5_clicked();

    void on_home5_clicked();

    void on_editback_2_clicked();

    void on_home2_2_clicked();

    void on_editback_3_clicked();

    void on_home2_3_clicked();

    void on_edit_2_clicked();

    void on_edit_3_clicked();

    void on_home5_2_clicked();

    void on_back5_2_clicked();

    void on_show_id_2_clicked();

    void on_ok_2_clicked();

    void on_Edit5_clicked();

private:
    Ui::AdminTeacher_Edit *ui;

};

#endif // ADMINTEACHER_EDIT_H
