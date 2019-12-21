#ifndef THIRD_MAIN_MENU_WIDGET_H
#define THIRD_MAIN_MENU_WIDGET_H

#include <QSqlDatabase>
#include <QSqlTableModel>
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

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Third_main_menu_widget *ui;
    QSqlDatabase db;
    void writeTable();
    QSqlTableModel *model;
};

#endif // THIRD_MAIN_MENU_WIDGET_H
