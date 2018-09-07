#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* central;
    Node* right;

    Node(char data = NULL, Node* left = NULL, Node* central = NULL, Node* right = NULL):
        data(data), left(left), central(central), right(right) {}
};

void addNode(Node*& tree, char x, char t = 'l')
{
    Node* newNode = new Node(x);
    if(!tree)
    {
        tree = newNode;
    }
    else
    {
        Node* temp = tree;

        if(t == 'l')
        {
            while(temp->left)
            {
                temp = temp->left;
            }
            temp->left = newNode;
        }
        else if(t == 'r')
        {
            while(temp->right)
            {
                temp = temp->right;
            }
            temp->right = newNode;
        }
        else if(t == 'c')
        {
            while(temp->central)
            {
                temp = temp->central;
            }
            temp->central = newNode;
        }
    }
}

void createTree(Node*& tree)
{
    char n; char c; char t;
    do
    {
        cout << "Enter element: ";
        cin >> n;
        cout << "Enter element in l or c or r tree: ";
        cin >> t;
        addNode(tree, n, t);
        cout << "Add next element: y or n";
        cin >> c;
    }while(c == 'y');
}

void printTree(const Node* tree, int i = 0)
{
    i = i+5;
    if(!tree)
        return;
    cout << setw(i-5) << tree->data << endl;
    printTree(tree->right, i);
    printTree(tree->central, i);
    printTree(tree->left, i);

}

int heightTree(Node* tree)
{
    int l = 0, c = 0, r = 0;
    if(!tree)
        return 0;

    l = heightTree(tree->left);
    c = heightTree(tree->central);
    r = heightTree(tree->right);

    return ((((c > l) ? c : l) > r) ? ((c > l) ? c : l) + 1 : r + 1);
}

void readTree(Node* tree)
{
    int h = heightTree(tree);

    if(!tree)
        return;

    if(h == 1)
    {
        cout << tree->data;
        return;
    }

    readTree(tree->left);
    readTree(tree->central);
    readTree(tree->right);


}



void saveTree(Node* tree)
{
    ofstream myFile("tree.txt", ios::app);

    if(myFile)
    {
        if(!tree)
        {
            myFile << "()";
            return;
        }
        myFile << "(" << tree->data;
        myFile.close();
        saveTree(tree->left);
        saveTree(tree->central);
        saveTree(tree->right);
        ofstream myFile("tree.txt", ios::app);
        myFile << ")";
        myFile.close();

    }

    myFile.close();
}
