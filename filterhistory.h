#ifndef FILTERHISTORY_H
#define FILTERHISTORY_H
#include <QStandardItemModel>

class FilterHistory
{
public:
    void buildFilterHistorySpreadsheet();
    void populateFilterHistorySpreadsheet();

    QStandardItemModel* getModel() { return this->model; }
private:
    QStandardItemModel *model;
    QStringList horizontalHeaders;
};

#endif // FILTERHISTORY_H
