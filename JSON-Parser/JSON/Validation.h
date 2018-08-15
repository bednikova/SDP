#include <iostream>
#include <string.h>

using namespace std;

int countLeftClamp = 0;
int countRightClamp = 0;
int countLeftClamp1 = 0;
int countRightClamp1 = 0;

bool ValidationJSONObject(char content)
{

    if(content == '{')
    {
        ++countLeftClamp;
        return true;
    }
    else if(content == '}')
    {
        ++countRightClamp;
        return true;
    }
    else if(content == '[')
    {
        ++countLeftClamp1;
        return true;
    }
    else if(content == ']')
    {
         ++countRightClamp1;
         return true;
    }
    else if(  isdigit(content)  || content == '\\' || content == '\"'
            || isalpha(content) || content == ',' || content == '\n'
            || content == ':' || content == '\t'  || content == ' '
            || content == '\r' || content == '\0' || content == '\r\n'
            || content == '\a' || content == '\v' || content == '\f')
    {
         return true;
    }


    //cout << "Error content is a: " << content << endl << endl;
    return false;
}
