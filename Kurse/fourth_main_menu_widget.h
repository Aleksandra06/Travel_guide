#ifndef FOURTH_MAIN_MENU_WIDGET_H
#define FOURTH_MAIN_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Fourth_main_menu_widget;
}

class Fourth_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fourth_main_menu_widget(QWidget *parent = 0);
    ~Fourth_main_menu_widget();

private:
    Ui::Fourth_main_menu_widget *ui;
};

#endif // FOURTH_MAIN_MENU_WIDGET_H
