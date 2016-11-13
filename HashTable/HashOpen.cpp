#include "HashOpen.hpp"
#include <iostream>

void TestInsert(){
	OpenHash table;
	table.insert(5);
	table.insert(10);
	if (table.Table[5] != 5){
		 std::cout << "TestInsert broke" << std::endl;
	}

	if (table.Table[2] != 10){
                 std::cout << "TestInsert broke" << std::endl;
        }
}

void TestRehash(){
	OpenHash table;
	std::vector<int> values = {50, 25, 100, 10, 75, 76, 74, 4, 99};
	for (int i = 0; i < values.size(); i++){
		table.insert(values[i]);
	}

	if (table.Table[2] != 50){
                 std::cout << "TestRehash broke" << std::endl;
        }

	if (table.Table[9] != 25){
                 std::cout << "TestRehash broke" << std::endl;
        }
}

void TestCopyConstruct(){
	OpenHash table;
        table.insert(5);
        table.insert(10);
	OpenHash newTable = OpenHash(table);

	if (newTable.Table[5] != 5){
                 std::cout << "TestCopyConstruct broke" << std::endl;
        }

        if (newTable.Table[2] != 10){
                 std::cout << "TestCopyConstruct broke" << std::endl;
        }
}

void TestCopyAssign(){
        OpenHash table;
        table.insert(5);
        table.insert(10);
        OpenHash newTable;
	newTable.insert(50);
        newTable.insert(100);

	newTable = table;

        if (newTable.Table[5] != 5){
                 std::cout << "TestCopyAssign broke" << std::endl;
        }

        if (newTable.Table[2] != 10){
                 std::cout << "TestCopyAssign broke" << std::endl;
        }
}


void TestTableFind(){
	OpenHash table;
        std::vector<int> values = {50, 25, 100, 10, 75, 76, 74, 4, 99};
        for (int i = 0; i < values.size(); i++){
                table.insert(values[i]);
        }

	int* found = table.find(25);

	if (!found){
                std::cout << "TestEnd broke" << std::endl;
        }

        if (*found != 25){
                std::cout << "TestEnd broke" << std::endl;
        }
}


void OpenHashTest(){
	TestInsert();
	TestRehash();
	TestCopyConstruct();
	TestCopyAssign();
	TestTableFind();
}

int main(){
	//do stuff
	//BucketTest();
	OpenHashTest();
	return 0;
}
