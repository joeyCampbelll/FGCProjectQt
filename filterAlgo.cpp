#include "filterAlgo.h"
#include "spreadsheet.h"
#include <QDebug>

FilterAlgo::FilterAlgo(Spreadsheet *spreadsheet)
{
    this->spreadsheet = spreadsheet;
    this->rowCount = spreadsheet->getRowCount();
    this->colCount = spreadsheet->getColCount();

//    this->addFilterComponent("Name", "keyword", "Joey";
}

void FilterAlgo::addFilterComponent(QString colHeader, QString colTargetType, QString target)
{
    // A filter component looks something like:
    // "(J2:J161 = "Associate")", "*(K2:K161 = "F")", or "+(L2:L161 > 10)"

    //   colLetter: "J", "K", or "L"
    //   rowRange: "J2:J161", "K2:K161", or "L2:L161"
    //   target = "'Associate'", "'F'", or "> 10"
    //   conjunction = "", "*", or "+"

    //    int colIndex = this->spreadsheet->getColumnIndex(colName);
    //    QString colLetter = Spreadsheet::toExcelLetter(colIndex);


    this->filterVec.append(new FilterComponent(colHeader, target));
    this->buildFilter();
}

void FilterAlgo::buildFilter()
{
    QString finalColLetter = Spreadsheet::toExcelLetter(this->colCount - 1);


    this->filterString = "=FILTER(A2:";
    this->filterString.append(finalColLetter + QString::number(this->rowCount) + ",");

    QVector<QString> filterStrings;

    for (int i = 0; i < filterVec.size(); i++)
    {
        QString currColHeader = filterVec.at(i)->getColHeader();
        QString currTarget = filterVec.at(i)->getTarget();

        if (i == 0)
        {
        }
    }
    qDebug() << filterString;
}
