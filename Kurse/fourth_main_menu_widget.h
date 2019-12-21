#ifndef FOURTH_MAIN_MENU_WIDGET_H
#define FOURTH_MAIN_MENU_WIDGET_H

#include <QSqlDatabase>
#include <QSqlTableModel>
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

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Fourth_main_menu_widget *ui;
    QSqlDatabase db;
    void writeTable();
    QSqlTableModel *model;
};

#endif // FOURTH_MAIN_MENU_WIDGET_H
