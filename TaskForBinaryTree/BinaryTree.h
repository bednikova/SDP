#include <iostream>
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

        int accumTreeImpl()
        {
            int sum = 0;

            if(root == NULL)
                return sum;
            else
            {
                if(!root->left && !root->right)
                {
                    return sum + root->data;
                }
                else if(root->left && !root->right)
                {
                    sum += accumTreeImpl(root->left);
                }
                else if(!root->left && root->right)
                {
                    sum += accumTreeImpl(root->right);
                }
                else
                {
                    sum += accumTreeImpl(root->right) + accumTreeImpl(root->left);
                }
            }

            return sum;
        }


        void insert(int x, bool flagTree)
        {


        }

    private:

        struct Node;

        Node* makeEmpty(Node* t)
        {

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
