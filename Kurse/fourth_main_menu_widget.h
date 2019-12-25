#ifndef FOURTH_MAIN_MENU_WIDGET_H
#define FOURTH_MAIN_MENU_WIDGET_H

#include "mydatabase.h"
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
    void writeTable();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::Fourth_main_menu_widget *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

signals:
    //Передача id
    void send_id_selected(int);
    //Сигнал для третьего меню
    void change_press();

public slots:
    void rebaseTable();
};

#endif // FOURTH_MAIN_MENU_WIDGET_H
