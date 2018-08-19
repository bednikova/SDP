#include "BinaryTree.h"
#include <stdlib.h>
#include <fstream>



int accumTree(BinaryTree* t)
{
    return t->accumTree();
}

void bloomTree(BinaryTree*& t)
{
    t->bloomTree();
}


BinaryTree* buildBinTree(int nodes)
{
    BinaryTree* t = new BinaryTree;
    for (int i = 0; i<nodes; i++)
    {
        t->insertBst(rand()%100);
    }
    return t;
}


void readTree()//BinaryTree*& tree)
{
    cout << "File name is: ";
    char fileName[30];
    cin >> fileName;
    ifstream myFile(fileName);

    if(myFile)
    {
        int x;
        char c;
        while(myFile.get(c))
        {
            if(c == '(' )
                if(myFile >> x)
                    cout << x << endl;
            else if(c == ')')
            {

            }
/*
            if(c == '(' )
            {
                int x;char symbol;
                while(myFile >> x)
                    cout << x << endl;
                if(myFile >> x)
                    cout << x << endl;
                    //naslednici na tekush vryh
                else
                {
                    cout << "null\n";
                }
            }
            else if(c == ')')
            {
                //se vryshtash nazad
            }
            else
            {
                int x;
                while(myFile >> x)
                    cout << x << endl;
            }
*/
        }
    }

    myFile.close();
}
