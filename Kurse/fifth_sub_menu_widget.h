#ifndef FIFTH_SUB_MENU_WIDGET_H
#define FIFTH_SUB_MENU_WIDGET_H

#include <QWidget>

namespace Ui {
class Fifth_sub_menu_widget;
}

class Fifth_sub_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fifth_sub_menu_widget(QWidget *parent = 0);
    ~Fifth_sub_menu_widget();

private:
    Ui::Fifth_sub_menu_widget *ui;
};

#endif // FIFTH_SUB_MENU_WIDGET_H
