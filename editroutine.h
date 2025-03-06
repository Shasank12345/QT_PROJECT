#ifndef EDITROUTINE_H
#define EDITROUTINE_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
//#include<loginWindow.h>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

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

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

public:
    void popu();

private:
    Ui::EditRoutine *ui;
};

#endif // EDITROUTINE_H
