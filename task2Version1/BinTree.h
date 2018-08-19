#include <iostream>
#include <iomanip>

using namespace std;

#ifndef __BINTREE_H__
#define __BINTREE_H__

template <class T>
class BinTree
{
    public:
        BinTree() : root(NULL) {}

        ~BinTree()
        {
            root = makeEmpty(root);
        }

        void display()
        {
            inorder(root);
            std::cout << endl;
        }

        void displayTree()
        {
            displayTreeImpl(root);
        }

        void insert(const T& x)
        {
            root = insert(x, root);
        }

        void insertBst(const T& x)
        {
            root = insertBst(x, root);
        }

        void remove(const T& x)
        {
            root = remove(x, root);
        }

        void ReduceToBst()
        {
            ReduceToBstImpl(root);
        }

        bool IsFull()
        {
            return IsFullImpl(root);
        }


        bool IsBstI()
        {
            return IsBstImpl(root);
        }


    private:
        struct Node;

        Node* destroy()
        {
            Node* t;
            t = makeEmpty(t);
            return t;
        }

        Node* insert(const T& x, Node* t)
        {
            if(!t)
            {
                t = new Node(x); // !!!
            }
            else if(x == t->data)
                return t;
            else if(!t->left)
                t->left = insert(x, t->left);
            else if(!t->right)
                t->right = insert(x, t->right);
            else
                t->left = insert(x, t->left);

            return t;

        }

        Node* insertBst(const T& x, Node* t)
        {
            if(!t)
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

        Node* remove(const T& x, Node* t)
        {
            Node* temp;
            if(!t)
                return NULL;
            else if(x < t->data)
                t->left = remove(x, t->left);
            else if(x > t->data)
                t->right = remove(x, t->right);
            else if(t->left && t->right)
            {
                temp = findMin(t->right);
                t->data = temp->data;
                t->right = remove(t->data, t->right);
            }
            else
            {
                temp = t;
                if(!t->left)
                    t = t->right;
                if(!t->right)
                    t = t->left;
                delete temp;
            }

            return t;
        }

        bool IsBstImpl(Node* t)
        {
            if(!t || (!t->left && !t->right))
                return true;
            else if(!t->left && t->right)
            {
                if(t->right->data < t->data)
                    return false;
                else
                    IsBstImpl(t->right);
            }
            else if(t->left && !t->right)
            {
                if(t->left->data > t->data)
                    return false;
                else
                    IsBstImpl(t->left);
            }
            else if(t->left->data > t->data || t->right->data < t->data)
                return false;
            else
                return (IsBstImpl(t->left) && IsBstImpl(t->right));
        }

        bool IsFullImpl(Node* node)
        {
            if(heightOfBinaryTree(node->left) != heightOfBinaryTree(node->right))
                return false;
            else if(!node || (!node->left && !node->right))
                return true;
            else if((!node->left && node->right) || (node->left && !node->right))
                return false;
            else
                return (IsFullImpl(node->left) && IsFullImpl(node->right));
        }

        void ReduceToBstImpl(Node*& node)
        {
            if(!node->left && !node->right)
                return;
            else if(!node)
                return;
            if(node->left->data > node->data)
                Delete(node, node->data);
            else if(node->right->data < node->data)
                Delete(node, node->data);
            else
            {
                ReduceToBstImpl(node->left);
                ReduceToBstImpl(node->right);
            }
        }

        Node* findMax(Node *t)
        {
            if(!t)
                return NULL;
            else if(t->right == NULL)
                return t;
            else
                return findMax(t->right);
        }

        Node* findMin(Node *t)
        {
            if(!t)
                return NULL;
            else if(t->left == NULL)
                return t;
            else
                return findMin(t->left);
        }

        Node* makeEmpty(Node* t)
        {
            if(!t)
                return NULL;
            else
            {
                makeEmpty(t->left);
                makeEmpty(t->left);
                delete t;
            }

            return NULL;
        }

        void displayTreeImpl(Node* n, int i = 0)
        {
            if(n)
            {
                i = i+5;
                if(n->right)
                    displayTreeImpl(n->right, i);
                cout << setw(i) << n->data << endl;
                if(n->left)
                    displayTreeImpl(n->left, i);
            }
        }

        Node* Delete(Node* t, const T& data)
        {
            if(!t)
                return NULL;
            else if(data != t->data)
            {
                t->left = Delete(t->left, data);
                t->right = Delete(t->right, data);
            }
            else
            {
                if(!t->left && !t->right)
                {
                    delete t;
                    t = NULL;
                }
                else if(!t->left)
                {
                    Node* temp = t;
                    t = t->right;
                    delete temp;
                }
                else
                {
                    t->data = FindMaxBinaryTree(t->left);
                    t->left = Delete(t->left, FindMaxBinaryTree(t->left));
                }
            }

            return t;
        }

        T FindMaxBinaryTree(Node* t)
        {
            if(!t)
                return NULL;
            T maxE = t->data;
            T maxL = FindMaxBinaryTree(t->left);
            T maxR = FindMaxBinaryTree(t->right);

            if(maxL > maxE)
                maxE = maxL;
            if(maxR > maxE)
                maxE = maxR;

            return maxE;

        }

        Node* find(Node* t, const T& x)
        {
            if(!t)
                return NULL;
            else if(x < t->data)
                return find(t->left);
            else if(x > t->data)
                return find(t->right);
            else
                return t;
        }

        void inorder(Node* t)
        {
            if(!t)
            {
                return;
            }
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }

        int heightOfBinaryTree(Node* t)
        {
            if(!t)
                return 0;

            int n = 0, m = 0;

            n = heightOfBinaryTree(t->left);
            m = heightOfBinaryTree(t->right);

            if(n > m)
                return n+1;
            return m+1;
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
