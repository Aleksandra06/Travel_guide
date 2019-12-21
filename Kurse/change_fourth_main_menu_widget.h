#ifndef CHANGE_FOURTH_MAIN_MENU_WIDGET_H
#define CHANGE_FOURTH_MAIN_MENU_WIDGET_H

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

signals:

    //Сигнал возвращения
    void back_to_fourth_main_menu();
};

#endif // CHANGE_FOURTH_MAIN_MENU_WIDGET_H
