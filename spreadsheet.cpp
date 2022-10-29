#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spreadsheet.h"
#include "QDir.h"

Spreadsheet::Spreadsheet() {}

void MainWindow::on_pushButton_SpeadsheetProperties_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

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
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith("rowCount"))
        {
            this->rowCount = line.split("-")[1].trimmed().toInt();
        }

        if (line.startsWith("colCount"))
        {
            this->colCount = line.split("-")[1].trimmed().toInt();
        }
    }
}

void Spreadsheet::printProperties()
{
    qDebug() << this->rowCount << Qt::endl << this->colCount;
}

QString Spreadsheet::toExcelCol(int colNum)
{
    int digit1 = colNum % 26;
    int digit2 = colNum / 26;

    QString result;
    if (colNum > 26)
    {
        result.push_back(digit2 + 'A' - 1);
    }
    result.push_back(digit1 + 'A');
    return result;
}
