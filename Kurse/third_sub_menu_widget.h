#ifndef THIRD_SUB_MENU_WIDGET_H
#define THIRD_SUB_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Third_sub_menu_widget;
}

class Third_sub_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Third_sub_menu_widget(QWidget *parent = 0);
    ~Third_sub_menu_widget();

private:
    Ui::Third_sub_menu_widget *ui;
};

#endif // THIRD_SUB_MENU_WIDGET_H
