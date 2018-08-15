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




    return 0;
}
