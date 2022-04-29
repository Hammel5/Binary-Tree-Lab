#include "BiTree.h"
#include <iostream>
using namespace std;
#define COUNT 10


/*
Precondition – No Precondition
Postcondition – Constructs the Binary Tree 
*/
BiTree::BiTree()
{
    root = nullptr;
}

/*
Precondition – A Binary Tree must have been created
Postcondition – Deconstructs the Binary Tree 
*/
BiTree::~BiTree()
{
    root = makeEmpty(root);
}

/*
Precondition – A Binary Tree must have been created
Postcondition – Adds a node to the correct spot if Null adds to the first spot
*/
Node* BiTree::addNode(int x, Node* current)
{
    if (current == nullptr)
    {
        current = new Node;
        current->data = x;
        current->left = current->right = nullptr;
    }
    else if (x < current->data)
        current->left = addNode(x, current->left);
    else if (x > current->data)
        current->right = addNode(x, current->right);
    return current;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – Removes a certain node
*/
Node* BiTree::removeNode(int x, Node* current)
{
    Node* temp;
    if (current == nullptr)
        return nullptr;
    else if (x < current->data)
        current->left = removeNode(x, current->left);
    else if (x > current->data)
        current->right = removeNode(x, current->right);
    else if (current->left && current->right)
    {
        temp = findMin(current->right);
        current->data = temp->data;
        current->right = removeNode(current->data, current->right);
    }
    else
    {
        temp = current;
        if (current->left == nullptr)
            current = current->right;
        else if (current->right == nullptr)
            current = current->left;
        delete temp;
    }

    return current;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – makes the entire binary tree empty
*/
Node* BiTree::makeEmpty(Node* current)
{
    if (current == nullptr)
        return nullptr;
    {
        makeEmpty(current->left);
        makeEmpty(current->right);
        delete current;
    }
    return nullptr;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – finds and returns the minimum value in the tree 
*/
Node* BiTree::findMin(Node* current)
{
    if (current == nullptr)
        return nullptr;
    else if (current->left == nullptr)
        return current;
    else
        return findMin(current->left);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – finds and returns the maximum value in the tree
*/
Node* BiTree::findMax(Node* current)
{
    if (current == nullptr)
        return nullptr;
    else if (current->right == nullptr)
        return current;
    else
        return findMax(current->right);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – Prints the current node 
*/
void BiTree::visit(Node* current)
{
    cout << current->data << " ";
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – traverses the nodes and prints them in tree order
*/
void BiTree::preOrder(Node* current)
{
    if (current == nullptr)
        return;
    visit(current);
    preOrder(current->left);
    preOrder(current->right);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – traverses the nodes and prints them in order
*/
void BiTree::inorder(Node* current)
{
    if (current == nullptr)
        return;
    inorder(current->left);
    visit(current);
    inorder(current->right);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – traverses the nodes and prints them in reverse order
*/
void BiTree::reverseOrder(Node* current)
{
    if (current == nullptr)
        return;
    reverseOrder(current->right);
    visit(current);
    reverseOrder(current->left);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – traverses the nodes and prints them in reverse tree order
*/
void BiTree::postOrder(Node* current)
{
    if (current == nullptr)
        return;
    postOrder(current->left);
    postOrder(current->right);
    visit(current);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – prints the tree in a tree format
*/
void BiTree::printTree(Node* root, int space)
{
    if (root == nullptr)
        return;

    space += COUNT;

    printTree(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    printTree(root->left, space);
}

// Methods to make it easier to call for the first time

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the addNode function
*/
void BiTree::add(int x)
{
    root = addNode(x, root);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the removeNode function
*/
void BiTree::remove(int x)
{
    root = removeNode(x, root);
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the preOrder function
*/
void BiTree::displayPre()
{
    preOrder(root);
    cout << endl;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the inorder function
*/
void BiTree::displayInOrder()
{
    inorder(root);
    cout << endl;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the reverseOrder function
*/
void BiTree::displayReverse()
{
    reverseOrder(root);
    cout << endl;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the postOrder function
*/
void BiTree::displayPost()
{
    postOrder(root);
    cout << endl;
}

/*
Precondition – A Binary Tree must have been created and has atleast one item
Postcondition – easier way to run the printTree function
*/
void BiTree::printTree()
{
    printTree(root, 0);
}