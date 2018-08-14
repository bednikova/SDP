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

BinTree* buildTestNotFullBinTree()
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
    t->insertBST(40);
    t->insertBST(60);
    t->insertBST(55);
    t->insertBST(41);
    t->insertBST(39);


    /* added node -> tree is full
    //t->insertBST(41);
    t->insertBST(61);
    //t->insertBST(39);
    */

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
    //int i = 1;
    while(!IsBst(tree))
    {
        tree->ReduceToBstImpl(tree->root);
        //cout << "Step " << i << endl;
        //tree->displayTree();
        //cout << endl << endl;
        //++i;
    }
}

void test1IsBstTree()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 1: " << endl;
    BinTree* testBinTree = buildBinTree(true, 6);
    cout << "Tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nIsBst: " << (IsBst(testBinTree) ? "true" : "false" ) << endl;
    cout << "-------------------------------------------------------------\n";
}

void test2IsBstTree()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 2: function IsBst()" << endl;
    BinTree* testBinTree = buildBinTree(false, 6);
    cout << "Tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nIsBst: " << (IsBst(testBinTree) ? "true" : "false" ) << endl;
    cout << "-------------------------------------------------------------\n";
}


void test1IsFullTree()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 1: function IsFull() " << endl;
    BinTree* testBinTree = buildFullBinTree();
    cout << "Tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nIsFull: " << (IsFull(testBinTree) ? "true" : "false") << endl;
    cout << "-------------------------------------------------------------\n";
}

void test2IsFullTree()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 2: function IsFull()" << endl;
    BinTree* testBinTree = buildTestNotFullBinTree();
    cout << "Tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nIsFull: " << (IsFull(testBinTree) ? "true" : "false") << endl;
    cout << "-------------------------------------------------------------\n";
}

void test1FunctionReduceToBst()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 1: function ReduceToBst()" << endl;
    BinTree* testBinTree = buildBinTree(false, 7);
    cout << "Original tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nReduceToBst: " << endl;
    ReduceToBst(testBinTree);
    cout << "Final tree: \n\n\n";
    testBinTree->displayTree();
    cout << "-------------------------------------------------------------\n";
}

void test2FunctionReduceToBst()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 2: function ReduceToBst()" << endl;
    BinTree* testBinTree = buildBinTree(false, 7);
    cout << "Original tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nReduceToBst: " << endl;
    ReduceToBst(testBinTree);
    cout << "Final tree: \n\n\n";
    testBinTree->displayTree();
    cout << "-------------------------------------------------------------\n";
}


void test3FunctionReduceToBst()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Test 3: function ReduceToBst()" << endl;
    BinTree* testBinTree = buildBinTree(true, 7);
    cout << "Original tree is: \n\n\n";
    testBinTree->displayTree();
    cout << "\n\n\nReduceToBst: " << endl;
    ReduceToBst(testBinTree);
    cout << "Final tree: \n\n\n";
    testBinTree->displayTree();
    cout << "-------------------------------------------------------------\n";
}
