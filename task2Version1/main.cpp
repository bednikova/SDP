#include <istream>
#include "functions.h"

using namespace std;

int main()
{
    BinTree<int> t;
    t.insertBst(4);
    t.insertBst(1);
    t.insertBst(3);
    t.insertBst(5);
    t.displayTree();
    cout << endl;
    //t.IsBstI();
    //t.IsFull();
    t.ReduceToBst();
    t.displayTree();


    return 0;
}
