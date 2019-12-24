#include "change_second_main_menu_widget.h"
#include "second_main_menu_widget.h"
#include "ui_change_second_main_menu_widget.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <iostream>

Change_second_main_menu_widget::Change_second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_second_main_menu_widget)
{
    ui->setupUi(this);
    //Связываем сигнал возвращения
    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(back_to_second_main_menu()));
}

Change_second_main_menu_widget::~Change_second_main_menu_widget()
{
    delete ui;
}

//Получение id изменяемой записи
void Change_second_main_menu_widget::reicive_id(int id)
{
   QString q = QString::number(id);
   //сохраняем id
   selected_id = id;
   wtiteTableThings();
}

void Change_second_main_menu_widget::wtiteTableThings(){
    QString selected;
    selected.setNum(selected_id);
    model = new QSqlTableModel();
    model->setTable("Things");
    model->setEditStrategy(QSqlTableModel::OnRowChange);

    QSqlTableModel *md = new QSqlTableModel();
    md->setTable("List_Things");
    md->select();
    md->setFilter("Id = " + selected);
    QString name;
    name = md->index(md->rowCount()-1,1).data().toString();
    ui->label->setText(name);

    model->setHeaderData(1, Qt::Horizontal, tr("Список"));
    model->select();
    model->setFilter("IdListThings = " + selected);
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(2,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

void Change_second_main_menu_widget::on_pushButton_2_clicked()
{
    QString newThing = ui->lineEdit->text();
    if(newThing!=""){
        model->insertRow(model->rowCount());
        model->setData(model->index(model->rowCount() - 1,1), newThing);
        QString si;
        si.setNum(selected_id);
        model->setData(model->index(model->rowCount() - 1,2), si);
        model->submitAll();
        wtiteTableThings();
    }
}

void Change_second_main_menu_widget::on_pushButton_clicked()
{
    Second_main_menu_widget *main = new Second_main_menu_widget();
    main->writeTable();
}
