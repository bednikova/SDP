#include <iostream>
#include "Reading.h"

using namespace std;

int main()
{
    char fileName[20];
    cin >> fileName;

    cout << endl;
    if(ReadAndValidationJSONFile(fileName))
    {
        cout << "\nFile " << fileName << " is a valid JSON!\n";
    }
    else
    {
        cout << "\nFile " << fileName << " is a not valid JSON!\n";
    }

    if(isString("\"212 555-1234\"4"))
        cout << "t\n";
    cout << "f\n";



    return 0;
}
