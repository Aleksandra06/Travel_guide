#include "change_second_main_menu_widget.h"
#include "ui_change_second_main_menu_widget.h"
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
   ui->textEdit->setText(q);

   //сохраняем id
   selected_id = id;
}
