#ifndef EDITROUTINE_H
#define EDITROUTINE_H

#include <QMainWindow>

namespace Ui {
class EditRoutine;
}

class EditRoutine : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditRoutine(QWidget *parent = nullptr);
    ~EditRoutine();

private slots:
    void on_EditRoutine_iconSizeChanged(const QSize &iconSize);

private:
    Ui::EditRoutine *ui;
};

#endif // EDITROUTINE_H
