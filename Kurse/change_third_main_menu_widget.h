#ifndef CHANGE_THIRD_MAIN_MENU_WIDGET_H
#define CHANGE_THIRD_MAIN_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Change_third_main_menu_widget;
}

class Change_third_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Change_third_main_menu_widget(QWidget *parent = 0);
    ~Change_third_main_menu_widget();

private:
    Ui::Change_third_main_menu_widget *ui;
    //переменная для хранения id выделенной строки
    int selected_id;
signals:
    //Сигнал возвращения
    void back_to_third_main_menu();
public slots:
    //получение id
    void reicive_id(int id);
};

#endif // CHANGE_THIRD_MAIN_MENU_WIDGET_H
