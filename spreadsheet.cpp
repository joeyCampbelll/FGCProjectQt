#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"

Spreadsheet::Spreadsheet() {}

void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

// This method accesses the spreadsheet.txt file and retrieves
//   the necessary spreadsheet data
void Spreadsheet::getProperties()
{

}

void Spreadsheet::printProperties()
{
    qDebug() << this->rowCount << Qt::endl << this->colCount;
}
