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
}

MainWindow::~MainWindow()
{
    delete ui;
}
