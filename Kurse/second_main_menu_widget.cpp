#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"

#include "mainwindow.h"
#include "QMessageBox"

#include "second_sub_menu_widget.h"

Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("C:\\DataBase.db");
    db.setDatabaseName("C:\\Qt\\KEKW\\Travel_guide\\BaseData\\DataBase.db");
    if(!db.open()){
        QMessageBox::warning(0, QObject::tr("Ошибка"),
                                     QObject::tr("Ошибка подключения к базе!!!"));
    }
    else{
        this->writeTable();
    }




    //Привязываем сигнал изменения с кнопкой
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SIGNAL(change_press()));
}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}

void Second_main_menu_widget::writeTable(){
    model = new QSqlTableModel();
    model->setTable("List_Things");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setHeaderData(1, Qt::Horizontal, tr("Название списка"));
    model->setHeaderData(2, Qt::Horizontal, tr("Пометка"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
}

void Second_main_menu_widget::on_pushButton_clicked()
{
//переход в вкладку демонстрации списка
}

void Second_main_menu_widget::on_pushButton_2_clicked()//Сохранить изменения
{
    model->submitAll();
}

void Second_main_menu_widget::on_pushButton_3_clicked()//Отменить изменения
{
    writeTable();
}
