#ifndef CHANGE_SECOND_MAIN_MENU_WIDGET_H
#define CHANGE_SECOND_MAIN_MENU_WIDGET_H

#include <QSqlTableModel>
#include <QWidget>
#include "mydatabase.h"

namespace Ui {
class Change_second_main_menu_widget;
}

class Change_second_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Change_second_main_menu_widget(QWidget *parent = 0);
    //int row_select;
    ~Change_second_main_menu_widget();

private:
    Ui::Change_second_main_menu_widget *ui;
    //переменная для хранения id выделенной строки
    int selected_id;
    QSqlTableModel *model;
    void wtiteTableThings();

signals:
    //Сигнал возвращения
    void back_to_second_main_menu();

public slots:
    //получение id
    void reicive_id(int id);
private slots:
    void on_pushButton_2_clicked();
};

#endif // CHANGE_SECOND_MAIN_MENU_WIDGET_H
