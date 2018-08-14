#include<iostream>
#include<iomanip>

using namespace std;

#ifndef __BINTREE_H__
#define __BINTREE_H__

struct node
{
    int data;
    node* left;
    node* right;
};

class BinTree
{
    public:
        BinTree();
        ~BinTree();

        void insert(int x);
        void insertBST(int x);
        void remove(int x);
        void display();
        void displayTree();

        node* findMin(node* t);
        node* findMax(node* t);
        node* remove(int x, node* t);

        void ReduceToBstImpl(node*& node);
        bool IsFullImpl(node* node);
        bool IsBstImpl(node* node);

        node* getRoot();

        node* root;

    private:

        void inorder(node* t);

        node* find(node* t, int x);
        node* insertBST(int x, node* t);
        node* makeEmpty(node* t);
        node* insert(int x, node* t);
        int heightOfBinTree(node* node);

        void displayTreeImpl(node* n, int);


        node* Delete(node *root, int data);
        int FindMaxBinaryTree(node* root);

};



#endif
