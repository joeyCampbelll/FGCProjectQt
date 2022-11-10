#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filterAlgo.h"

void MainWindow::on_pushButton_CreateFilters_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->filterAlgo = new FilterAlgo(this->spreadsheet);
}

void MainWindow::on_pushButton_BackFromCreateFilters_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::buildCreateFilters()
{

}
