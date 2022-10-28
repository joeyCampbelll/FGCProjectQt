#ifndef SPREADSHEET_H
#define SPREADSHEET_H

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

private:
    int rowCount = 0;
    int colCount = 0;
};

#endif // SPREADSHEET_H
