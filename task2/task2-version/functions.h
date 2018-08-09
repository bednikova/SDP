#include "BinTree.h"
#include <stdlib.h>

BinTree* buildBinTree(bool isBst, int nodes)
{
    BinTree* t = new BinTree;

    for (int i = 0; i<nodes; i++) {
        if (isBst) {
            t->insertBST(rand()%100);
        } else {
            t->insert(rand()%100);
        }
    }

    return t;
}

bool IsBstImpl(node* node);
//proverqva dali dadeno dvoichno dyrvo e dvoichno naredeno
bool IsBst(BinTree *tree)
{
    // TODO: implement
    // tree->display();
    // node* rootHelp = tree->root;
    //cout << endl << root->data << "  ";
    //cout << endl << root->left->data << "  ";
    if(tree == NULL)
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
            //obhojdame dqsnoto poddyrvo
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
            //obhojdame lqvoto poddyrvo
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

//proverqva dali dadeno dvoichno dyrvo e pylno
bool IsFull()
{
    // TODO: implement
}

//poluchava proizvolno dvoichno dyrvo i go pravi dvoichno naredeno dyrvo
bool ReduceToBst()
{
    // TODO: implement
}
