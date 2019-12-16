#include "fourth_main_menu_widget.h"
#include "ui_fourth_main_menu_widget.h"

Fourth_main_menu_widget::Fourth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fourth_main_menu_widget)
{
    ui->setupUi(this);
}

Fourth_main_menu_widget::~Fourth_main_menu_widget()
{
    delete ui;
}
