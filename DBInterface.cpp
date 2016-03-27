//Jacob Hewitt - Computer Science - 3218832
#include "DBInterface.h"

namespace interface{

DBInterface::DBInterface(){
	root = new BSTree<type>(); // initialize the binary search tree
}

DBInterface::~DBInterface(){
	delete root; // delete the tree
}

// This function is the Menu. It takes the users input and sends them to the corresponding methods.
void DBInterface::start(){
	bool toContinue = false;
	std::string input;
	int option;
	std::cout << "1. read current inventory file \n2. read/exec monthly update file \n"
	<< "3. display statistics \n4. search list items file \n5. quit " << std::endl;
	
	while(toContinue == false){
		std::getline(std::cin, input);
		option = atoi(input.c_str());
	
		switch(option){
			case 1: readCurrentFile();
					break;
			case 2: readMonthlyFile();
					break;
			case 3: displayStatistics();
					break;
			case 4: searchListItemsFile();
					break;
			case 5: toContinue = true;
					std::cout << "Quitting" << std::endl;
					break;		
		}
	}
	
}

// This function takes a file name from the user and adds its contents into the BST.
void DBInterface::readCurrentFile(){
	std::string line;
	ifstream myReadFile;
	node::MechPart* data = NULL;
	std::string delimiter = "	"; // string in between the item's Code and Quantity. Used to split line into two strings.
	std::string code;
	std::string quantity;
	bool skipFirstLine = true; // skip first line of the file.
	std::cout << "Enter file name to read:" << std::endl;
	std::string filename;
	std::cin >> filename; // get file-name
	
	
	myReadFile.open(filename.c_str(), ifstream::in); 
	if(myReadFile.is_open()){ // check the file has opened.
		std::cout << std::endl;
		std::cout << "File Opened Successfully" << std::endl;
		std::cout << std::endl;
		while(getline(myReadFile, line)) { // loop through each line in the file.
			if(skipFirstLine == true){
				skipFirstLine = false;
				continue;
			}
			data = NULL;
			int value;
			code = line.substr(0, line.find(delimiter)); // copy the code from the line in the file.
			quantity = line.substr(line.find(delimiter)+1, line.length()); // copy the quantity (integer) from the line in the file.
			value = atoi(quantity.c_str()); // convert the string to integer.
			data = new MechPart(code, value); // create new MechPart object to be stored by the Node.
			root->insert(data); // create new node in the tree.
			
			
			line = "";
		}
		
		myReadFile.close();
	}else{ // File was no opened correctly.
		std::cout << "Error: no file found" << std::endl;
	}
	
}

// this function reads a file and adds/modifies the contents into the binary search tree. 
// It uses a linkedList to hold pointers of MechPart objects to be passed into the tree. 
void DBInterface::readMonthlyFile(){
	LinkedList<MechPart>* itemCodes = new LinkedList<MechPart>(); // holds MechPart objects created from the file.
	bool skipFirstLine = true; // skip first line of the file.
	std::string line;
	ifstream myReadFile;
	std::string code;
	std::string quantity;
	std::string delimiter = "	";
	std::cout << "Enter monthly update file-name: " << std::endl;
	std::string fileName;
	std::cin >> fileName;
	node::MechPart* data = NULL; // Used to create MechPart objects from each line in the file.
	
	myReadFile.open(fileName.c_str(), ifstream::in); // open the file
	if(myReadFile.is_open()){ // check if the file is open. 
		std::cout << std::endl;
		std::cout << "File Opened Successfully" << std::endl;
		std::cout << std::endl;
		while(getline(myReadFile, line)){ // loop through each line in the file.
			data = NULL; 
			if(skipFirstLine == true){
				skipFirstLine = false;
				continue;
			}
			int value;
			code = line.substr(0, line.find(delimiter)); // get the code from the line.
			quantity = line.substr(line.find(delimiter)+1, line.length()); // get the quantity from the line
			value = atoi(quantity.c_str()); // convert string to int.
			data = new MechPart(code, value); // create new MechPart object 
			itemCodes->addToTail(data); // store it in the linkedList.
			
		}
		myReadFile.close(); // close file
	}else{ // if the file did not open
		std::cout << "Error: no file found" << std::endl;
	}
	
	int toCompare = itemCodes->length(); // get the length of the linkedList.
	for(int x = 0; x < toCompare; x++){ // loop through the linkedList
		root->insert(itemCodes->get(x)); // pass the MechPart stored by the Node in the linkedList to the BST insert() method
	}
	
	delete itemCodes; // delete the linkedlist.
	
}

void DBInterface::displayStatistics(){
	std::cout << "Number of different parts: " << root->countNodes(root->getRoot()) << std::endl; // count the total number of nodes.
	std::cout << "Number of parts in total: " << root->countParts(root->getRoot()) << std::endl; // count the total number of parts (quantity)
}

// this function loops through a file provided by the user and creates a new MechPart object.
// this object is stored in a LinkedList. The MechPart objects are then used to search the binary tree.
void DBInterface::searchListItemsFile(){
	LinkedList<MechPart>* itemCodes = new LinkedList<MechPart>(); // linked list of MechPart object pointers.
	MechPart* toAdd; // MechPart object to add to the linkedList and search the BST
	bool skipFirstLine = true;
	std::string line;
	std::string code;
	ifstream myReadFile;
	std::cout << "Enter filename to search: " << std::endl;
	std::string fileName;
	std::cin >> fileName;
	
	myReadFile.open(fileName.c_str(), ifstream::in); // open the file
	if(myReadFile.is_open()){ // check if its open
		std::cout << std::endl;
		std::cout << "File Opened Successfully" << std::endl;
		std::cout << std::endl;
		while(!myReadFile.eof()){ // loop through the file
			toAdd = NULL;
			line = "";
			getline(myReadFile, line); // get the line from the file
			if(skipFirstLine == true){
				skipFirstLine = false;
				continue;
			}
			if(line.substr(line.length()-1, line.length()) == "\r" ){ // check if the current line has a hidden "\r" at the end.
				toAdd = new MechPart(line.substr(0, line.length()-1), 0); // create new MechPart object
			}else{
				toAdd = new MechPart(line.substr(0, line.length()), 0);  
			}
			
			itemCodes->addToTail(toAdd); // add the MechPart object to the LinkedList
		
		}
		
		skipFirstLine = true;
		myReadFile.close();
		
	}else{ // file was not opened.
		std::cout << "Error: no file found" << std::endl;
		return;
	}
	
	int numberOfComparisons;
	int totalNumberOfComparisons;
	int numberToDivideBy;
	int toCompare = itemCodes->length(); // get the length of the linkedList
	std::cout << std::endl;
	std::cout << "Item Code-----------Quantity-----------Number Of Comparisons to find" << std::endl;
	for(int x = 0; x < toCompare; x++){ // loop through each node in the linkedList
		
		// get the MechPart in the BST corresponding to the MechPart stored in the LinkedList Node
		MechPart* temp = searchItem(itemCodes->get(x)); 
		
		// check if the item exists in the tree
		if(temp != NULL){
			numberToDivideBy++;
			// get the total number of comparisons it took to find the Node in the tree.
			numberOfComparisons = root->searchReturnComparisons(itemCodes->get(x));
			totalNumberOfComparisons += numberOfComparisons;
			std::cout << temp->getCode() << "-----------" << temp->getQuantity() << "-----------" << numberOfComparisons << std::endl;
		}else{ // item does not exist in the tree
			std::cout << itemCodes->get(x)->getCode() << "-----------" << "0" << std::endl;
		}
	}
	int numberToDisplay = totalNumberOfComparisons/numberToDivideBy;
	std::cout << "average number of comparisons: " << numberToDisplay << std::endl;
	
	delete itemCodes; // delete the linkedList

}

// returns the MechPart from the Node searched for in the tree.
MechPart* DBInterface::searchItem(MechPart* code){
	return root->search(code);
}

}
