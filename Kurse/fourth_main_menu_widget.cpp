#include "fourth_main_menu_widget.h"
#include "ui_fourth_main_menu_widget.h"
#include "QMessageBox"

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

void Fourth_main_menu_widget::on_pushButton_clicked()//добавить
{
    //должна открываться форма для изменения change_second...
    //и передаваться туда -2
}

void Fourth_main_menu_widget::on_pushButton_2_clicked()//сохранить
{
    model->submitAll();
}

void Fourth_main_menu_widget::on_pushButton_3_clicked()//обновить
{
    writeTable();
}


//Передача ID по нажатию на кнопку изменить
void Fourth_main_menu_widget::on_pushButton_4_clicked()//изменить
{
    int row;
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(select->hasSelection())
        row = select->currentIndex().row();

    row = ui->tableView->model()->index(row,0).data().toInt();
    emit send_id_selected(row);
}

void Fourth_main_menu_widget::on_pushButton_5_clicked()//удалить
{
    //отрывается диалоговое окно "вы точно хотите удалить". Если да, то работаем дальше по тому коду, если нет, то идем нафиг
    //не знаю как работают диалоговые окна. Если его отдельно надо создавать, то лучше сделать так. чтоб туда строка с вопросом передавалась. ПОтому что могут быть и другие вопросы
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
