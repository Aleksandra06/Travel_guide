#include "third_main_menu_widget.h"
#include "ui_third_main_menu_widget.h"

Third_main_menu_widget::Third_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Third_main_menu_widget)
{
    ui->setupUi(this);
}

Third_main_menu_widget::~Third_main_menu_widget()
{
    delete ui;
}
