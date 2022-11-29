#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filterAlgo.h"
#include <QInputDialog>
// ----- GENERAL FUNCTIONS ------
void MainWindow::on_pushButton_CreateFilters_clicked()
{
    // first, set the stacked widget to the createfilters menu
    ui->stackedWidget->setCurrentIndex(3);

    // create a new filterAlgo instance
    this->filterAlgo = new FilterAlgo(this->spreadsheet);

    // Populate the colHeaders combobox
    QVector<QString> colHeaders = this->spreadsheet->getHeaders();

    ui->combo_ColumnHeader->clear();

    foreach(QString header, colHeaders)
    {
        ui->combo_ColumnHeader->addItem(header);
    }

    ui->combo_ColumnHeader->setCurrentIndex(-1);
    ui->textEdit_FilterPreview->clear();
    createFiltersDisableAll();
}

void MainWindow::on_pushButton_BackFromCreateFilters_clicked()
{
    if (this->filterAlgo->getHasFilterBeenAdded() == true)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Back to main menu", "Are you sure you want to leave the filter before saving?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
             ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_ClearFilter_clicked()
{
    if (this->filterAlgo->getHasFilterBeenAdded() == true)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Clear Filter", "Are you sure you want to clear the filter?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
          on_pushButton_CreateFilters_clicked();
        }
    }
}


void MainWindow::on_pushButton_SaveFilter_clicked()
{
    // if there is no filter to save, don't do anything
    if (this->filterAlgo->getHasFilterBeenAdded() == false)
    {
        return;
    }

    // get the filter name through the input dialog box
    QString filterName = QInputDialog::getText(this,"Name","Enter a filter name...");

    // if the user doesn't enter anything, call it <no name>
    if (filterName == "")
    {
        filterName = "<no name>";
    }

    // get current date and make a FilterFinal object
    QDate currentDate = QDate::currentDate();
    this->filterFinal = new FilterFinal(filterName, currentDate, this->filterAlgo->getFilterString());

    // ---- WRITING TO SAVE FILE ----
    QString filePath = qApp->applicationDirPath();
    filePath = filePath.mid(0, filePath.indexOf("FGCProjectQt")).append("FGCProjectQt/FGCApplication/filterhistory.txt");

    QFile file(filePath);

    if (!file.exists())
    {
        qDebug() << "File not found";
    }

    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
       return;
    }

    QTextStream out(&file);

    out << "| " << filterName << " | " << currentDate.toString() << " | " << this->filterAlgo->getFilterString() << " |\n";

    ui->stackedWidget->setCurrentIndex(0);

    ui->textEdit_ActualFilter->clear();
    ui->textEdit_ReadableFilter->clear();

    ui->textEdit_ActualFilter->appendPlainText(this->filterAlgo->getFilterString());
    ui->textEdit_ReadableFilter->appendPlainText(this->filterAlgo->getReadableFilterString());
}
// --------------------------------------------

// ----- COLUMN HEADER GROUP METHODS ------

void MainWindow::on_combo_ColumnHeader_activated(int index)
{
    this->filterAlgo->setColHeaderCreateFilters(this->spreadsheet->getHeaders().at(index));

    createFiltersDisableAll();
    ui->radioButton_KeywordSearch->setEnabled(true);
    ui->radioButton_RangeSearch->setEnabled(true);
}

void MainWindow::on_radioButton_KeywordSearch_clicked()
{
    ui->lineEdit_KeywordEntry->setEnabled(true);
    ui->pushButton_EnterKeyword->setEnabled(true);

    // disable range search radio button
    ui->radioButton_RangeSearch->setAutoExclusive(false);
    ui->radioButton_RangeSearch->setChecked(false);
    ui->radioButton_RangeSearch->setAutoExclusive(false);

    // disable greater than radio button
    ui->radioButton_GreaterThan->setAutoExclusive(false);
    ui->radioButton_GreaterThan->setChecked(false);
    ui->radioButton_GreaterThan->setAutoExclusive(true);
    ui->radioButton_GreaterThan->setEnabled(false);

    // disable less than radio button
    ui->radioButton_LessThan->setAutoExclusive(false);
    ui->radioButton_LessThan->setChecked(false);
    ui->radioButton_LessThan->setAutoExclusive(true);
    ui->radioButton_LessThan->setEnabled(false);

    // disable spin box and range enter button
    ui->spinBox_RangeValue->setEnabled(false);
    ui->spinBox_RangeValue->clear();
    ui->pushButton_EnterRange->setEnabled(false);
}

