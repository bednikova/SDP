//#include "function.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
    //char fileName[30];
    //cout << "File name is: ";
    //cin >> fileName;
    //cout << endl;

    //readTree(fileName);

    //cout << endl;

    BinaryTree t;
    t.insertBst(1);
    t.insertBst(3);
    //t->insertBst(2);
    t.insertBst(4);

    t.display();

    //cout << "sum: ";
   // int sum = accumTree(t);
    //cout <<  sum  << endl;

    return 0;
}
