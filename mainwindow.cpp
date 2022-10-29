#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 525);
    ui->stackedWidget->setCurrentIndex(0);

    // BUILD SPREADSHEET - this code is in spreadsheet.cpp for organization
    this->buildSpreadsheet();

    // BUILD CREATE FILTERS
    this->buildCreateFilters();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_FilterHistory_clicked()
{
    qDebug() << "filter history clicked..." << Qt::endl;

}


void MainWindow::on_pushButton_SaveFilter_clicked()
{
    qDebug() << "save filter clicked..." << Qt::endl;
}

