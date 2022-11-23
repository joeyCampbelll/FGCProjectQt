#ifndef FILTERALGO_H
#define FILTERALGO_H
#include <QString>
#include <QVector>
#include <QHash>
#include <QDate>
#include "spreadsheet.h"

class FilterFinal
{
public:
    FilterFinal(QString filterName, QDate filterDate, QString filterString)
    {
        this->filterName = filterName;
        this->filterDate = filterDate;
        this->filterString = filterString;
    }

private:
    QString filterName;
    QDate filterDate;
    QString filterString;
};

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
    void filterStart();
    void addFilterComponent(QString colHeader, QString target);
    void buildFilter();
    void printFilterHash();

    void setColHeaderCreateFilters(QString colHeader) { this->colHeaderCreateFilters = colHeader; }
    void setTargetCreateFilters(QString target) { this->targetCreateFilters = target; }

    QString getFilterString() { return this->filterString; }
    QString getreadableFilterString() { return this->readableFilterString; }

    bool getHasFilterBeenAdded() { return this->hasFilterBeenAdded; }

private:
    Spreadsheet *spreadsheet;
    QString filterString;
    QString readableFilterString;
    QHash<QString, FilterComponent*> filterHash;

    int rowCount;
    int colCount;

    QString colHeaderCreateFilters;
    QString targetCreateFilters;

    bool hasFilterBeenAdded = false;
};
#endif // FILTERALGO_H
