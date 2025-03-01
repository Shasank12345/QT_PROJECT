#ifndef ADMINSTUDENT_EDIT_H
#define ADMINSTUDENT_EDIT_H

#include <QDialog>
#include<QObject>

namespace Ui {
class AdminStudent_Edit;
}

class AdminStudent_Edit : public QDialog
{
    Q_OBJECT


public:
    explicit AdminStudent_Edit(QWidget *parent = nullptr);
    ~AdminStudent_Edit();

private slots:
    void on_add_clicked();

    void on_view_clicked();

    void on_edit_clicked();

    void on_delet_3_clicked();

    void on_back1_clicked();

    void on_home1_clicked();

    void on_back2_clicked();

    void on_save1_clicked();

    void on_home2_clicked();

    void on_back3_clicked();

    void on_view1_clicked();

    void on_home3_2_clicked();

    void on_pushButton_3_clicked();

    void on_back3_2_clicked();

    void on_summit_clicked();

    void on_home4_clicked();

    void on_back4_clicked();

    void on_save2_clicked();

    void on_home5_clicked();

    void on_back5_clicked();

    void on_save3_clicked();

    void on_home6_clicked();

    void on_bak6_clicked();

    void on_save4_clicked();

    void on_home7_clicked();

    void on_back7_clicked();

    void on_save5_clicked();

    void on_home11_clicked();

    void on_back8_2_clicked();

    void on_save6_clicked();

    void on_home9_clicked();

    void on_view5_2_clicked();

    void on_delet1_clicked();

    void on_back9_clicked();

    void on_home10_clicked();
    void populatecombo();
    void populatecombo1();
    void email(QString a);
    void phn(QString a);
    void address(QString a);

    void on_pushButton_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox1_currentTextChanged(const QString &arg1);

    void on_stackedWidget_currentChanged(int arg1);

    void on_lineEdit_19_cursorPositionChanged(int arg1, int arg2);

     void oldpassword( QString a);

    void on_home222_clicked();

     void on_back99_clicked();

    void on_update100_clicked();

     void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

     void on_emailupdate_clicked();

    void on_emailhome_clicked();

     void on_emailback_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::AdminStudent_Edit *ui;
};

#endif // ADMINSTUDENT_EDIT_H
