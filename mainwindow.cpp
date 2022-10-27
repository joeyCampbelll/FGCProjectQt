#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 525);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    qDebug() << "spreadsheet properties clicked..." << Qt::endl;
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_CreateFilters_clicked()
{
    qDebug() << "create filters clicked..." << Qt::endl;

}


void MainWindow::on_pushButton_FilterHistory_clicked()
{
    qDebug() << "filter history clicked..." << Qt::endl;

}


void MainWindow::on_pushButton_SaveFilter_clicked()
{
    qDebug() << "save filter clicked..." << Qt::endl;
}

