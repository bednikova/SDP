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




BinTree* buildFullBinTreeTest1()
{

    BinTree* t = new BinTree;

    t->insertBST(3);
    t->insertBST(1);
    t->insertBST(0);
    t->insertBST(2);
    t->insertBST(5);
    t->insertBST(4);
    t->insertBST(9);
    t->insertBST(6);
    t->insertBST(10);


    return t;
}


BinTree* buildFullBinTreeTest2()
{

    BinTree* t = new BinTree;

    t->insertBST(5);
    t->insertBST(3);
    t->insertBST(2);
    t->insertBST(4);
    t->insertBST(10);
    t->insertBST(8);
    t->insertBST(6);
    t->insertBST(9);
    t->insertBST(11);


    return t;
}


BinTree* buildFullBinTreeTest3()
{

    BinTree* t = new BinTree;

    t->insertBST(10);
    t->insertBST(3);
    t->insertBST(2);
    t->insertBST(5);
    t->insertBST(4);
    t->insertBST(6);
    t->insertBST(15);
    t->insertBST(11);
    t->insertBST(16);


    return t;
}


BinTree* buildFullBinTreeTest4()
{

    BinTree* t = new BinTree;

    t->insertBST(6);
    t->insertBST(5);
    t->insertBST(1);
    t->insertBST(2);
    t->insertBST(0);
    t->insertBST(4);
    t->insertBST(7);
    t->insertBST(8);
    t->insertBST(9);


    return t;
}

bool IsBstImpl(node* node);
bool IsBst(BinTree *tree)
{
    if(tree->root == NULL)
        return false;
    return IsBstImpl(tree->root);
}

bool IsBstImpl(node* node)
{
    if((node == NULL) || ((node->left == NULL) && (node->right == NULL)))
    {
        return true;
    }
    else if((node->left == NULL) && (node->right != NULL))
    {
        if(node->right->data < node->data)
        {
            return false;
        }
        else
        {
            IsBstImpl(node->right);
        }

    }
    else if((node->left != NULL) && (node->right == NULL))
    {
        if(node->left->data > node->data)
        {
            return false;
        }
        else
        {
            IsBstImpl(node->left);
        }

    }
    else if((node->left->data > node->data) || (node->right->data < node->data))
    {
        return false;
    }
    else
    {
        IsBstImpl(node->left);
        IsBstImpl(node->right);
    }

    return true;
}


int heightOfBinTree(node* node)
{
    int n, m;

    if(node == NULL)
        return 0;

    n = heightOfBinTree(node->left);
    m = heightOfBinTree(node->right);

    if(n > m)
        return n+1;

    return m+1;

}


bool IsFullImpl(node* node)
{

    if((node == NULL) || ((node->left == NULL) && (node->right == NULL)))
    {
        return true;
    }
    else if(heightOfBinTree(node->left) != heightOfBinTree(node->right))
    {
        cout << "Height leftTree != height rightTree! \n";
        return false;
    }
    else if(((node->left == NULL) && (node->right != NULL)) ||
        ((node->left != NULL) && (node->right == NULL)))
       {
           cout << "leftTree or rightTree is a empty tree \n";
            return false;
       }
    else
    {
        IsFullImpl(node->left);
        IsFullImpl(node->right);
    }

    return true;

}



//proverqva dali dadeno dvoichno dyrvo e pylno
bool IsFull(BinTree *tree)
{
    if(tree->root == NULL)
        return false;
    return IsFullImpl(tree->root);
}

//poluchava proizvolno dvoichno dyrvo i go pravi dvoichno naredeno dyrvo
bool ReduceToBst()
{
    // TODO: implement
}
