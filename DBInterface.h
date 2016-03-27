//Jacob Hewitt - Computer Science - 3218832
#ifndef DBINTERFACE_H
#define DBINTERFACE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "BSTree.h"
#include "MechPart.h"
#include "LinkedList.h"


using std::ifstream;
using namespace tree;
using namespace linkedList;

namespace interface{

class DBInterface{
	public:
		// constructors / destructor
		DBInterface();
		~DBInterface();
		
		// start the menu
		void start();
		
		void readCurrentFile();
		void readMonthlyFile();
		void displayStatistics();
		void searchListItemsFile();
		MechPart* searchItem(MechPart*);
		
	private: 
		typedef MechPart type;
		BSTree<type>* root; // binary search tree
		
		
		
};



}

#endif