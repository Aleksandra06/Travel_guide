#include "third_main_menu_widget.h"
#include "ui_third_main_menu_widget.h"
#include "QMessageBox"

Third_main_menu_widget::Third_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Third_main_menu_widget)
{
    ui->setupUi(this);
    myDataBase *mdb = new myDataBase();
    db = mdb->mydb;
    this->writeTable();

    //Сигнал смены меню
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SIGNAL(change_press()));

    //Сигнал смены меню по нажатию на кнопу добавить
    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(change_press()));
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
    //ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);               // Сортировка таблицы
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);    // Порядок сортировки по умолчанию
}


void Third_main_menu_widget::on_pushButton_clicked()//добавить
{
    //должна открываться форма для изменения change_second...
    //и передаваться туда -1
    model->sort(0, Qt::AscendingOrder);
    int size = model->rowCount();
    model->insertRow(size);
    int row = model->index(size+1,0).row();



    emit send_new_row(row);
}

void Third_main_menu_widget::on_pushButton_2_clicked()//сохранить
{
    model->submitAll();
}

void Third_main_menu_widget::on_pushButton_3_clicked()//отменить
{
    writeTable();
}

void Third_main_menu_widget::on_pushButton_4_clicked()//изменить
{
    int row = model->rowCount();
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if(select->hasSelection())
        row = select->currentIndex().row();
    row = ui->tableView->model()->index(row,0).data().toInt();
    emit send_id_selected(row);
}

void Third_main_menu_widget::on_pushButton_5_clicked()//удалить
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
