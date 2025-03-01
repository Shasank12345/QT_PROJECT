#ifndef ADMINTEACHER_EDIT_H
#define ADMINTEACHER_EDIT_H
#include"mainwindow.h"
#include"adminwindow.h"
#include <QDialog>

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
    void on_home0_clicked();

    void on_back_clicked();

    void on_add_clicked();

    void on_Edit_clicked();

    void on_Delet_clicked();

    void on_View_clicked();

    void on_addback_clicked();

    void on_back5_clicked();

    void on_editback_clicked();

    void on_editback_2_clicked();

    void on_editback_3_clicked();

    void on_editback_4_clicked();

    void on_deletback_clicked();

    void on_viewback_clicked();

    void on_home1_clicked();

    void on_home5_clicked();

    void on_home2_clicked();

    void on_home2_2_clicked();

    void on_home2_3_clicked();

    void on_home2_4_clicked();

    void on_home3_clicked();

    void on_home4_clicked();

    void on_save_clicked();

    void on_show_id_clicked();

    void on_ok_clicked();

    //void on_edit_clicked();

    void on_name_edit_clicked();

    void on_email_edit_clicked();

    void on_phn_edit_clicked();

    void on_sub_edit_clicked();

    void on_view5_clicked();

    void on_delet_clicked();

    void on_show_clicked();

    void on_view1_clicked();
    void populatecomboboz();
    void populatecombox();
    void oldpassword( QString a);

    void on_back_2_clicked();

    void on_pushButton_clicked();
    void email(QString a);
    void phn(QString a);
    void subject(QString a);


    void on_comboBox2_currentTextChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_editback_5_clicked();

    void on_sub_edit_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::AdminTeacher_Edit *ui;
     MainWindow *mainWindow =new MainWindow();


};

#endif // ADMINTEACHER_EDIT_H
