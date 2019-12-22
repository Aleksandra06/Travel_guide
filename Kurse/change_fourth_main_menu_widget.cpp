#include "change_fourth_main_menu_widget.h"
#include "ui_change_fourth_main_menu_widget.h"

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
}
