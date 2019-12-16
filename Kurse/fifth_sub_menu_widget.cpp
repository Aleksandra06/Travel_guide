#include "fifth_sub_menu_widget.h"
#include "ui_fifth_sub_menu_widget.h"

Fifth_sub_menu_widget::Fifth_sub_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fifth_sub_menu_widget)
{
    ui->setupUi(this);
}

Fifth_sub_menu_widget::~Fifth_sub_menu_widget()
{
    delete ui;
}
