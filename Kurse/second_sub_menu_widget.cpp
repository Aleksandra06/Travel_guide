#include "second_sub_menu_widget.h"
#include "ui_second_sub_menu_widget.h"

second_sub_menu_widget::second_sub_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::second_sub_menu_widget)
{
    ui->setupUi(this);
}

second_sub_menu_widget::~second_sub_menu_widget()
{
    delete ui;
}
