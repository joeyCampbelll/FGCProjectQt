#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_FilterHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    this->prepareFilterHistoryTableView();
}

void MainWindow::on_pushButton_BackFromFilterHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::prepareFilterHistoryTableView()
{

}

void MainWindow::parseFilterHistoryFile()
{
    QString filePath = qApp->applicationDirPath();
    filePath = filePath.mid(0, filePath.indexOf("FGCProjectQt")).append("FGCProjectQt/FGCApplication/filterhistory.txt");

    QFile file(filePath);

    if (!file.exists())
    {
        qDebug() << "File not found";
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {

    }
}
