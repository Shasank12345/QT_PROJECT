#ifndef ADMINSTUDENT_EDIT_H
#define ADMINSTUDENT_EDIT_H

#include <QDialog>

namespace Ui {
class AdminStudent_Edit;
}

class AdminStudent_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit AdminStudent_Edit(QWidget *parent = nullptr);
    ~AdminStudent_Edit();

private:
    Ui::AdminStudent_Edit *ui;
};

#endif // ADMINSTUDENT_EDIT_H
