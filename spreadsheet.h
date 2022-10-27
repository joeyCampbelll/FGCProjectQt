#ifndef SPREADSHEET_H
#define SPREADSHEET_H

class Spreadsheet
{
public:
    void printProperties();
    void updateProperties();

private:
    int rowCount = 0;
    int colCount = 0;

};

#endif // SPREADSHEET_H
