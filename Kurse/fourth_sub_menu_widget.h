#ifndef FOURTH_SUB_MENU_WIDGET_H
#define FOURTH_SUB_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Fourth_sub_menu_widget;
}

class Fourth_sub_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fourth_sub_menu_widget(QWidget *parent = 0);
    ~Fourth_sub_menu_widget();

private:
    Ui::Fourth_sub_menu_widget *ui;
};

#endif // FOURTH_SUB_MENU_WIDGET_H
