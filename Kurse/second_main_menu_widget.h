#ifndef SECOND_MAIN_MENU_WIDGET_H
#define SECOND_MAIN_MENU_WIDGET_H

/*#include <QTableView>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QSqlQuery>
#include <QDebug>*/
#include <QTSql>
#include <QDebug>

namespace Ui {
class Second_main_menu_widget;
}

class Second_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Second_main_menu_widget(QWidget *parent = 0);
    ~Second_main_menu_widget();

private:
    Ui::Second_main_menu_widget *ui;
    QSqlDatabase db;
};

#endif // SECOND_MAIN_MENU_WIDGET_H
