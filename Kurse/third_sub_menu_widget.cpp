#include "third_sub_menu_widget.h"
#include "ui_third_sub_menu_widget.h"

Third_sub_menu_widget::Third_sub_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Third_sub_menu_widget)
{
    ui->setupUi(this);
}

Third_sub_menu_widget::~Third_sub_menu_widget()
{
    delete ui;
}
