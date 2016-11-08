#include "AVLtree.hpp"
#include<iostream>
#include <vector>
#include <string>

AVLTree<int>* TestInsert(){
	AVLTree<int>* t = new AVLTree<int>();
	std::vector<int> values = {50,49,48,47,46,45,44,43,42,41};
	srhgsgasgasgasgsdg
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
		//t->print();
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

AVLTree<int>* TestLeftRotate(){
	AVLTree<int>* t = new AVLTree<int>();
        /*std::vector<int> values = {50, 51, 52,9,8,7,6,5,4,3};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }*/
        
	t->insert(50);
        t->insert(51);
        t->insert(48);
        t->insert(47);

	//t->print();

	t->rotateLeft(t->Head, t->Head->Right);


        return t;

}


AVLTree<int>* TestRightRotate(){
        AVLTree<int>* t = new AVLTree<int>();
        /*std::vector<int> values = {50, 51, 52,9,8,7,6,5,4,3};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
        }*/

        t->insert(50);
        t->insert(51);
        t->insert(48);
        t->insert(47);

        //t->print();

        t->rotateRight(t->Head, t->Head->Left);


        return t;

}


AVLTree<int>* TestDelete() {
	AVLTree<int>* t = new AVLTree<int>();
        std::vector<int> values = {50,49,48,47,46,45,44,43,42,41};
        for (int i = 0; i < values.size(); i++){
                t->insert(values[i]);
                //t->print();
        }
 

	AVLNode<int>* q = t->find(44);
	t->print();
	t->erase(q);
	//t->print();
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
	return q;
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

/*
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
*/

int main(){
	AVLTree<int>* t;
        t = TestInsert();
	t = TestLeftRotate();
	t = TestRightRotate();
	t = TestDelete();

	//t = TestFind();
	/*t = TestCopConstruct();
	t = TestCopAssign();
	//t = TestHeight();*/
	t->print();
        return 0;
}

