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

private:
    Ui::AdminTeacher_Edit *ui;
};

#endif // ADMINTEACHER_EDIT_H
