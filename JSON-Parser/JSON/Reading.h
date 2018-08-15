#include <iostream>
#include <fstream>

using namespace std;


bool ReadAndValidationJSONFile(char* fileName)
{
    ifstream myFile(fileName);

    if(myFile)
    {
        char buff[1024];
        while(myFile.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);

            //shte podavam row na function, koqto shte go validira,
            //ako ne e validen JSON obekt shte vryshta error
        }
    }

    myFile.close();
}


void ReadJSONFileAndCreateJSONObject(char* fileName)
{
    ifstream myFile(fileName);

    if(myFile)
    {
        char buff[1024];
        while(myFile.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);

            //shte go zapisvame v strukturata, validniq veche json object
        }
    }

    myFile.close();
}
