#include "fourth_sub_menu_widget.h"
#include "ui_fourth_sub_menu_widget.h"

Fourth_sub_menu_widget::Fourth_sub_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fourth_sub_menu_widget)
{
    ui->setupUi(this);
}

Fourth_sub_menu_widget::~Fourth_sub_menu_widget()
{
    delete ui;
}
