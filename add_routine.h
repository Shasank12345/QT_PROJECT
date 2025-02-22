#ifndef ADD_ROUTINE_H
#define ADD_ROUTINE_H

#include <QDialog>
#include<QObject>



namespace Ui {
class Add_routine;
}

class Add_routine : public QDialog
{
    Q_OBJECT

public:
    explicit Add_routine(QWidget *parent = nullptr);
    void adddata();
    void day();
    ~Add_routine();

private slots:
    void on_back1_clicked();

    void on_home1_clicked();

    void on_search_clicked();

    void on_Save_clicked();



    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Add_routine *ui;
};

#endif // ADD_ROUTINE_H
