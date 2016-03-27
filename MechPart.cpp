//Jacob Hewitt - Computer Science - 3218832

// constructor method. Takes the data to be stored and saves.

#include "MechPart.h"
namespace node{
MechPart::MechPart(){
	
}


MechPart::MechPart(std::string codeInput, int quantityInput){
	this->code = codeInput;
	this->quantity = quantityInput;
}

MechPart::MechPart(MechPart* toCopy){ // copy constructor
	this->code = toCopy->getCode();
	this->quantity = toCopy->getQuantity();
}

MechPart::~MechPart(){
	
}

// compare function between two MechPart objects.
// used to traverse the tree.
int MechPart::compareTo(const MechPart* toCompare) const{
	std::string temp = toCompare->getCode(); // the MechPart object passed into the parameters 
	if(code == temp){ // two codes match. 
	
		return 0;
		
	}else if(temp < code){ // the code of the object passed into the parameters is smaller than the current node's code
	

		return 1;
	
	}else{ // the node's code is bigger
	
		return 2;
		
	}
}

std::string MechPart::getCode() const{
	return code;
}

int MechPart::getQuantity() const{
	return quantity;
}

void MechPart::setQuantity(int newQuantity){
	quantity = newQuantity;
}

}