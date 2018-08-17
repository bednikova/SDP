#include <iostream>
#include <fstream>
#include "Validation.h"

using namespace std;

bool helpReadAndValidate(char* fileName);

bool ReadAndValidationJSONFile(char* fileName)
{
    bool flag = true;

    ifstream myFile(fileName);

    if(myFile)
    {
        char buff;
        while(myFile.get(buff))
        {
            char object;
            object = buff;

            //test reading
            cout << object;

            if(ValidationJSONObject(object))
            {

            }
            else
            {
                flag = false;
                //cout << "\nNot valid json object\n";
            }
        }
    }
    else
    {
        cout << "Error! \n";
    }

    myFile.close();

    if(countLeftClamp != countRightClamp)
    {
        cout << "\nCount leftClamp != count rightClamp!!! \n";
        cout << "Count leftClamp { is: " << countLeftClamp << endl;
        cout << "Count rightClamp } is: " << countRightClamp << endl;

        return false;
    }
    else if(countLeftClamp1 != countRightClamp1)
    {
        cout << "\nCount leftClamp != count rightClamp!!! \n";
        cout << "Count leftClamp [ is: " << countLeftClamp1 << endl;
        cout << "Count rightClamp ] is: " << countRightClamp1 << endl;

        return false;
    }
    else if(flag == false)
    {
        if(helpReadAndValidate(fileName))
        {
            return true;
        }
        else
        {
            cout << "\nContent is not json object!\n";
            return false;
        }
    }
    else
        return true;
}


bool helpReadAndValidate(char* fileName)
{
    ifstream myFile(fileName);

    if(myFile)
    {
        char buff[1024];
        while(myFile.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);

            if(!(isString(row) || isSymbol(Trim(row)) || isNumber(Trim(row))))
            {
                cout << "\nNot valid type data! ( " << Trim(row)  << " )" << endl;
                cout << (isNumber(Trim(row)) ? "true" : "false") << endl;
                return false;
            }
            cout << row << endl;

        }
    }

    myFile.close();

    return true;

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





