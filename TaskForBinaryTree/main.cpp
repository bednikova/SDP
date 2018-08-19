#include "function.h"

using namespace std;

int main()
{
    char fileName[30];
    cout << "File name is: ";
    cin >> fileName;
    cout << endl;

    readTree(fileName);

    return 0;
}
