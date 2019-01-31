#include <iostream>
#include "HashTable.h"


int main(){
	std::string command;
	std::string IP;

	std::cin >> command; //get size for table (always first command)
	int  size = std::stoi(command);
	HashTable ht(257); // make hash table of size 257 for basic program

	while(std::cin >> command )
	{
		if(command == "insert")
		{
			std::cin >> command; //get IP from input after command
			ht.insert(command); // pass parsedIP and insert in table
		}

		else if(command == "delete")
		{
			std::cin >> command; //get IP from input after command
			ht.remove(command);
		}

		else if(command == "lookup")
		{
			std::cin >> command; //get IP from input after command
			ht.lookup(command);
		}

		else if(command == "stat")
		{
			ht.stat();
		//	ht.print();
		}
		else
		{
			std::cout<<"Invalid file" << std::endl;
		}
	}	

	return 0;

}


