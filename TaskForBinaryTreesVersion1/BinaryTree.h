#include <iostream>
#include <iomanip>

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
            std::cout << std::endl;
        }

        int accumTree()
        {
            return accumTreeImpl(root);
        }

        void displayTree()
        {
            displayTreeImpl(root);
        }

        void bloomTree()
        {
            bloomTreeImpl(root);
        }


    private:
        struct Node;

        void bloomTreeImpl(Node*& t)
        {
            if(t == NULL)
                return;
            else if(!t->left && !t->right)
            {
                t->left = new Node;
                t->left->data = t->data;
                t->left->left = t->left->right = NULL;
                t->right = new Node;
                t->right->data = t->data;
                t->right->left = t->right->right = NULL;
                return;
            }
            else
            {
                bloomTreeImpl(t->left);
                bloomTreeImpl(t->right);
            }
        }

        void displayTreeImpl(Node* t, int i = 0)
        {
            i = i + 5;
            if(t == NULL)
                return;

            if(t->right)
                displayTreeImpl(t->right,i);
            std::cout << setw(i) << t->data << std::endl;
            if(t->left)
                displayTreeImpl(t->left,i);
        }


        int accumTreeImpl(Node* t)
        {
            if(t == NULL)
                return 0;
            else if(!t->left && t->right)
                return t->data + accumTreeImpl(t->right);
            else if(t->left && !t->right)
                return t->data + accumTreeImpl(t->left);
            else if(!t->right && !t->left)
                return t->data;
            else
                return t->data + accumTreeImpl(t->left) + accumTreeImpl(t->right);
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

        void inorder(Node* t)
        {
            if(t == NULL)
                return;

            inorder(t->left);
            std::cout << t->data << " ";
            inorder(t->right);

        }

    private:

        struct Node
        {
            int data;
            Node* left;
            Node* right;

            Node() : data(0), left(NULL), right(NULL) {}
            Node(int data, Node* left = NULL, Node* right = NULL) : data(data), left(left), right(right) {}
        };

        Node* root;

};
#endif
