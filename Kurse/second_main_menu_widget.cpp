#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"
<<<<<<< HEAD
#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include <QString>
    //#include <QSqlRelation>
#include <QSqlTableModel>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

/*#define ACCESS "DRIVER={Microsoft Access Driver (*.mdb)};" \
    "FIL={MS Access};DBQ=C:\\Qt\\d\\Travel_guide\\BaseData\\DataBase.mdb"*/
=======
#include "QMessageBox"
#include <QDebug>
#include <QStandardItem>

>>>>>>> 75dd06bce0f02e6b393c8cd48f8360b649a2bdb9
Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{
    ui->setupUi(this);
<<<<<<< HEAD


    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Qt\\d\\Travel_guide\\BaseData\\DataBase.mdb");
    db.open();


    QSqlTableModel *mModel = new QSqlTableModel(this);
    mModel->setTable("Travel");
    mModel->select();
    ui->tableView->setModel(mModel);
    /*QSqlQuery query;



    query.exec("SELECT Id FROM Travel");
    query.next();
    QString NameTravel = query.value(0).toString();
    ui->label_2->setText(NameTravel);*/



    /*db = QSqlDatabase::addDatabase("QODBS");
    db.setDatabaseName(ACCESS);
    db.setUserName("root");
    db.setPassword("");
=======
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\DataBase.db");
>>>>>>> 75dd06bce0f02e6b393c8cd48f8360b649a2bdb9
    if(!db.open()){
        qDebug() << db.lastError().text();
        QMessageBox::warning(0, QObject::tr("Ошибка"),
                                     QObject::tr("Ошибка подключения к базе!!!"));
    }
    else{
<<<<<<< HEAD
        ui->label_2->setText("ok");
        //QDebug ()<<"Seccess";
        //QSqlDatabase defaultDB = QSqlDatabase::database();
       // QSqlTableModel  model;
   //     model.setQuery("SELECT * FROM Things");
        for (int i = 0; i < model.rowCount(); ++i) {
                 int id = model.record(i).value("Id").toString();
                 QString nameTravel = model.record(i).value("NameTravel").toInt();
                 QString info = model.record(i).value("Information").toString();
                 qDebug() << id << nameTravel << info;
             }*/
       /* for (int i = 0; i < model.rowCount(); ++i) {
                 int id = model.record(i).value("Id").toInt();
                 QString nameTravel = model.record(i).value("NameTravel").toString();
                 QString info = model.record(i).value("Information").toString();
                 qDebug() << id << name;
        }*/
       // model.setTable("Things");
        //model->setRelation(2, QSqlRelation("city", "id", "name"));
        //model->setRelation(3, QSqlRelation("country", "id", "name"));
       // tableViewThings = new QTableView;
       // tableViewThin.setModel(model);
       // view->show();


=======
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
>>>>>>> 75dd06bce0f02e6b393c8cd48f8360b649a2bdb9
}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}
