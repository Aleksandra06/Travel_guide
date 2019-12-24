#include "change_fourth_main_menu_widget.h"
#include "fourth_main_menu_widget.h"
#include "ui_change_fourth_main_menu_widget.h"

#include <QMessageBox>

Change_fourth_main_menu_widget::Change_fourth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_fourth_main_menu_widget)
{
    ui->setupUi(this);

    //Связываем сигнал возвращения
    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(back_to_fourth_main_menu()));
}

Change_fourth_main_menu_widget::~Change_fourth_main_menu_widget()
{
    delete ui;
}

//Получение id изменяемой записи
void Change_fourth_main_menu_widget::reicive_id(int id)
{
    QString q = QString::number(id);
    ui->textEdit->setText(q);
    //сохраняем id
    selected_id = id;
    wtiteform();
}

void Change_fourth_main_menu_widget::wtiteform(){
    QString selected;
    selected.setNum(selected_id);
    model = new QSqlTableModel();
    model->setTable("List_Travel");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->select();
    model->setFilter("Id = " + selected);
    ui->label->setText(model->index(model->rowCount()-1,1).data().toString());
    ui->lineEdit->setText(model->index(model->rowCount()-1,2).data().toString());
    ui->textEdit->setText(model->index(model->rowCount()-1,3).data().toString());
}

void Change_fourth_main_menu_widget::on_pushButton_2_clicked()//сохранить
{
    QString newmark = ui->lineEdit->text();
    if(newmark!=""){
        model->setData(model->index(0,2), newmark);
    }
    ui->lineEdit->setText(model->index(0,0).data().toString());
    newmark = ui->textEdit->toPlainText();
    if(newmark!=""){
        model->setData(model->index(0,3), newmark);
    }
    model->submitAll();
    wtiteform();
}

void Change_fourth_main_menu_widget::on_pushButton_clicked()
{
    //Fourth_main_menu_widget *main = new Fourth_main_menu_widget();
    //main->writeTable();
}
