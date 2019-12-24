#include "fifth_main_menu_widget.h"
#include "ui_fifth_main_menu_widget.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include<QDesktopServices>
#include "QMessageBox"

Fifth_main_menu_widget::Fifth_main_menu_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fifth_main_menu_widget)
{
    ui->setupUi(this);
    QFile *File = new QFile("C:\\Qt\\qq\\Travel_guide\\Helper\\helper.html");
    File->open(QFile::ReadOnly | QFile::Text);
    QString html = File->readAll();
    ui->textBrowser->setHtml(html);
    ui->textBrowser->setOpenLinks(false);
    ui->textBrowser->setOpenExternalLinks(false);
    File->close();

    connect(ui->textBrowser, &QTextBrowser::anchorClicked,this, &Fifth_main_menu_widget::onAnchorClicked);
}

Fifth_main_menu_widget::~Fifth_main_menu_widget()
{
    delete ui;
}

void Fifth_main_menu_widget::onAnchorClicked(const QUrl &link)
{
    QString str = link.toString();
    str.replace("%5C", "\\");
    QFile *File= new QFile(str);
    File->open(QFile::ReadOnly|QFile::Text);
    QString html = File->readAll();
    ui->textBrowser->setHtml(html);
    File->close();
}

void Fifth_main_menu_widget::on_pushButton_clicked()
{
    QFile *File= new QFile("C:\\Qt\\qq\\Travel_guide\\Helper\\helper.html");
    File->open(QFile::ReadOnly|QFile::Text);
    QString html = File->readAll();
    ui->textBrowser->setHtml(html);
    File->close();
}
