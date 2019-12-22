#include "fourth_main_menu_widget.h"
#include "ui_fourth_main_menu_widget.h"
#include "QMessageBox"

Fourth_main_menu_widget::Fourth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fourth_main_menu_widget)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("C:\\DataBase.db");
    db.setDatabaseName("C:\\Qt\\qq\\Travel_guide\\BaseData\\DataBase.db");
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

Fourth_main_menu_widget::~Fourth_main_menu_widget()
{
    delete ui;
}

void Fourth_main_menu_widget::writeTable(){
    model = new QSqlTableModel();
    model->setTable("List_Travel");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setHeaderData(1, Qt::Horizontal, tr("Название поездки"));
    model->setHeaderData(2, Qt::Horizontal, tr("Информация"));
    model->select();
    model->setFilter("Visited = 1");
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
}

void Fourth_main_menu_widget::on_pushButton_clicked()
{
    //перейти во вкладку добавления
}

void Fourth_main_menu_widget::on_pushButton_2_clicked()
{
    model->submitAll();
}

void Fourth_main_menu_widget::on_pushButton_3_clicked()
{
    writeTable();
}


//Передача ID по нажатию на кнопку изменить
void Fourth_main_menu_widget::on_pushButton_4_clicked()
{
    int row;
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(select->hasSelection())
        row = select->selectedRows().first().row();

    row = ui->tableView->model()->index(row,0).data().toInt();
    emit send_id_selected(row);
}
