#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"

Spreadsheet::Spreadsheet() {}

void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_BackToHome_clicked()
{
//    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_BackFromEditSpreadsheet_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::buildSpreadsheet()
{
    this->spreadsheet = new Spreadsheet();
    this->spreadsheet->getProperties();

//    // creating model for spreadsheet tableview
//    this->spreadsheetTableModel = new QStandardItemModel(this->spreadsheet->getRowCount(),
//                                              this->spreadsheet->getColCount(),
//                                              this);
//    QVector<QString> tempVec = this->spreadsheet->getHeaders();
//    for (int i = 0; i < tempVec.length(); i++)
//    {
//        this->spreadsheetTableModel->setHorizontalHeaderItem(i, new QStandardItem(tempVec.at(i)));
//    }

//    ui->table_spreadsheet->setModel(this->spreadsheetTableModel);
    QString numOfCols = "# of Cols: ";
    numOfCols.append(QString::number(this->spreadsheet->getColCount()));
    this->ui->label_NumOfCols->setText(numOfCols);

    this->ui->spinBox_NumOfRows->setValue(this->spreadsheet->getRowCount());

    QVector<QString> tempVec = this->spreadsheet->getHeaders();
    QString colHeaders = "";
    for (int i = 0; i < tempVec.length(); i++)
    {
        colHeaders.append(tempVec[i] + "\n");
    }

    this->ui->textEdit_ColEdit->insertPlainText(colHeaders);
}

// This method accesses the spreadsheet.txt file and retrieves
//   the necessary spreadsheet data
void Spreadsheet::getProperties()
{
    QString filePath = qApp->applicationDirPath();
    filePath = filePath.mid(0, filePath.indexOf("FGCProjectQt")).append("FGCProjectQt/FGCApplication/spreadsheet.txt");

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
        QString line = in.readLine();

        if (line.startsWith("rowCount"))
        {
            this->rowCount = line.split("-")[1].trimmed().toInt();
        }

        if (line.startsWith("colCount"))
        {
            this->colCount = line.split("-")[1].trimmed().toInt();
        }

        if (line.startsWith("-- COL HEADERS --"))
        {
            for (int i = 0; i < this->colCount; i++)
            {
                this->headers.append(in.readLine());
            }
        }
    }
}

// --- DEBUGGING ---
void Spreadsheet::printProperties()
{
    qDebug() << this->rowCount << Qt::endl << this->colCount;
}
// ----------------


// --- UTILITY METHODS ---
int Spreadsheet::getColumnIndex(QString headerName)
{
    return this->headers.indexOf(headerName);
}

QString Spreadsheet::intToExcelLetter(int num)
{
    int digit1 = num % 26;
    int digit2 = num / 26;

    QString result;
    if (num > 26)
    {
        result.push_back(digit2 + 'A' - 1);
    }
    result.push_back(digit1 + 'A');
    return result;
}

QString Spreadsheet::headerToExcelLetter(QString headerName)
{
    return intToExcelLetter(getColumnIndex(headerName));
}
// -----------------------
