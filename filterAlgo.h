#ifndef FILTERALGO_H
#define FILTERALGO_H
#include <QString>
#include <QVector>
#include <QHash>
#include "spreadsheet.h"

class FilterComponent
{
public:
    FilterComponent(QString colHeader, QString initialTarget)
    {
        this->colHeader = colHeader;
        this->targets.append(initialTarget);
    }


    QString getColHeader() { return colHeader; }

    QVector<QString> getTargets() { return targets; }

    QString getFilterString() { return filterString; }

    void addTarget(QString targetToAdd) { this->targets.append(targetToAdd); }

private:
    QString filterString;
    QString colHeader;
    QVector<QString> targets;
};

class FilterAlgo
{
public:
    FilterAlgo(Spreadsheet *spreadsheet);

    void initializeFilter();
    void addFilterComponent(QString colHeader, QString target);
    void buildFilter();
    void printFilterHash();

private:
    Spreadsheet *spreadsheet;

    QString filterString;
//    QVector<FilterComponent*> filterVec;

    QHash<QString, FilterComponent*> filterHash;

    int rowCount;
    int colCount;
};
#endif // FILTERALGO_H
