#ifndef CHANGE_FOURTH_MAIN_MENU_WIDGET_H
#define CHANGE_FOURTH_MAIN_MENU_WIDGET_H

#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class Change_fourth_main_menu_widget;
}

class Change_fourth_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Change_fourth_main_menu_widget(QWidget *parent = 0);
    ~Change_fourth_main_menu_widget();

private:
    Ui::Change_fourth_main_menu_widget *ui;
    //переменная для хранения id выделенной строки
    int selected_id;
    QSqlTableModel *model;
    void wtiteform();

signals:
    //Сигнал возвращения
    void back_to_fourth_main_menu();

public slots:
    //получение id
    void reicive_id(int id);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // CHANGE_FOURTH_MAIN_MENU_WIDGET_H
