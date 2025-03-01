#ifndef VIEWROUTINESTUDENT_H
#define VIEWROUTINESTUDENT_H

#include <QMainWindow>

namespace Ui {
class viewroutinestudent;
}

class viewroutinestudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewroutinestudent(QWidget *parent = nullptr);
    ~viewroutinestudent();

private:
    Ui::viewroutinestudent *ui;
};

#endif // VIEWROUTINESTUDENT_H
