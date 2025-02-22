#ifndef STUDENTATTENDANCEVIEW_H
#define STUDENTATTENDANCEVIEW_H

#include <QMainWindow>

namespace Ui {
class Studentattendanceview;
}

class Studentattendanceview : public QMainWindow
{
    Q_OBJECT

public:
    explicit Studentattendanceview(QWidget *parent = nullptr);
    ~Studentattendanceview();

private:
    Ui::Studentattendanceview *ui;
};

#endif // STUDENTATTENDANCEVIEW_H
