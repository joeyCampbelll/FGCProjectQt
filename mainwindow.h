#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStandardItemModel>
#include "spreadsheet.h"
#include "filterAlgo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // ----- HOME PAGE METHODS -----
    void on_pushButton_SpeadsheetProperties_clicked();

    void on_pushButton_CreateFilters_clicked();

    void on_pushButton_FilterHistory_clicked();

    void on_pushButton_SaveFilter_clicked();
    // -----------------------------

    void on_pushButton_BackToHome_clicked();

private:
    Ui::MainWindow *ui;
    Spreadsheet *spreadsheet;
    FilterAlgo *filterAlgo;
    QStandardItemModel *tableModel;

    void buildSpreadsheet();
    void buildCreateFilters();
};
#endif // MAINWINDOW_H
