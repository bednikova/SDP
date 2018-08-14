#include "BinTree.h"

BinTree::BinTree()
{
    root = NULL;
}

BinTree::~BinTree()
{
    root = makeEmpty(root);
}

void BinTree::insert(int x)
{
    root = insert(x, root);
}


void BinTree::insertBST(int x)
{
    root = insertBST(x, root);
}

void BinTree::remove(int x)
{
    root = remove(x, root);
}

void BinTree::display()
{
    inorder(root);
    cout << endl;
}

void BinTree::displayTree()
{
    displayTreeImpl(root,0);
}

void BinTree::displayTreeImpl(node* n, int i=0)
{
    if(n)
    {
        i = i + 5;
        if (n->right)
            displayTreeImpl(n->right, i);
        cout << setw(i) << n->data << endl;
        if (n->left)
            displayTreeImpl(n->left, i);
    }
}


void BinTree::inorder(node* t)
{
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

node* BinTree::find(node* t, int x)
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


node* BinTree::findMin(node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

node* BinTree::findMax(node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

node* BinTree::remove(int x, node* t)
{
    node* temp;
    if(t == NULL)
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
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}


node* BinTree::insertBST(int x, node* t)
{
    if(t == NULL)
    {
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if(x < t->data)
        t->left = insertBST(x, t->left);
    else if(x > t->data)
        t->right = insertBST(x, t->right);
    return t;
}

node* BinTree::makeEmpty(node* t)
{
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

node* BinTree::insert(int x, node* t)
{
    if(t == NULL)
    {
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if(x == t->data)
        return t;
    else if(t->left == NULL)
        t->left = insert(x, t->left);
    else if(t->right == NULL)
        t->right = insert(x, t->right);
    else
        t->left = insert(x, t->left);

    return t;
}


void BinTree::ReduceToBstImpl(node*& node)
{
    if(node->left == NULL && node->left == NULL)
    {
        return;
    }
    else if(node == NULL)
    {
        return;
    }
    if(node->left->data > node->data)
    {
        Delete(node, node->data);
    }
    else if(node->right->data < node->data)
    {
        Delete(node, node->data);
    }
    else
    {
        ReduceToBstImpl(node->left);
        ReduceToBstImpl(node->right);
    }

}


bool BinTree::IsFullImpl(node* node)
{
    if(heightOfBinTree(node->left) != heightOfBinTree(node->right))
    {
        return false;
    }
    else if((node == NULL) || ((node->left == NULL) && (node->right == NULL)))
    {
        return true;
    }
    else if(((node->left == NULL) && (node->right != NULL)) ||
            ((node->left != NULL) && (node->right == NULL)))
    {
        return false;
    }
    else
    {
        return (IsFullImpl(node->left) && IsFullImpl(node->right)) ? true : false;
    }
}



int BinTree::heightOfBinTree(node* node)
{
    int n = 0, m = 0;

    if(node == NULL)
        return 0;

    n = heightOfBinTree(node->left);
    m = heightOfBinTree(node->right);

    if(n > m)
        return n+1;
    return m+1;
}


bool BinTree::IsBstImpl(node* node)
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
        return (IsBstImpl(node->left) && IsBstImpl(node->right)) ? true : false;
    }


}

node* BinTree::Delete(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data != root->data)
    {
        root->left = Delete(root->left, data);
        root->right = Delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            root->data = FindMaxBinaryTree(root->left);
            root->left = Delete(root->left, FindMaxBinaryTree(root->left));
        }
    }
    return root;
}


int BinTree::FindMaxBinaryTree(node* root)
{
    if (root == NULL)
      return 0;

    int maxElem = root->data;
    int maxElemLeft = FindMaxBinaryTree(root->left);
    int maxElemRight = FindMaxBinaryTree(root->right);

    if (maxElemLeft > maxElem)
      maxElem = maxElemLeft;
    if (maxElemRight > maxElem)
      maxElem = maxElemRight;

    return maxElem;
}

