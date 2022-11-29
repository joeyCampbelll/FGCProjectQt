#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filterhistory.h"
void MainWindow::on_pushButton_FilterHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

    this->filterHistory = new FilterHistory();

    this->filterHistory->buildFilterHistorySpreadsheet();

    ui->tableView_FilterHistory->setModel(this->filterHistory->getModel());
    ui->tableView_FilterHistory->horizontalHeader()->setStretchLastSection(true);

    this->filterHistory->populateFilterHistorySpreadsheet();
}

void MainWindow::on_pushButton_BackFromFilterHistory_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void FilterHistory::buildFilterHistorySpreadsheet()
{
    this->model = new QStandardItemModel();

    this->horizontalHeaders.append("Filter Name");
    this->horizontalHeaders.append("Filter Date");
    this->horizontalHeaders.append("Filter Function");

    this->model->setHorizontalHeaderLabels(this->horizontalHeaders);
}

void FilterHistory::populateFilterHistorySpreadsheet()
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

    QStandardItem *col1;
    QStandardItem *col2;
    QStandardItem *col3;

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList lineSplit = line.split("|");

        col1 = new QStandardItem(lineSplit[1]);
        col2 = new QStandardItem(lineSplit[2]);
        col3 = new QStandardItem(lineSplit[3]);

        model->appendRow( QList<QStandardItem*>() << col1 << col2 << col3);
    }


}


void MainWindow::prepareFilterHistoryTableView()
{

}

void MainWindow::parseFilterHistoryFile()
{

}
