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
    void name();
    void day();
    ~deleteroutine();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deleteroutine *ui;
};

#endif // DELETEROUTINE_H
