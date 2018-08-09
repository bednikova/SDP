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

    if(n == m)
        return 0;

    return 1;

}


bool IsFullImpl(node* node)
{
    if(heightOfBinTree(node) == 1)
        return false;

    if((node != NULL) &&
       (((node->left == NULL) && (node->right != NULL)) ||
        ((node->left != NULL) && (node->right == NULL))))
        return false;
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
