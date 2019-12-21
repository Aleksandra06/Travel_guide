#include "change_third_main_menu_widget.h"
#include "ui_change_third_main_menu_widget.h"

Change_third_main_menu_widget::Change_third_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_third_main_menu_widget)
{
    ui->setupUi(this);

    //Связываем сигнал возвращения
    connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(back_to_third_main_menu()));
}

Change_third_main_menu_widget::~Change_third_main_menu_widget()
{
    delete ui;
}
