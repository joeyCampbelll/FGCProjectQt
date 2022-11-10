#include "filterAlgo.h"
#include "spreadsheet.h"
#include <QDebug>

FilterAlgo::FilterAlgo(Spreadsheet *spreadsheet)
{
    this->spreadsheet = spreadsheet;
    this->rowCount = spreadsheet->getRowCount();
    this->colCount = spreadsheet->getColCount();

    this->addFilterComponent("Name", "\"Joey\"");
    this->addFilterComponent("Department", "\"Math\"");
    this->addFilterComponent("Name", "\"James\"");
    this->addFilterComponent("Name", "< 26");
}

void FilterAlgo::addFilterComponent(QString colHeader, QString target)
{
    // We are assuming that the target has been formatted under these conditions:
    //   - If (targetType == "keyword") -> "target in quotes" (ex. "Associate")
    //   - If (targetType == "range") -> </> targetNum (ex. < 12 OR > 10)

    // If the filterHash already has a filter for the given colHeader
    if (filterHash.contains(colHeader))
    {
        // First, we get a copy of the component corresponding to the column
        FilterComponent *tempComponent = filterHash.value(colHeader);
        // Second, we add the target onto this copy
        tempComponent->addTarget(target);
        // Third, we insert to replace the copy
        filterHash.insert(colHeader, tempComponent);
    }
    // If the filterHash does not have a filter for the given colHeader
    else
    {
        filterHash.insert(colHeader, new FilterComponent(colHeader, target));
    }

    // now that a filter has been added, we want to reconstruct the filterString
    this->buildFilter();
}

void FilterAlgo::buildFilter()
{
    QString finalColLetter = Spreadsheet::intToExcelLetter(this->colCount - 1);

    this->filterString = "=FILTER(A2:";
    this->filterString.append(finalColLetter + QString::number(this->rowCount) + ",");


}

void FilterAlgo::printFilterHash()
{
    qDebug() << " -------------------------------------------- ";
    QHashIterator<QString, FilterComponent*> i(filterHash);

    while (i.hasNext())
    {
        i.next();
        QString temp = "| ";
        foreach(QString s, i.value()->getTargets())
        {
            temp.append(s + " | ");
        }

        qDebug() << QString(i.key()).toUtf8().constData() << ": [" << QString(temp).toUtf8().constData() << "]";
    }

    qDebug() << " -------------------------------------------- ";

}
