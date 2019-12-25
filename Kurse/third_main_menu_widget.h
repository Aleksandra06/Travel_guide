#ifndef THIRD_MAIN_MENU_WIDGET_H
#define THIRD_MAIN_MENU_WIDGET_H

#include "mydatabase.h"
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
    void writeTable();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::Third_main_menu_widget *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

signals:
    //Передача новой строки
    void send_new_row(int);
    //Передача id
    void send_id_selected(int);
    //сигнал для третьего меню
    void change_press();

public slots:
    void rebaseTable();
};

#endif // THIRD_MAIN_MENU_WIDGET_H
