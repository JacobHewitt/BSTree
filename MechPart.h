//Jacob Hewitt - Computer Science - 3218832
#ifndef MECHPART_H
#define MECHPART_H
#include <string>
#include <iostream>

// This class holds the data for each Node in the binary tree.
namespace node{
class MechPart{
	public:
		MechPart();
		MechPart(std::string, int); 
		MechPart(MechPart*); // copy constructor
		~MechPart();
		int compareTo(const MechPart*) const; // compare the code strings to see if they are equal or smaller/bigger
		std::string getCode() const;
		int getQuantity() const;
		void setQuantity(int);
	private: 
		
		std::string code; // unique identifier. Item code
		int quantity; // current quantity of this item.
		
		
};

}


#endif