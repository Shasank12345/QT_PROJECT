#ifndef ADMINTEACHER_EDIT_H
#define ADMINTEACHER_EDIT_H
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
    void on_Add_clicked();

    void on_Prev_clicked();

    void on_Edit_clicked();

    void on_View_3_clicked();

    void on_Back_clicked();

    void on_delet_clicked();

    void on_Back_1_clicked();

    void on_back_2_clicked();

    void on_Back_3_clicked();

    void on_Delet_clicked();

    void on_addback_clicked();

    void on_editback_clicked();

    void on_deletback_clicked();

    void on_Add_data_clicked();

private:
    Ui::AdminTeacher_Edit *ui;

};

#endif // ADMINTEACHER_EDIT_H
