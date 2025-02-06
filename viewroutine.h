#ifndef VIEWROUTINE_H
#define VIEWROUTINE_H

#include <QMainWindow>

namespace Ui {
class VIEWROUTINE;
}

class VIEWROUTINE : public QMainWindow
{
    Q_OBJECT

public:
    explicit VIEWROUTINE(QWidget *parent = nullptr);
    void day();
    void shows();
    ~VIEWROUTINE();

private slots:
    void on_back4_clicked();

    void on_home4_clicked();

    void on_show_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::VIEWROUTINE *ui;
};

#endif // VIEWROUTINE_H
