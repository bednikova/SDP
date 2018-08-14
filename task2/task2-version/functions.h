#include "BinTree.h"
#include <stdlib.h>

BinTree* buildBinTree(bool isBst, int nodes)
{
    BinTree* t = new BinTree;
    for (int i = 0; i<nodes; i++)
    {
        if (isBst)
        {
            t->insertBST(rand()%100);
        }
        else
        {
            t->insert(rand()%100);
        }
    }
    return t;
}


BinTree* buildFullBinTree()
{

    BinTree* t = new BinTree;

    t->insertBST(4);
    t->insertBST(2);
    t->insertBST(6);
    t->insertBST(5);
    t->insertBST(3);
    t->insertBST(7);
    t->insertBST(1);


    return t;
}

BinTree* buildTesFullBinTree()
{

    BinTree* t = new BinTree;

    t->insertBST(50);
    t->insertBST(30);
    t->insertBST(10);
    t->insertBST(5);
    t->insertBST(20);
    t->insertBST(70);
    t->insertBST(90);
    t->insertBST(80);
    t->insertBST(100);

    return t;
}


bool IsBst(BinTree *tree)
{
    if(tree->root == NULL)
        return false;
    return tree->IsBstImpl(tree->root);
}


bool IsFull(BinTree *tree)
{
    if(tree->root == NULL)
        return false;
    return tree->IsFullImpl(tree->root);
}


void ReduceToBst(BinTree*& tree)
{
    int i = 1;
    while(!IsBst(tree))
    {
        tree->ReduceToBstImpl(tree->root);
        cout << "step " << i << endl;
        tree->displayTree();
        cout << endl << endl;
        ++i;
    }
}
