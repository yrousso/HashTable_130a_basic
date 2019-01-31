#include <list>
#include <string>
#include <vector>

class HashTable{

	public:
		HashTable(int size);
		//hashtable should have size and randomly generated a1-a4 every time a new hash table is constructed
		// HashTable(int size)
		// generatea() -> should generate a1-a4 randomly 
		void insert(std::string name);
		void remove(std::string name);
		bool exists(std::string name);
		void print();
		void lookup(std::string name);
		void stat();	
		
	private:
		std::vector<std::list<std::string> > table;
		int hash(std::string name);
		int size;
		void parseIPtoArray(std::string);//function will parse string 123.12.4.014 and store in parsedIP[123,12,4,014]
		std::vector<int> parsedIP;
		void generateCoeff();
		int a1; 
		int a2;
		int a3;
		int a4;
		int insert_success;
		int remove_success;
		int emptySlots;
		int exactly_one_item;
		int max_collision_index;
		std::vector<int> collisions;
};
