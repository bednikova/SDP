#include <iostream>

using namespace std;


#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

class BinaryTree
{
    public:
        BinaryTree() : root(NULL) {}

        ~BinaryTree()
        {
            root = makeEmpty(root);
        }


        void insertBst(int x)
        {
            root = insertBst(x, root);
        }

        void display()
        {
            inorder(root);
            cout << endl;
        }

    private:

        struct Node;

        void inorder(Node* r)
        {
            if(r == NULL)
                return;
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }


        Node* insertBst(int x, Node* t)
        {
            if(t == NULL)
            {
                t = new Node;
                t->data = x;
                t->left = t->right = NULL;

            }
            else if(x < t->data)
                t->left = insertBst(x, t->left);
            else if(x > t->data)
                t->right = insertBst(x, t->right);
            else
                return t;
        }

        Node* makeEmpty(Node* t)
        {
            if(t == NULL)
                return NULL;
            else
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }

            return NULL;
        }

    private:

        struct Node
        {
            int data;
            Node* left;
            Node* right;

            Node(int data = 0, Node* left = NULL, Node* right = NULL) : data(data), left(left), right(right) {}
        };

        Node* root;

};
#endif
