#ifndef FIFTH_MAIN_MENU_WIDGET_H
#define FIFTH_MAIN_MENU_WIDGET_H

#include <QWidget>
#include <qwidget.h>



namespace Ui {
class Fifth_main_menu_widget;
}

class Fifth_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fifth_main_menu_widget(QWidget *parent = 0);
    ~Fifth_main_menu_widget();

private:
    Ui::Fifth_main_menu_widget *ui;
private slots:
void onAnchorClicked(const QUrl &link);
void on_pushButton_clicked();
};

#endif // FIFTH_MAIN_MENU_WIDGET_H
