#ifndef SECOND_MAIN_MENU_WIDGET_H
#define SECOND_MAIN_MENU_WIDGET_H

#include "mydatabase.h"
#include <QTSql>
#include <QStandardItem>

namespace Ui {
class Second_main_menu_widget;
}

class Second_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Second_main_menu_widget(QWidget *parent = 0);
    ~Second_main_menu_widget();
    void writeTable();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::Second_main_menu_widget *ui;

    QSqlDatabase db;
    QSqlTableModel *model;

signals:
    //Передача id
    void send_id_selected(int);
    //Сигнал для второго меню
    void change_press();
};

#endif // SECOND_MAIN_MENU_WIDGET_H
