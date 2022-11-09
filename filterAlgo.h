#ifndef FILTERALGO_H
#define FILTERALGO_H
#include <QString>
#include <QVector>
#include "spreadsheet.h"

class FilterComponent
{
public:
    FilterComponent(QString colHeader, QString target)
    {
        this->colHeader = colHeader;
        this->target = target;
    }

    QString getColHeader()
    {
        return colHeader;
    }

    QString getTarget()
    {
        return target;
    }

private:
    QString colHeader;
    QString target;
};

class FilterAlgo
{
public:
    FilterAlgo(Spreadsheet *spreadsheet);

    void initializeFilter();
    void addFilterComponent(QString colName, QString colTargetType, QString target);
    void buildFilter();

private:
    Spreadsheet *spreadsheet;

    QString filterString;
    QVector<FilterComponent*> filterVec;

    int rowCount;
    int colCount;
};
#endif // FILTERALGO_H
