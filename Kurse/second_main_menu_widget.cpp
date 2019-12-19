#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"
#include "QMessageBox"
#include <QDebug>

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
        this->writeTable();
    }
}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}

void Second_main_menu_widget::writeTable(){
    model = new QSqlTableModel();
    model->setTable("List_Things");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, tr("Название списка"));
    model->setHeaderData(1, Qt::Horizontal, tr("Пометка"));
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void Second_main_menu_widget::on_pushButton_clicked()
{

}
