#include "filterAlgo.h"
#include "spreadsheet.h"
#include <QDebug>

FilterAlgo::FilterAlgo(Spreadsheet *spreadsheet)
{
    this->spreadsheet = spreadsheet;
    this->rowCount = spreadsheet->getRowCount();
    this->colCount = spreadsheet->getColCount();

//    this->addFilterComponent("Rank", "= \"Full\"");
//    this->addFilterComponent("Dept", "= \"Mathematics/Computer Science\"");
//    this->addFilterComponent("Dept", "= \"MICS\"");
//    this->addFilterComponent("Rank", "= \"Associate\"");

//    this->addFilterComponent("Name", " = \"Morgan Professor 22\"");
//    this->addFilterComponent("Name", " = \"Luke Professor 1\"");

//    this->addFilterComponent("Name", "< 26");

}

void FilterAlgo::filterStart()
{
    addFilterComponent(this->colHeaderCreateFilters, this->targetCreateFilters);
}

void FilterAlgo::addFilterComponent(QString colHeader, QString target)
{
    // We are assuming that the target has been formatted under these conditions:
    //   - If (targetType == "keyword") -> "target in quotes" (ex. "= "Associate"")
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
    // -----------------------------------------
    // This code is used to handle the beginning of the filter string
    //   ex. "=FILTER(A2:Y161, "
    // It dynamically changes the filter range based on the # of cols and rows

    // the last column of the spreadsheet (this is a letter)
    QString finalColLetter = Spreadsheet::intToExcelLetter(this->colCount - 1);

    // the last row in the spreadsheet (this is a number)
    QString finalRowNumber = QString::number(this->rowCount);
    this->filterString = "=FILTER(A2:";
    this->filterString.append(finalColLetter + finalRowNumber + ", ");
    // -----------------------------------------


    QHashIterator<QString, FilterComponent*> i(filterHash);
    while (i.hasNext())
    {
        i.next();

        // ex. Count, org_id, Name, Dept
        QString currColName = i.key();
        // ex. A, B, C, ... AA, AB ... CA ...
        QString currColLetter = this->spreadsheet->headerToExcelLetter(currColName);
        // ex. E2:E161
        QString currColRange = currColLetter + "2:" + currColLetter + finalRowNumber;

        // If the column has multiple targets (i.e. multiple keywords)
        if (i.value()->getTargets().size() > 1)
        {
            this->filterString.append("(");
            foreach(QString target, i.value()->getTargets())
            {
                this->filterString.append("(" + currColRange + " " + target + ") + ");
            }
            filterString.remove(filterString.length() - 3, filterString.length());

            filterString.append(")");
        }
        // if the column has only one target
        else
        {
            this->filterString.append("(" + currColRange + " " + i.value()->getTargets().at(0) + ")");
        }

        // If i.hasNext() == true, then there is another filter to be added on
        if (i.hasNext())
        {
            this->filterString.append(" * ");
        }
        // If i.hasNext() == false, we close the filter by adding a ', "")' to the end
        else
        {
            this->filterString.append(", \"\")");
        }
    }

//    qDebug() << QString(this->filterString).toUtf8().constData();
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
