#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size){
	this->size = size;
	table.resize(size);
	collisions.resize(size);
	generateCoeff();	
}

int HashTable::hash(std::string name){
	parseIPtoArray(name); // parse ip to array
	//math		
	int val = 0;
	//can later adjust code to use back and pop_back to multiply and remove elements 
	// -> can then remove empty() chek in function parseIPtoArray

	val = (a4 * parsedIP[0]) + (a3 * parsedIP[1]) + (a2 * parsedIP[2]) + (a1 * parsedIP[3]); 

	return val % size;
}

// note: when vector parsedIP is storing split ip in order: msb -> lsb
void HashTable::parseIPtoArray(std::string ip_stream)
{   
	if(!parsedIP.empty())
	{
		parsedIP.clear(); //clear any previously stored ip 
		//		std::cout<<" not empty \n";
	}
	std::string ip; 
	//parse IP
	for(int i = 0 ; i<ip_stream.length(); i++)
	{	    
		if(ip_stream[i] == '.')
		{   
			parsedIP.push_back (std::stoi(ip)); //save ip sectioned in array of ints
			ip = ""; //reset ip for next section
			i++; //move past '.'
		}    
		ip += ip_stream[i]; //save digits in ip as string

		if(i == ip_stream.length() - 1)
		{   
			parsedIP.push_back (std::stoi(ip));  //save last ip sectioned in array of ints
			ip = ""; 
		}   
	}   
	//	for (auto it = parsedIP.begin(); it != parsedIP.end(); ++it) 
	//	       std::cout << ' ' << *it << " > ";
}    
void HashTable::generateCoeff(){
	// use math.rand()
	//for now hardcode values
	this->a1 = 10;
	this->a2 = 89;
	this->a3 = 210;
	this->a4 = 162;
}

bool HashTable::exists(std::string name){
	int index = hash(name);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
		if(name.compare(*it) == 0){
			return true;
		}
	}
	return false;
}

void HashTable::insert(std::string name){
	if(exists(name)){
		std::cout << name << " already exists" << std::endl;
		return;
	}
	int index = hash(name);
	table[index].push_back(name);
	insert_success++;
	collisions[index]++;	
	//std::cout << name << " inserted" << std::endl;
	return;
}

void HashTable::remove(std::string name){
	int index = hash(name);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
		if(name.compare(*it) == 0){
			table[index].erase(it);
			remove_success++;
			//std::cout << name << " deleted" << std::endl;
			return;
		}
	}
	std::cout << name << " does not exist" << std::endl;
	return;
}

void HashTable::print(){
	for(int i = 0; i < size; i++){
		std::list<std::string>::iterator it;
		std::cout << i << ": ";
		for(it = table[i].begin(); it != table[i].end(); it++){
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}
}

void HashTable::lookup(std::string name)
{
	if(exists(name))
		std::cout << name << ": found" << std::endl;
	else
		std::cout << name << ": not found" << std::endl;
}

void HashTable::stat(){
	for(int i = 0; i < size; i++)
	{
		if(table[i].size() == 0)		
			emptySlots++;
		if(table[i].size() == 1)
			exactly_one_item++;
		if(collisions[i] > collisions[max_collision_index])
			max_collision_index = i;
		else if(collisions[i] == collisions[max_collision_index])
			if(i > max_collision_index)
				max_collision_index = i;
			
	}
	std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << std::endl;
	std::cout << insert_success << std::endl;
	std::cout << remove_success << std::endl;
	std::cout << emptySlots << std::endl;
	std::cout << exactly_one_item << std::endl;
	std::cout << collisions[max_collision_index] << " " << max_collision_index << std::endl;
	//max collisions (count, location)
	// -> note: 1 insert is 1 collision
	//	->ties on count break on largest location

}
