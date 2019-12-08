// Red Black Tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

#include <iostream>
#include <RBTree.h>

using namespace std;

int main() {
	RBTree tree;
  tree.insert(20);
  tree.insert(3);
  tree.insert(40);
  tree.insert(2);
  tree.insert(4);
  tree.insert(22);
  tree.insert(50);
  tree.insert(1);
  tree.insert(23);
  tree.insert(25);
  tree.insert(60);
  tree.insert(24);
  tree.insert(26);
  tree.prettyPrint();


	// tree.deleteNode(20);
	// tree.prettyPrint();

	// tree.deleteNode(40);
	// tree.prettyPrint();
	//
	// tree.deleteNode(60);
	// tree.prettyPrint();


	return 0;
}
