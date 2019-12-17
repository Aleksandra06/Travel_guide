#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlRelation>
#include <QSqlTableModel>
#define ACCESS "DRIVER={Microsoft Access Driver (*.mdb)};" \
    "FIL={MS Access};DBQ=C:\\DataBase.accdb"
Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{

    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QODBS");
    db.setDatabaseName(ACCESS);
    db.setUserName("root");
    db.setPassword("");
    if(!db.open()){
        //qDebug()<<db.lastError().text();
        //db.lastError().showMessage();
        //вывод сообщения об ошибке подкючения к бд
    //    QMessageBox::critical(this, "Error", db.lastError().text());
        ui->label_2->setText("huinya1");
    }
    else{
        ui->label_2->setText("ok");
        //QDebug ()<<"Seccess";
        //QSqlDatabase defaultDB = QSqlDatabase::database();
       // QSqlTableModel  model;
   //     model.setQuery("SELECT * FROM Things");
      /*  for (int i = 0; i < model.rowCount(); ++i) {
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

    }

}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}
