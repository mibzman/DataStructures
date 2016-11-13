#include "HashChain.hpp"
#include <iostream>

void TestAdd(){
	Bucket bucket;
	bucket.Add(4);
	//std::cout << "yay";
}

void TestBegin(){
	Bucket bucket;
        bucket.Add(4);
	bucket.Add(6);
	auto test = bucket.Begin();
	if(*test != 4){
		std::cout << "TestGet broke" << std::endl;
	}
}

void TestEnd(){
	Bucket bucket;
        bucket.Add(4);
        bucket.Add(6);
        auto test = bucket.End();
        if(*test != 6){
                std::cout << "TestEnd broke" << std::endl;
        }

}

void TestFind(){
	Bucket bucket;
	bucket.Add(4);
        bucket.Add(6);
	int* found = bucket.Find(6);

	if (!found){
                std::cout << "TestEnd broke" << std::endl;
        }

	if (*found != 6){
		std::cout << "TestEnd broke" << std::endl;
	}
}

void BucketTest(){
	TestAdd();
	TestBegin();
	TestEnd();
}

void TestInsert(){
	SepHash table;
	table.insert(5);
	table.insert(10);
	if (*table.Table[5].Begin() != 5){
		 std::cout << "TestInsert broke" << std::endl;
	}

	if (*table.Table[2].Begin() != 10){
                 std::cout << "TestInsert broke" << std::endl;
        }
}

void TestRehash(){
	SepHash table;
	std::vector<int> values = {50, 25, 100, 10, 75, 76, 74, 4, 99};
	for (int i = 0; i < values.size(); i++){
		table.insert(values[i]);
	}

	if (*table.Table[2].Begin() != 50){
                 std::cout << "TestRehash broke" << std::endl;
        }

	if (*table.Table[9].Begin() != 25){
                 std::cout << "TestRehash broke" << std::endl;
        }
}

void TestCopyConstruct(){
	SepHash table;
        table.insert(5);
        table.insert(10);
	SepHash newTable = SepHash(table);

	if (*newTable.Table[5].Begin() != 5){
                 std::cout << "TestCopyConstruct broke" << std::endl;
        }

        if (*newTable.Table[2].Begin() != 10){
                 std::cout << "TestCopyConstruct broke" << std::endl;
        }
}

void TestCopyAssign(){
        SepHash table;
        table.insert(5);
        table.insert(10);
        SepHash newTable;
	newTable.insert(50);
        newTable.insert(100);

	newTable = table;

        if (*newTable.Table[5].Begin() != 5){
                 std::cout << "TestCopyAssign broke" << std::endl;
        }

        if (*newTable.Table[2].Begin() != 10){
                 std::cout << "TestCopyAssign broke" << std::endl;
        }
}


void SepHashTest(){
	TestInsert();
	TestRehash();
	TestCopyConstruct();
	TestCopyAssign();
}

int main(){
	//do stuff
	BucketTest();
	SepHashTest();
	return 0;
}
