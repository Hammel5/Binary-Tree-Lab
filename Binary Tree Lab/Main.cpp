#include <iostream>
#include "BiTree.h"

using namespace std;

int main()
{
	BiTree tree;

	tree.add(7);
	tree.add(10);
	tree.add(4);
	tree.add(15);
	tree.add(8);
	tree.add(6);
	tree.add(2);
	tree.add(50);
	tree.add(12);
	tree.add(9);
	tree.add(3);
	tree.add(20);
	tree.add(25);
	tree.add(15);
	tree.add(10);
	tree.add(30);
	tree.displayInOrder();
	tree.remove(20);
	tree.displayInOrder();
	tree.remove(25);
	tree.displayInOrder();
	tree.remove(30);
	tree.displayInOrder();
	cout << endl << endl << "Pre" << endl;
	tree.displayPre();
	cout << endl << endl << "In" << endl;
	tree.displayInOrder();
	cout << endl << endl << "Reverse" << endl;
	tree.displayReverse();
	cout << endl << endl << "Post" << endl;
	tree.displayPost();
	cout << endl << endl << "Tree" << endl;
	tree.printTree();

	return 0;
}