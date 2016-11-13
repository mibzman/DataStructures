#include <vector>
#include <list>
#include <iostream>

struct OpenHash {//a seperate chained hash table
	private:

	int KeyCount;

	int Hash(int key){
		return key % int_count();
	}
	public:
	std::vector<int> Table;

	OpenHash(){
		KeyCount = 0;
		std::vector<int> newTable(8);
                Table = newTable;
	}

	OpenHash(const OpenHash & other){
		KeyCount = other.key_count();
		Table = other.Table;
	}

	OpenHash & operator=(const OpenHash & other){
		KeyCount = other.key_count();
                Table = other.Table;
	}

	int load() const{
		return key_count() / int_count();
	}

	int key_count() const {
		return KeyCount;
	}

	int int_count() const{
		return Table.size();
	}

	void insert(int key){
		if (load() > .75){
			rehash(int_count() * 2);
		}
		DumbInsert(key);
	}

	void DumbInsert(int key){
		int hash = Hash(key);
		if (Table[hash]){
                        int counter = hash +1;
                        while (counter != hash){
                                if (!Table[counter]){
                                        Table[counter] = key;
                                        break;
                                }
                                counter++;

                                if (counter == Table.size()){
                                        counter = 0;
                                }
                        }
                }else{
                        Table[hash] = key;
                }
                KeyCount++;
	}

	void rehash(int size){
		int emptyint = int();
		std::vector<int> oldTable = Table; 
		//we have to do it this way to make the hash function work right
		KeyCount = 0;
		std::vector<int> newTable(size, emptyint);
		Table = newTable;
		for (int i = 0; i < oldTable.size(); i++){
			DumbInsert(oldTable[i]);//lest us bypass rehashing
			
		}
	}
	
	int* find(int val){
		int hash = Hash(val);
		int* output = &Table[hash];
		if (!output){
			return nullptr;
		}else{
			while (*output != val){
				if (!Table[hash]){
                                        return nullptr;
                                }
                                hash++;
				output = &Table[hash];
                                if (hash == Table.size()){
                                        hash = 0;
                                }
			}
			return output;
		}
	}

};
