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

    // takes in a header name, returns the corresponding column index
    int getColumnIndex(QString headerName);

    // takes in a number, returns the corresponding alphabet character
    //   passed Z -> AA, AB, AC ... BA, BB, BC ... AAA, AAB
    static QString intToExcelLetter(int num);

    QString headerToExcelLetter(QString headerName);

    int getRowCount() { return rowCount; }
    int getColCount () { return colCount; }
    QVector<QString> getHeaders() { return headers; }
private:
    int rowCount = 0;
    int colCount = 0;
    QVector<QString> headers;


};

#endif // SPREADSHEET_H
