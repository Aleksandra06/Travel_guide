#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"

#include <QStandardItem>
//#include <QApplication>
//#include <QMessageBox>
//#include <QSqlRelation>
//#include <QSqlTableModel>

Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{

    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QODBC","Context");
    db.setDatabaseName("DRIVER={SQL Server}; SERVER=ALEKSANDRA-ПК;DATABASE=TravelBD;Trusted_Connection=Yes;");
    db.setUserName("user");
    db.setPassword("user...");

    if(!db.open()){
        //вывод сообщения об ошибке подкючения к бд надо сделать
        qDebug() << db.lastError().text();
        ui->label_2->setText("Ошибка подключения к базе данных");
    }
    else{
        //Осуществляем запрос
        QSqlQuery query;
        query.exec("SELECT * FROM TravelTable");
        QSqlRecord rec  = query.record();

        //QStandardItemModel *model = new QStandardItemModel;
        //QStandardItem *item;
        //Заголовки столбцов
        QStringList horizontalHeader;
        horizontalHeader.append("Список вещей");
        horizontalHeader.append("Пометка");
       // model->setHorizontalHeaderLabels(horizontalHeader);
        //Выводим значения из запроса
        int row = 0;

        QString name, inf, visit;
        while (query.next())
        {
            name = query.value(rec.indexOf("NameTravel")).toString();
         //   qDebug() << name;
      //  QString Thing = query.value(0).toString();
      //  QString Mark = query.value(1).toString();
     //   item=new QStandardItem(Thing);
      //  model->setData(model->index(0,row), Thing);
     //   qDebug() << Thins.text();
        //model->setItem(row,0,item);
 //       item=new QStandardItem(Mark);
        //model->setItem(row,1,item);
        row = row+1;
         ui->label_2->setText("2");
        }
        ui->label_2->setText("row.toString()");
        //ui->tableView->setModel(model);

        //ui->tableView->resizeRowsToContents();
        //ui->tableView->resizeColumnsToContents();
    }

}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}
