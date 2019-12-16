#include "first_sub_menu_widget.h"
#include "ui_first_sub_menu_widget.h"

First_sub_menu_widget::First_sub_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::First_sub_menu_widget)
{
    ui->setupUi(this);
}

First_sub_menu_widget::~First_sub_menu_widget()
{
    delete ui;
}
