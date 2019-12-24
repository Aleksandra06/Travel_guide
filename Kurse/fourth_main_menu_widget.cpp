#include "fourth_main_menu_widget.h"
#include "ui_fourth_main_menu_widget.h"
#include "QMessageBox"
#include <QAbstractItemView>
#include "QSqlQuery"
Fourth_main_menu_widget::Fourth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fourth_main_menu_widget)
{
    ui->setupUi(this);
    myDataBase *mdb = new myDataBase();
    db = mdb->mydb;
    this->writeTable();

    //Привязываем сигнал изменения с кнопкой
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SIGNAL(change_press()));
}

Fourth_main_menu_widget::~Fourth_main_menu_widget()
{
    delete ui;
}

void Fourth_main_menu_widget::writeTable(){
    model = new QSqlTableModel();
    model->setTable("List_Travel");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1, Qt::Horizontal, tr("Название поездки"));
    model->setHeaderData(2, Qt::Horizontal, tr("Пометка"));
    model->select();
    model->setFilter("Visited = 1");
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->setColumnHidden(4,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
    ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
}

void Fourth_main_menu_widget::on_pushButton_clicked()//добавить
{
    model->sort(0, Qt::AscendingOrder);
    int size = model->rowCount();
    model->insertRow(size);
    model->setData(model->index(model->rowCount() - 1,4), "1");
}

void Fourth_main_menu_widget::on_pushButton_2_clicked()//сохранить
{
    model->submitAll();
}

void Fourth_main_menu_widget::on_pushButton_3_clicked()//обновить
{
    model->revertAll();
}

void Fourth_main_menu_widget::on_pushButton_4_clicked()//изменить
{
    int row = 0;
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(select->hasSelection())
        row = select->currentIndex().row();
    row = ui->tableView->model()->index(row,0).data().toInt();
    emit send_id_selected(row);
}

void Fourth_main_menu_widget::on_pushButton_5_clicked()//удалить
{
    QMessageBox ms;
    QAbstractButton *yes = ms.addButton("Да",QMessageBox::YesRole);
    QAbstractButton *no = ms.addButton("Нет",QMessageBox::NoRole);
    ms.setText("Уверены, что хотите удалить выбранную запись?");
    ms.setIcon(QMessageBox::Warning);
    ms.exec();
    if(ms.clickedButton() == yes)
    {
        int row;
        int id;
        QItemSelectionModel *select = ui->tableView->selectionModel();
        if(select->hasSelection()){
            row = select->currentIndex().row();
            model->removeRow(row);
            model->submitAll();
            id = ui->tableView->model()->index(row,0).data().toInt();
            writeTable();
        }
    }
}
