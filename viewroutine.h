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
    ~VIEWROUTINE();

private:
    Ui::VIEWROUTINE *ui;
};

#endif // VIEWROUTINE_H
