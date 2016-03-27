//Jacob Hewitt - Computer Science - 3218832
#ifndef BTNODE_H
#define BTNODE_H
#include <sstream>
#include <iostream>
#include "MechPart.h"

// this class represents each node in the tree.
namespace node{
template <typename MechPart>
class BTNode{
	public:
	
		// constructors
		BTNode(MechPart*);
		BTNode(MechPart*, BTNode*, BTNode*, BTNode*);
		
		// destructor
		~BTNode();
		
		// mutator member functions
		bool add(MechPart*);
		void setData(MechPart*);
		void setQuantity(int);
		void setParent(BTNode*);
		void setLeft(BTNode*);
		void setRight(BTNode*);
		BTNode<MechPart>* remove(MechPart*, BTNode<MechPart>*);
		
		// query member functions
		MechPart* getData();
		BTNode<MechPart>* getParent();
		BTNode<MechPart>* getLeft();
		BTNode<MechPart>* getRight();
		MechPart* maxValue();
		
	private: 
		
		MechPart* data; // MechPart object which holds the item's data.
		
		// pointers to other nodes in the tree.
		BTNode<MechPart>* parent;
		BTNode<MechPart>* left;
		BTNode<MechPart>* right;
};

#include "BTNode.template"

}

#endif