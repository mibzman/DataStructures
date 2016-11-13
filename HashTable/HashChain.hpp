#include <vector>
#include <list>
#include <iostream>

struct Bucket {
	std::vector<int> List;
	int Size = 0;
	
	void Add(int val){
		List.push_back(val);
		Size++;
	}
	
	//TODO: implement me!
	int* Find(int val){
		int* output;
		for (int i = 0; i < Size; i++){
			output = &List[i];
			if (*output == val){
				return output;
			}
		}
		return nullptr;
		/*
		int* otuput = List.begin();
		while(output < List.end()){
			if (val == *output){
				return output;
			}
			output++;
		}
		return nullptr;
		*/
	}


	//I do this so I can play with using a linked list vs a vector without changing the hash table code
	int* Begin(){
		return &List[0];
	}

	int* End(){ 
                return &List[Size-1];
        }

};

struct SepHash {//a seperate chained hash table
	private:

	int KeyCount;

	int Hash(int key){
		return key % bucket_count();
	}
	public:
	std::vector<Bucket> Table;

	SepHash(){
		KeyCount = 0;
		Bucket emptyBucket = Bucket();
		std::vector<Bucket> newTable(8, emptyBucket);
                Table = newTable;
	}

	SepHash(const SepHash & other){
		KeyCount = other.key_count();
		Table = other.Table;
	}

	SepHash & operator=(const SepHash & other){
		KeyCount = other.key_count();
                Table = other.Table;
	}

	int load() const{
		return key_count() / bucket_count();
	}

	int key_count() const {
		return KeyCount;
	}

	int bucket_count() const{
		return Table.size();
	}

	void insert(int key){
		int hash = Hash(key);
		if (load() > .75){
			rehash(bucket_count() * 2);
		}
		Table[hash].Add(key);
		KeyCount++;
	}

	void rehash(int size){
		Bucket emptyBucket = Bucket();
		std::vector<Bucket> oldTable = Table; 
		//we have to do it this way to make the hash function work right
		KeyCount = 0;
		std::vector<Bucket> newTable(size, emptyBucket);
		Table = newTable;
		for (int i = 0; i < oldTable.size(); i++){
			Bucket thisBucket = oldTable[i];
			for (int i = 0; i < thisBucket.Size; i++){
				int newHash = Hash(thisBucket.List[i]);
				Table[newHash].Add(thisBucket.List[i]);
				KeyCount++;
			}
		}
	}
	
	

};
