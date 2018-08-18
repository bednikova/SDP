#include <iostream>
#include <iomanip>

using namespace std;

#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

template <class T>
class BinarySearchTree
{
    public:

        BinarySearchTree() : root(NULL) {}

        ~BinarySearchTree()
        {
            root = makeEmpty(root);
        }

        void displayTree()
        {
            displayTreeImpl(root);
        }

        void insert(const T& x)
        {
            root = insert(x, root);
        }

        void remove(const T& x)
        {
            root = remove(x, root);
        }

        void display() //const
        {
            inorder(root);
            std::cout << endl;
        }

        void search(const T& x)
        {
            root = find(root, x);
        }


    private:

        struct Node;

        void displayTreeImpl(Node* root, int i = 0)
        {
            if(root != NULL)
            {
                i = i + 5;
                if(root->right != NULL)
                    displayTreeImpl(root->right, i);
                std::cout << setw(i) << root->data << endl;
                if(root->left != NULL)
                    displayTreeImpl(root->left, i);
            }
        }

        Node* makeEmpty(Node* t)
        {
            if(t == NULL)
            {
                return NULL;
            }
            else
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }

            return NULL;
        }

        Node* insert(const T& x, Node* t)
        {
            if(t == NULL)
            {
                t = new Node;
                t->data = x;
                t->left = t->right = NULL;
            }
            else if(x < t->data)
            {
                t->left = insert(x, t->left);
            }
            else if(x > t->data)
            {
                t->right = insert(x, t->right);
            }
            return t;
        }

        Node* findMin(Node* t)
        {
            if(t == NULL)
                return NULL;
            if(t->left == NULL)
                return t;
            else
                return findMin(t->left);
        }


        Node* findMax(Node* t)
        {
            if(t == NULL)
                return NULL;
            if(t->right == NULL)
                return t;
            else
                return findMax(t->right);
        }

        Node* remove(const T& x, Node* t)
        {
            Node* temp;

            if(t == NULL)
                return NULL;
            if(x < t->data)
                t->left = remove(x, t->left);
            else if(x > t->data)
                t->right = remove(x, t->right);
            else if(t->left != NULL && t->right != NULL)
            {
                temp = findMin(t->right);
                t->data = temp->data;
                t->right = remove(t->data, t->right);
            }
            else
            {
                temp = t;
                if(t->left == NULL)
                    t = t->right;
                else if(t->right == NULL)
                    t = t->left;

                delete temp;
            }

            return t;
        }

        void inorder(Node* t)
        {
            if(t == NULL)
                return;
            inorder(t->left);
            std::cout << t->data << " ";
            inorder(t->right);
        }

        Node* find(Node* t, const T& x)
        {
            if(t == NULL)
                return NULL;
            else if(x < t->data)
                return find(t->left, x);
            else if(x > t->data)
                return find(t->right, x);
            else
                return t;
        }
    private:

        struct Node
        {
            T data;
            Node* left;
            Node* right;

            Node(const T& data = NULL, Node* left = NULL, Node* right = NULL) : data(data), left(left), right(right) {}
        };

        Node* root;

};

#endif
