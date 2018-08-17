#include <iostream>
#include <string.h>

using namespace std;

int countLeftClamp = 0;
int countRightClamp = 0;
int countLeftClamp1 = 0;
int countRightClamp1 = 0;


char* LTrim(char* szX)
{
    if((' '==szX[0]) || ('\t'==szX[0]) || ('\f'==szX[0]) ||
       ('\r'==szX[0]) || ('\v'==szX[0]) || ('\n'==szX[0]))
    while(' '== szX[0]) { ++szX;}

    return szX;
}

char* RTrim(char* szX)
{
    int i = strlen(szX);
    while ((' '==szX[i]) || ('\t' == szX[i]) || ('\v'==szX[i]) ||
           ('\f'==szX[i])  || ('\r'==szX[i]) || ('\n'==szX[i]))
    {
        szX[i] = 0;
        --i;

    }

    return szX;
}

char* Trim(char* szX)
{
    szX = LTrim(szX);
    szX = RTrim(szX);
    return szX;
}


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


bool isNumber(char* data)
{
    int len = strlen(data);


    for(int index = 0; index < len; ++index)
    {
        if(isalpha(data[index]))
        {
            return false;
        }
    }

    for(int index = 0; index < len; ++index)
    {
        if((data[index] == '\"') || (data[index] == ' '))
        {
            return false;
        }
    }

    int count = 0;
    for(int index = 0; index < len; ++index)
    {
        if(data[index] == '.')
        {
            ++count;
        }
    }

    if(count > 1)
    {
        return false;
    }

    if((data[0] == '-') || (data[0] == '+') || isdigit(data[0]))
    {
        for(int index = 1; index < len-1; ++index)
        {
            if(!isdigit(data[index]) && data[index] != '.' && data[index] != ',')
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool isString(char* content)
{
    int len = strlen(content);
    int count = 0;


    for(int index = 0; index < len; ++index)
    {
        if(content[index] == '\"')
        {
            ++count;
        }
        if(content[0] == '\"' && content[index] == '\"' && (content[index+1] == ':' || content[index+1] == ','))
        {
            //cout << "\nContent is a string: " << content << endl;
            return true;
        }
        if(content[0] == '\"' && content[len-1] == '\"' && content[len] != ':' && content[len] != ',')
        {
            cout << "\nZavyrshva sys znak razliceh ot : ili ," << content[index+1] << "\ncqloto sydyrjanie e " << content << "\n";
            return false;
        }
        if(content[0] == '\"' && content[len-1] == '\"')
        {
            //cout << "\nContent is a string: " << content << endl;
            return true;
        }
    }

    if(count > 2)
    {
        //cout << "\nContent is a string: " << content << endl;
        return true;
    }

    return false;
}


bool isSymbol(char* content)
{
    int len = strlen(content);


    for(int index = 0; index < len; ++index)
    {
        if((content[index] == '\"') || (content[index] == '\t')
           || (content[index] == ':') || (content[index] == ' ')
           || (content[index] == ',') || (content[index] == '{')
           || (content[index] == '}') || (content[index] == '[')
           || (content[index] == ']') || (content[index] == '\n')
           || (content[index] == '\r\n') || (content[index] == '\r')
           || (content[index] == '\a') || (content[index] == '\v')
           || (content[index] == '\f') || (content[index] == '\0'))
        {

        }
        else
        {
            //cout << "ne validniq simvol e " << content[index] << " a ne validnoto sydyrjanie e "
           //      << content << endl;
            return false;
        }
    }

    //cout << "\nContent is a symbol: " << content << endl;
    return true;
}
