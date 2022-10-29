#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QString>
#include <QVector>
class Spreadsheet
{
public:
    Spreadsheet();

    // gets the spreadsheet properties from text file
    void getProperties();

    // updates the spreadsheet properties in text file
    void setProperties();

    // debugging method to print spreadsheet properties
    void printProperties();

    int getRowCount() { return rowCount; }
    int getColCount () { return colCount; }
    QVector<QString> getHeaders() { return headers; }
private:
    int rowCount = 0;
    int colCount = 0;
    QVector<QString> headers;

    QString toExcelCol(int colNum);
};

#endif // SPREADSHEET_H
