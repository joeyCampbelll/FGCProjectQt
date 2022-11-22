#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
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

    // ----- SPREADSHEET PROPERTIES METHODS -----
    void on_pushButton_BackToHome_clicked();
    // ------------------------------------------

    // ----- CREATE FILTERS METHODS -----

    void on_pushButton_BackFromCreateFilters_clicked();

    void on_combo_ColumnHeader_activated(int index);

    void createFiltersDisableAll();

    void createFiltersUpdateFilter();

    void on_radioButton_KeywordSearch_clicked();

    void on_radioButton_RangeSearch_clicked();
    // ----------------------------------



    void on_lineEdit_KeywordEntry_returnPressed();

    void on_pushButton_EnterKeyword_clicked();

    void on_radioButton_GreaterThan_clicked();

    void on_radioButton_LessThan_clicked();

    void on_pushButton_EnterRange_clicked();

    void on_spinBox_RangeValue_textChanged(const QString &arg1);

    void on_pushButton_ClearFilter_clicked();

private:
    Ui::MainWindow *ui;
    Spreadsheet *spreadsheet;
    FilterAlgo *filterAlgo;
    FilterFinal *filterFinal;
    QStandardItemModel *spreadsheetTableModel;

    void buildSpreadsheet();
};
#endif // MAINWINDOW_H
