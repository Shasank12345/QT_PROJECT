#ifndef DELETEROUTINE_H
#define DELETEROUTINE_H

#include <QDialog>

namespace Ui {
class deleteroutine;
}

class deleteroutine : public QDialog
{
    Q_OBJECT

public:
    explicit deleteroutine(QWidget *parent = nullptr);
    ~deleteroutine();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_Delete_clicked();

    void on_Home_clicked();

    void on_Back_clicked();

    void on_delete_2_clicked();



    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::deleteroutine *ui;
public:
   // void adddata();
    void day();
};

#endif // DELETEROUTINE_H
