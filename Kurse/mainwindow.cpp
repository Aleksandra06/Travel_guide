#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Выпадающий список для первой кнопки
    QMenu*       pm = new QMenu(ui->pushButton);
    pm->addAction("Готовимся к путешествию", this, SLOT(first_sub_menu()));
    pm->addAction("Путешествуем с детьми", this, SLOT(second_sub_menu()));
    pm->addAction("Путешествуем с животными", this, SLOT(third_sub_menu()));
    pm->addAction("В аэропорте и самолёте", this, SLOT(fourth_sub_menu()));
    pm->addAction("Безопастность", this, SLOT(fifth_sub_menu()));
    ui->pushButton->setMenu(pm);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//Реализация нажатия на первое подменю
void MainWindow::first_sub_menu()
{
    ui->textEdit->setText("Подменю Готовимся к путешествию");
}

//Реализация нажатия на второе подменю
void MainWindow::second_sub_menu()
{
    ui->textEdit->setText("Подменю Путешествие с детьми");
}

//Реализация нажатия на третье подменю
void MainWindow::third_sub_menu()
{
    ui->textEdit->setText("Подменю Путешествуем с животными");
}

//Реализация нажатия на четвёртое подменю
void MainWindow::fourth_sub_menu()
{
    ui->textEdit->setText("В аэропорте и самолёте");
}

//Реализация нажатия на четвёртое подменю
void MainWindow::fifth_sub_menu()
{
    ui->textEdit->setText("Безопастность");
}

//Реализация нажатия на кнопку "Список с собой"
void MainWindow::on_pushButton_2_clicked()
{
    //ui->textEdit->setText("Список с собой");
}

//Реализация нажатия на кнопку "Хочу посетить"
void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->setText("Хочу посетить");
    QPushButton *kek = new QPushButton(ui->widget);
    kek->setText("dasdas");
    kek->show();

}

//Реализация нажатия на кнопку "Посетил"
void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->setText("Посетил");
    delete(ui->widget);
}

//Реализация нажатия на кнопку "Настройки"
void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->setText("Настройки");
}
