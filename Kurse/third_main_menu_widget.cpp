#include "third_main_menu_widget.h"
#include "ui_third_main_menu_widget.h"
#include "QMessageBox"

Third_main_menu_widget::Third_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Third_main_menu_widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\DataBase.db");
    if(!db.open()){
        QMessageBox::warning(0, QObject::tr("Ошибка"),
                                     QObject::tr("Ошибка подключения к базе!!!"));
    }
    else{
        this->writeTable();
    }
}

Third_main_menu_widget::~Third_main_menu_widget()
{
    delete ui;
}

void Third_main_menu_widget::writeTable(){
    model = new QSqlTableModel();
    model->setTable("List_Travel");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setHeaderData(1, Qt::Horizontal, tr("Название поездки"));
    model->setHeaderData(2, Qt::Horizontal, tr("Информация"));
    model->select();
    model->setFilter("Visited = 0");
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
}

void Third_main_menu_widget::on_pushButton_clicked()
{
    //перейти во вкладку добавления
}

void Third_main_menu_widget::on_pushButton_2_clicked()
{
    model->submitAll();
}

void Third_main_menu_widget::on_pushButton_3_clicked()
{
    writeTable();
}
