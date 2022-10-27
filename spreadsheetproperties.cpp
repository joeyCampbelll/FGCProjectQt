#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    qDebug() << "spreadsheet properties clicked..." << Qt::endl;
    ui->stackedWidget->setCurrentIndex(1);
}
