#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include "QString.h"
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

private:
    int rowCount = 0;
    int colCount = 0;

    QString toExcelCol(int colNum);
};

#endif // SPREADSHEET_H
