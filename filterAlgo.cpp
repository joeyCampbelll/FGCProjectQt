#include "filterAlgo.h"
#include "spreadsheet.h"
#include <QDebug>

FilterAlgo::FilterAlgo(int rowCount, int colCount)
{
    QString colLetter = Spreadsheet::toExcelLetter(colCount);

    this->filterString = "=FILTER(A2,";
    this->filterString.append(colLetter + QString::number(rowCount) + ",");

    qDebug() << filterString;

}
