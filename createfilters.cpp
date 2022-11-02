#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filterAlgo.h"

void MainWindow::on_pushButton_CreateFilters_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->filterAlgo = new FilterAlgo(this->spreadsheet->getRowCount(), this->spreadsheet->getColCount());
}

void MainWindow::buildCreateFilters()
{

}
