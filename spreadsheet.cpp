#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"

void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    this->spreadsheet.printProperties();
}



void Spreadsheet::printProperties()
{
    qDebug() << this->rowCount << Qt::endl << this->colCount;
}
