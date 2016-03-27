//Jacob Hewitt - Computer Science - 3218832
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include "Node.h"
using namespace node;
namespace linkedList{
template <typename Data>
class LinkedList{
	public:
	
		// mutator member functions
		LinkedList();
		~LinkedList();
		void addToHead(Data input);
		void addToTail(Data* input);
		void deleteNodes(Data input);
		Data removeFromHead();
		Data returnHead() const;
		
		// query member functions
		size_t length() const;
		bool empty() const;
		Data* get(int input) ;
		int count(Data input) ;
		
	private:
		
		// Pointers for the Nodes
		Node<Data> *head;
		Node<Data> *tail;
		Node<Data> *current;
		size_t counter;
		
};

#include "LinkedList.template"
}
#endif