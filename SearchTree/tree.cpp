#include "tree.hpp"
#include<iostream>
#include <vector>
#include <string>

Tree<int>* TestInsert(){
	Tree<int>* t = new Tree<int>();
	t->insert(50);
	t->insert(25);
	t->insert(100);
	t->insert(10);
	
//	t->print();

	/*
	if (t->Head->Value != 50){
		std::cout << "insert failed";
	}

	if (t->Head->Left->Value != 25){
		std::cout << "insert failed on 25";
	}

	if (t->Head->Left->Left->Value != 10){
                std::cout << "insert failed on 10";
        }*/
	return t;
}

Tree<int>* TestDelete() {
	Tree<int>* t = new Tree<int>();
        t->insert(50);
        t->insert(25);
        t->insert(100);
        t->insert(10);
	t->insert(75);
	t->insert(76);
	t->insert(74);
	//t->print();

	t->erase(t->Head->Right->Left);
	return t;
}

Tree<int>* TestFind(){
	Tree<int>* t = new Tree<int>();
	std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
	for (int i = 0; i < values.size(); i++){
		t->insert(values[i]);
	}
	Node<int>* p = t->Head->Left->Left;
	Node<int>* output = t->find(10);
	if (p != output){
		return t;
	}
	Tree<int>* q = new Tree<int>(); //it worked!
	Node<int>* goodHead = new Node<int>(666, nullptr, nullptr, nullptr);
	q->Head = goodHead;
	return t;
}


Tree<int>* TestCopConstruct(){
        Tree<int>* t = new Tree<int>();
        std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }
        
	Tree<int>* alsot = new Tree<int>(*t);
	//t->print();
	//alsot->print();
        
	Tree<int>* q = new Tree<int>(); //it worked!
        Node<int>* goodHead = new Node<int>(666, nullptr, nullptr, nullptr);
        q->Head = goodHead;
        return alsot;
}

Tree<int> TestCopAssign(){

}

int main(){
	Tree<int>* t;
        t = TestInsert();
	t = TestDelete();
	t = TestFind();
	t = TestCopConstruct();
	t->print();
        return 0;
}

