#ifndef CRWINDOW_H
#define CRWINDOW_H

#include <QMainWindow>

namespace Ui {
class CRWindow;
}

class CRWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CRWindow(QWidget *parent = nullptr);
    ~CRWindow();

private:
    Ui::CRWindow *ui;
};

#endif // CRWINDOW_H
