#include "AVLtree.hpp"
#include<iostream>
#include <vector>
#include <string>

AVLTree<int>* TestInsert(){
	AVLTree<int>* t = new AVLTree<int>();
	std::vector<int> values = {50, 25, 10,9,8,7,6,5,4,3};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }
	//std::cout<<t->Head->Right->Left->Right->Right->Value;
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
	//std::cout<< "test";
	return t;
}

AVLTree<int>* TestDelete() {
	AVLTree<int>* t = new AVLTree<int>();
        t->insert(50);
        t->insert(25);
        t->insert(100);
        t->insert(10);
	t->insert(75);
	t->insert(76);
	t->insert(74);
	//t->print();

	t->erase(t->Head->Right->Left->Right);
	return t;
}

AVLTree<int>* TestFind(){
	AVLTree<int>* t = new AVLTree<int>();
	std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
	for (int i = 0; i < values.size(); i++){
		t->insert(values[i]);
	}
	AVLNode<int>* p = t->Head->Left->Left;
	AVLNode<int>* output = t->find(10);
	if (p != output){
		return t;
	}
	AVLTree<int>* q = new AVLTree<int>(); //it worked!
	AVLNode<int>* goodHead = new AVLNode<int>(666, nullptr, nullptr, nullptr);
	q->Head = goodHead;
	return t;
}


AVLTree<int>* TestCopConstruct(){
        AVLTree<int>* t = new AVLTree<int>();
        std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }
        
	AVLTree<int>* alsot = new AVLTree<int>(*t);
	//t->print();
	//alsot->print();
        
	AVLTree<int>* q = new AVLTree<int>(); //it worked!
        AVLNode<int>* goodHead = new AVLNode<int>(666, nullptr, nullptr, nullptr);
        q->Head = goodHead;
        return alsot;
}

AVLTree<int>* TestCopAssign(){
        AVLTree<int>* t = new AVLTree<int>();
        std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }

        AVLTree<int>* alsot = new AVLTree<int>();
	std::vector<int> values2 = {1,2,3,4,5,6,99,11,525,1245};
        for (int i = 0; i < values2.size(); i++){
                alsot->insert(values2[i]);
        }


	alsot = new AVLTree<int>(*t);
        //t->print();
        //alsot->print();

        AVLTree<int>* q = new AVLTree<int>(); //it worked!
        AVLNode<int>* goodHead = new AVLNode<int>(666, nullptr, nullptr, nullptr);
        q->Head = goodHead;
        return alsot;
}


AVLTree<int>* TestHeight(){
        AVLTree<int>* t = new AVLTree<int>();
        std::vector<int> values = {50, 25, 100, 10, 75, 76, 74};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }
        int output = t->Head->SubTreeHeight();
        if (output == 4){
                AVLTree<int>* q = new AVLTree<int>(); //it worked!
                AVLNode<int>* goodHead = new AVLNode<int>(666, nullptr, nullptr, nullptr);
                q->Head = goodHead;
                return q;
        }
        return t;
}

int main(){
	AVLTree<int>* t;
        t = TestInsert();
/*	t = TestDelete();
	t = TestFind();
	t = TestCopConstruct();
	t = TestCopAssign();
	t = TestHeight();*/
	t->print();
        return 0;
}