void MainWindow::on_radioButton_RangeSearch_clicked()
{
    ui->radioButton_GreaterThan->setEnabled(true);
    ui->radioButton_LessThan->setEnabled(true);

    // disable keyword search radio button
    ui->radioButton_KeywordSearch->setAutoExclusive(false);
    ui->radioButton_KeywordSearch->setChecked(false);
    ui->radioButton_KeywordSearch->setAutoExclusive(false);

    ui->lineEdit_KeywordEntry->setEnabled(false);
    ui->lineEdit_KeywordEntry->clear();
    ui->pushButton_EnterKeyword->setEnabled(false);
}

// --------------------------------------------------

// ------- KEYWORD GROUP METHODS ------

void MainWindow::on_lineEdit_KeywordEntry_returnPressed()
{
    on_pushButton_EnterKeyword_clicked();
}

void MainWindow::on_pushButton_EnterKeyword_clicked()
{
    QString keywordTarget = ui->lineEdit_KeywordEntry->text();

    if (keywordTarget.isEmpty())
    {
        return;
    }

    keywordTarget.push_front("= \"");
    keywordTarget.append("\"");

    ui->lineEdit_KeywordEntry->clear();

    this->filterAlgo->setTargetCreateFilters(keywordTarget);

    createFiltersUpdateFilter();
}

// -----------------------------------------

// ----- RANGE SEARCH GROUP -----

void MainWindow::on_radioButton_GreaterThan_clicked()
{
    ui->spinBox_RangeValue->setEnabled(true);
    ui->pushButton_EnterRange->setEnabled(true);
}

void MainWindow::on_radioButton_LessThan_clicked()
{
    ui->spinBox_RangeValue->setEnabled(true);
    ui->pushButton_EnterRange->setEnabled(true);
}

void MainWindow::on_spinBox_RangeValue_textChanged(const QString &arg1)
{
    ui->pushButton_EnterRange->setEnabled(true);
}

void MainWindow::on_pushButton_EnterRange_clicked()
{
    QString rangeTarget = "";
    if (ui->radioButton_GreaterThan->isChecked())
    {
        rangeTarget.append("> ");
    }
    else if (ui->radioButton_LessThan->isChecked())
    {
        rangeTarget.append("< ");
    }

    rangeTarget.append(QString::number(ui->spinBox_RangeValue->value()));

    this->filterAlgo->setTargetCreateFilters(rangeTarget);

    createFiltersUpdateFilter();
}
// ------------------------------------------



void MainWindow::createFiltersUpdateFilter()
{
    this->filterAlgo->filterStart();

    ui->textEdit_FilterPreview->clear();
    ui->textEdit_FilterPreview->insertPlainText(this->filterAlgo->getReadableFilterString() + "\n\n" + this->filterAlgo->getFilterString());

    ui->combo_ColumnHeader->setCurrentIndex(-1);
    createFiltersDisableAll();
}

void MainWindow::createFiltersDisableAll()
{
    // ----- HEADER COMBO -----
    ui->radioButton_KeywordSearch->setAutoExclusive(false);
    ui->radioButton_KeywordSearch->setChecked(false);
    ui->radioButton_KeywordSearch->setAutoExclusive(false);

    ui->radioButton_RangeSearch->setAutoExclusive(false);
    ui->radioButton_RangeSearch->setChecked(false);
    ui->radioButton_RangeSearch->setAutoExclusive(false);

    ui->radioButton_KeywordSearch->setEnabled(false);
    ui->radioButton_RangeSearch->setEnabled(false);

    // ----- KEYWORD SEARCH ------
    ui->lineEdit_KeywordEntry->setEnabled(false);
    ui->pushButton_EnterKeyword->setEnabled(false);

    // ----- RANGE SEARCH ------

    ui->radioButton_GreaterThan->setAutoExclusive(false);
    ui->radioButton_GreaterThan->setChecked(false);
    ui->radioButton_GreaterThan->setAutoExclusive(true);

    ui->radioButton_LessThan->setAutoExclusive(false);
    ui->radioButton_LessThan->setChecked(false);
    ui->radioButton_LessThan->setAutoExclusive(true);

    ui->radioButton_GreaterThan->setEnabled(false);
    ui->radioButton_LessThan->setEnabled(false);
    ui->spinBox_RangeValue->setEnabled(false);
    ui->pushButton_EnterRange->setEnabled(false);
}
