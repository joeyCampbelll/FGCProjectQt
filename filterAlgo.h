#ifndef FILTERALGO_H
#define FILTERALGO_H
#include <QString>
#include <QHash>
#include "spreadsheet.h"


class FilterAlgo
{
public:
    FilterAlgo(Spreadsheet *spreadsheet);

    void initializeFilter();
    void addFilterComponent(QString colName, QString colTargetType, QString target, QString conjunction);
    void buildFilter();

private:
    Spreadsheet *spreadsheet;

    QString filterString;
    QHash<QString, QString> filterMap;

    int rowCount;
    int colCount;
};
#endif // FILTERALGO_H
