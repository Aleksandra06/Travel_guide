#ifndef THIRD_MAIN_MENU_WIDGET_H
#define THIRD_MAIN_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Third_main_menu_widget;
}

class Third_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Third_main_menu_widget(QWidget *parent = 0);
    ~Third_main_menu_widget();

private:
    Ui::Third_main_menu_widget *ui;
};

#endif // THIRD_MAIN_MENU_WIDGET_H
