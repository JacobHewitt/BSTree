//Jacob Hewitt - Computer Science - 3218832
#ifndef NODE_H
#define NODE_H
#include <cstddef>

// This template class of Node takes a input of type 'Data' and stores it. It also holds a pointer to the next Node object
namespace node{
template <typename Data>
class Node{
	public:
	
		// mutator member functions
		Node(Data*);
		~Node();
		void setLink(Node *inputNode);
		
		// query member functions
		Node* getLink() const;
		Data* getData() const;
	private: 
		Data* data; // data being stored
		Node<Data> *link;
};

#include "Node.template"

}

#endif