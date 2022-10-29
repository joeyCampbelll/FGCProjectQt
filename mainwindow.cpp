#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 525);
    ui->stackedWidget->setCurrentIndex(0);

    // BUILD SPREADSHEET
    this->spreadsheet = new Spreadsheet();
    this->spreadsheet->getProperties();

    this->spreadsheet->getColCount();

    // creating model for spreadsheet tableview
    this->tableModel = new QStandardItemModel(this->spreadsheet->getRowCount(),
                                              this->spreadsheet->getColCount(),
                                              this);
    this->tableModel->setHorizontalHeaderItem(0, new QStandardItem("test\nA"));
    ui->table_spreadsheet->setModel(this->tableModel);
}

MainWindow::~MainWindow()
{
    delete ui;
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

