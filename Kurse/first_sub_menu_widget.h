#ifndef FIRST_SUB_MENU_WIDGET_H
#define FIRST_SUB_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class First_sub_menu_widget;
}

class First_sub_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit First_sub_menu_widget(QWidget *parent = 0);
    ~First_sub_menu_widget();

private:
    Ui::First_sub_menu_widget *ui;
};

#endif // FIRST_SUB_MENU_WIDGET_H
