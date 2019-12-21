#ifndef SECOND_MAIN_MENU_WIDGET_H
#define SECOND_MAIN_MENU_WIDGET_H

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

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Second_main_menu_widget *ui;
    QSqlDatabase db;
    void writeTable();
    QSqlTableModel *model;
};

#endif // SECOND_MAIN_MENU_WIDGET_H
