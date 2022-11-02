#ifndef FILTERALGO_H
#define FILTERALGO_H
#include <QString>

class FilterAlgo
{
public:
    FilterAlgo(int rowCount, int colCount);

    void initializeFilter();
    void addFilter(QString colName, QString target, QString conjunction);

private:
    QString filterString;
};
#endif // FILTERALGO_H
