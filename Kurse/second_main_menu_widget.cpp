#include "second_main_menu_widget.h"
#include "ui_second_main_menu_widget.h"

Second_main_menu_widget::Second_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second_main_menu_widget)
{
    ui->setupUi(this);
}

Second_main_menu_widget::~Second_main_menu_widget()
{
    delete ui;
}
