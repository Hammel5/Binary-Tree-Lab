#ifndef BiTree_H
#define BiTree_H

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BiTree
{
public:
    BiTree(); // constructor
    ~BiTree(); // deconstructor
    Node* addNode(int x, Node* current); // Adds a node to the correct spot
    Node* removeNode(int x, Node* current); // removes a certain node
    Node* makeEmpty(Node* current); // makes the entire binary tree empty
    Node* findMin(Node* current); // finds the minimum value in the tree 
    Node* findMax(Node* current); // finds the maximum value in the tree
    void visit(Node* current); // Prints the current node 
    void preOrder(Node* current); // traverses the nodes and prints them in tree order
    void inorder(Node* current); // traverses the nodes and prints them in order
    void reverseOrder(Node* current); // traverses the nodes and prints them in reverse order
    void postOrder(Node* current); // traverses the nodes and prints them in reverse tree order
    void printTree(Node* root, int space); // prints the tree in a tree format

    void add(int x); // easier way to run the addNode function
    void remove(int x); // easier way to run the removeNode function
    void displayPre(); // easier way to run the preOrder function
    void displayInOrder(); // easier way to run the inorder function
    void displayReverse(); // easier way to run the reverseOrder function
    void displayPost(); // easier way to run the postOrder function
    void printTree(); // easier way to run the printTree function

private:
    Node* root;
};
#endif //!BiTree_H