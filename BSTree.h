//Jacob Hewitt - Computer Science - 3218832
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <string>
#include "BTNode.h"
using namespace node;
namespace tree{
template <typename MechPart>
class BSTree{
	public:
		// constructors/destructor
		BSTree();
		BSTree(BTNode<MechPart>*);
		~BSTree();
		
		void deleteTree(); // called to delete all the nodes in the tree.
		
		// query member functions
		BTNode<MechPart>* getRoot();
		BTNode<MechPart>* getLeft();
		BTNode<MechPart>* getRight();
		MechPart* current();
		int countNodes(BTNode<MechPart>*);
		int countParts(BTNode<MechPart>*);
		MechPart* search(const MechPart*);
		int searchReturnComparisons(const MechPart*);
		
		// mutator member functions
		void insert(MechPart*);
		bool deleteNode(MechPart*);
		void deleteFromTree(BTNode<MechPart>*);
		
		
		
	private: 
		void deleteTree(BTNode<MechPart>*);
		MechPart* search(const MechPart*, BTNode<MechPart>*);
		
		BTNode<MechPart>* root; // root node of the tree
		size_t size; // number of nodes in the tree.
		
		
		
};

#include "BSTree.template"

}

#endif