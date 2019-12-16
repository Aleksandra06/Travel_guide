#ifndef SECOND_SUB_MENU_WIDGET_H
#define SECOND_SUB_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class second_sub_menu_widget;
}

class second_sub_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit second_sub_menu_widget(QWidget *parent = 0);
    ~second_sub_menu_widget();

private:
    Ui::second_sub_menu_widget *ui;
};

#endif // SECOND_SUB_MENU_WIDGET_H
