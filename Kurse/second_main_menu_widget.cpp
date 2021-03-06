#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"
#include "second_sub_menu_widget.h"

#include "mainwindow.h"
#include "QMessageBox"
#include <QAbstractItemView>
#include "QSqlQuery"


Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{
    ui->setupUi(this);
    myDataBase *mdb = new myDataBase();
    db = mdb->mydb;
    this->writeTable();
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
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1, Qt::Horizontal, tr("Название списка"));
    model->setHeaderData(2, Qt::Horizontal, tr("Пометка"));
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
    ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
}

void Second_main_menu_widget::on_pushButton_clicked()//Добавить новый
{
    model->sort(0, Qt::AscendingOrder);
    int size = model->rowCount();
    model->insertRow(size);
}

void Second_main_menu_widget::on_pushButton_2_clicked()//Сохранить изменения
{
    model->submitAll();

}

void Second_main_menu_widget::on_pushButton_3_clicked()//Отменить изменения
{
    model->revertAll();
}

void Second_main_menu_widget::on_pushButton_4_clicked()//изменить
{
    int row = 0;
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(select->hasSelection())
        row = select->currentIndex().row();
    row = ui->tableView->model()->index(row,0).data().toInt();
    emit send_id_selected(row);
}

void Second_main_menu_widget::on_pushButton_5_clicked()//удалить
{
     //Диалоговое окно подтверждающее удаление выделенного элемента
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
            QSqlTableModel *mod = new QSqlTableModel();
            mod->setTable("Things");
            int n = mod->rowCount();
            for (int i = 0; i<n; i++){
                if(mod->index(i,2).data().toInt() == id){
                    mod->removeRow(i);
                    i--;
                    n--;
                }
            }
            mod->submitAll();
            writeTable();
        }
    }
}
