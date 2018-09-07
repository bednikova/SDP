#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node
{
    char data;
    Node* l;
    Node* c;
    Node* r;

    Node(char data, Node* l = NULL, Node* c = NULL, Node* r = NULL) : data(data), l(l), c(c), r(r) {}
};


void addNode(Node*& list, char x, char c = 'c')
{
    Node* n = new Node(x);
    if(!list)
    {
        list = n;
    }
    else
    {
        Node* t = list;
        if(c == 'l')
        {
            t->l = n;
        }
        else if(c == 'c')
        {
            t->c = n;
        }
        else if(c == 'r')
        {
            t->r = n;
        }
    }
}

void printTree(Node* list, int i = 0)
{
    if(!list)
        return;
    i = i + 5;
    cout << setw(i-5) << list->data << endl;
    printTree(list->l, i);
    printTree(list->c, i);
    printTree(list->r, i);
}

int height(Node* t)
{
    if(!t)
        return 0;

    int l = 0, c = 0, r = 0;
    l = height(t->l);
    c = height(t->c);
    r = height(t->r);

    return ((((c > r) ? c : r) > l ) ? ((c > r) ? c : r)+1 : l+1);
}

void saveTree(Node* tree)
{
    ofstream mf("tree.txt", ios::app);
    if(mf)
    {
        if(!tree)
        {
            mf << "()";
            return;
        }
        mf << "(" << tree->data;
        mf.close();
        saveTree(tree->l);
        saveTree(tree->c);
        saveTree(tree->r);
        ofstream mf("tree.txt", ios::app);
        mf << ")";
    }

    mf.close();
}

void readTree(Node* tree)
{
    int h = height(tree);

    if(!tree)
        return;
    if(h == 1)
        cout << tree->data;

    readTree(tree->l);
    readTree(tree->c);
    readTree(tree->r);
}
