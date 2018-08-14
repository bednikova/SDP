#include<iostream>
#include<iomanip>

using namespace std;

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

        node* root;

    private:
        void inorder(node* t);

        node* find(node* t, int x);
        node* insertBST(int x, node* t);
        node* makeEmpty(node* t);
        node* insert(int x, node* t);
        node* findMaxNode(node* t);
        int heightOfBinTree(node* node);

        void displayTreeImpl(node* n, int);


        node* Delete(node *root, int data);
        int FindMax(node *root);

};




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
    else if(t->left == NULL)
        t->left = insert(x, t->left);
    else if(t->right == NULL)
        t->right = insert(x, t->right);
    else
        t->left = insert(x, t->left);

    return t;
}


node* BinTree::findMaxNode(node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMaxNode(t->right);
}

void BinTree::ReduceToBstImpl(node*& node)
{
    if(node->left->data > node->data)
    {
        //node = findMaxNode(node->left);

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
        IsFullImpl(node->left);
        IsFullImpl(node->right);
    }
}



int BinTree::heightOfBinTree(node* node)
{
    int n, m;

    if(node == NULL)
        return 0;

    n = heightOfBinTree(node->left);
    m = heightOfBinTree(node->right);

    if(n > m)
        return n + 1;
    return m + 1;
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


//delete root

node* BinTree::Delete(node *root, int data)
{
  if (root == NULL)
  {
      return NULL;
  }
  /*
  if (data < root->data && this->IsBstImpl(root))
  {
      // data is in the left sub tree.
      root->left = Delete(root->left, data);
  }
  else if(data > root->data && this->IsBstImpl(root))
  {
      // data is in the right sub tree.
      root->right = Delete(root->right, data);
  }
  */
  //else
  if (data != root->data)
  {
      // data is in the left sub tree.
      root->left = Delete(root->left, data);
      // data is in the right sub tree.
      root->right = Delete(root->right, data);
  }
  else
  {
     // case 1: no children
     if (root->left == NULL && root->right == NULL)
     {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL)
     {
        node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: two children or one child (left)
     else
     {
        //node *temp = FindMin(root->left); // find minimal value of right sub tree
        root->data = FindMax(root->left);  // duplicate the node
        root->left = Delete(root->left, FindMax(root->left)); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}



int BinTree::FindMax(node *root)
{
   if (root == NULL)
   {
      return NULL;//INT_MAX; // or undefined.
   }
   if (root->left != NULL)
   {
      return FindMax(root->left); // left tree is smaller
   }
   return root->data;
}
