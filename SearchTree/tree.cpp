#include "tree.hpp"
#include<iostream>

void TestInsert(){
	Tree<int>* t = new Tree<int>();
	t->insert(50);
	t->insert(25);
	t->insert(100);
	t->insert(10);
	if (t->Head->Value != 50){
		std::cout << "insert failed";
	}

	if (t->Head->Left->Value != 25){
		std::cout << "insert failed on 25";
	}

	if (t->Head->Left->Left->Value != 10){
                std::cout << "insert failed on 10";
        }
}


int main(){
        TestInsert();
        return 0;
}

