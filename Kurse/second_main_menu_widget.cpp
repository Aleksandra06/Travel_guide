#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"
#include "QMessageBox"
#include <QDebug>
#include <QStandardItem>

Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\DataBase.db");
    if(!db.open()){
        qDebug() << db.lastError().text();
        QMessageBox::warning(0, QObject::tr("Ошибка"),
                                     QObject::tr("Ошибка подключения к базе!!!"));
    }
    else{
        //Осуществляем запрос
        QSqlQuery *query = new QSqlQuery();
        query->exec("SELECT Thing, Mark FROM Things");
        qDebug() << query->lastError().text();
        QSqlRecord rec  = query->record();
        //Создаем модель, в которую поместим данные, а после закинем ее в таблицу
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *item;
        //Заголовки столбцов
        QStringList horizontalHeader;
        horizontalHeader.append("Название списка");
        horizontalHeader.append("Пометка");
        model->setHorizontalHeaderLabels(horizontalHeader);
        int row = 0;//счетчик строк
        QString name, inf, visit;
        while (query->next())
        {
            QString Thing = query->value(0).toString();
            QString Mark = query->value(1).toString();
            item = new QStandardItem(Thing);
            model->setItem(row, 0, item);
            item = new QStandardItem(Mark);
            model->setItem(row, 1, item);
            row = row+1;
        }
        ui->tableView->setModel(model);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
    }
}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}
