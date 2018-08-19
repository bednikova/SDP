#include "BinaryTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void readTree(char* fileName)
{
    ifstream myFile(fileName);

    if(myFile)
    {
        char c;
        while(myFile.get(c))
        {
            if(c == '(')
            {
                //naslednici na tekush vryh

            }

            if(c == ')')
            {
                //se vryshtash na gore
            }

            if(c != '(' && c != ')' && c != ' ')
            {
                cout << c << " ";
            }

        }

    }

    cout << endl;
    myFile.close();
}



int accumTree(BinaryTree* tree)
{
    return tree->accumTreeImpl();
}
