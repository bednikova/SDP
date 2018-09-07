#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* central;
    Node* right;

    Node(char data = NULL, Node* left = NULL, Node* central = NULL, Node* right = NULL) :
        data(data), left(left), central(central), right(right) {}
};


void addNode(Node*& tree, char data, char t = 'k')
{
    Node* newNode = new Node(data);

    if(!tree)
    {
        tree = newNode;
    }
    else
    {
        if(t == 'l')
        {
            tree->left = newNode;
        }
        else if(t == 'c')
        {
            tree->central = newNode;
        }
        else if(t == 'r')
        {
            tree->right = newNode;
        }
    }
}


void printTree(Node* tree, int i = 0)
{
    if(!tree)
        return;
    i = i + 5;
    std::cout << std::setw(i-5) << tree->data << std::endl;
    if(tree->right)
        printTree(tree->right, i);
    if(tree->central)
        printTree(tree->central, i);
    if(tree->left)
        printTree(tree->left, i);

}

void saveInFile(Node* tree)
{
    ofstream myFile("tree.txt", ios::app);

    if(myFile)
    {
        if(!tree)
            myFile << "()";
        else
        {
            myFile << "(" << tree->data;
            myFile.close();
            saveInFile(tree->left);
            saveInFile(tree->central);
            saveInFile(tree->right);
            ofstream myFile("tree.txt", ios::app);
            if(myFile)
                myFile << ")";
            myFile.close();
        }
    }

    myFile.close();
}


int heightTree(Node* tree)
{
    int l = 0, c = 0, r = 0;

    if(!tree)
        return 0;

    l = heightTree(tree->left);
    c = heightTree(tree->central);
    r = heightTree(tree->right);

   return ((((c >= l) ? c : l) >= r) ? ((c >= l) ? c : l) + 1: r+1);
}


void readTree(Node* tree)
{
    int h = heightTree(tree);

    if(h == 1)
    {
        cout << tree->data;
        return;
    }

    if(!tree)
        return;

    readTree(tree->left);
    readTree(tree->central);
    readTree(tree->right);

}
