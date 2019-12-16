#include "fifth_main_menu_widget.h"
#include "ui_fifth_main_menu_widget.h"

Fifth_main_menu_widget::Fifth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fifth_main_menu_widget)
{
    ui->setupUi(this);
}

Fifth_main_menu_widget::~Fifth_main_menu_widget()
{
    delete ui;
}
