#include <stack>
#include <iostream>

template<typename T>
struct Node {
	T Value;
	Node* Left;
	Node* Right;
	Node* Parent;

	//borrowed from my linked list project last semester
	Node() = default;

	Node(T v, Node* l, Node* r, Node* p)
	:Value(v), Left(l), Right(r), Parent(p){}

	Node & operator=(const Node & N){
		Value = N.Value;
		Right = N.Right;
		Left = N.Left;
		Parent = N.Parent;
		return *this;
	}
};

template<typename T>
struct Tree { //the non-balanced tree
	Node<T>* Head;

	Tree()
	:Head(nullptr){}

	/*
	Tree(T n){
		Head = new Node<T>(n, nullptr, nullptr, nullptr);
	}*/

	 Tree(const Tree<T> & t){
                if (t.Head == nullptr){
			Head = nullptr;
                        return;
                }

		Head = new Node<T>(*t.Head);
		Node<T>* r = Head;
                Node<T>* n;
		Node<T>* temp;
                std::stack<Node<T>*> Stack;
		std::stack<Node<T>*> twoChild;

                 if (t.Head->Left){
                        Stack.push(t.Head->Left);
                 }
                 if (t.Head->Right){
                        Stack.push(t.Head->Right);
                 }

		twoChild.push(Head);
                while(!Stack.empty()){
			
                        n = Stack.top();
			//do visit 
			Node<T>* newNode = new Node<T>(*n);
			if (r->Value > n->Value){
				r->Left = newNode;
			}else{
				r->Right = newNode;
			}
			newNode->Parent = r;
			r = newNode;

			if (n->Left && n->Right){
				twoChild.push(r);
			}else if (!n->Left && !n->Right){
				//this resets r to the last node with two children so that our traversial of the new tree moves in step with our pre-order traversial
				if(!twoChild.empty()){
					r = twoChild.top();
                                	twoChild.pop();
				}
			}

 			
                        Stack.pop();
                        if (n->Left){
                                Stack.push(n->Left);
                        }
                        if (n->Right){
                                Stack.push(n->Right);
                        }
                }
        }

	Tree & operator=(const Tree & t){
		Node<T>* p = Head;
                Node<T>* ThisParent;
                while (Head) {
			//erase(Head);
			
                        if (!p->Left && !p->Right){
                                ThisParent = p->Parent;
                                erase(p);
                                p = ThisParent;
                        } else if (!p->Left) {
                                p = p->Right;
                        } else {
                                p = p ->Left;
                        }
                }
		Tree newTree = Tree(t);
		Head = newTree->Head;
		return *this;

	}


	Node<T>* find(T val) {
		Node<T>* p = Head;
		while(p) {
                        if (val > p->Value) {
                                p = p->Right;
                        }else if (val < p->Value) {
                                p = p->Left;
                        }else{
				return p;
			}
                }
		return p;
	}	

	void insert(T val) {
		if (Head == nullptr){
			Node<T>* temp = new Node<T>(val, nullptr, nullptr, nullptr);
			Head = temp;
			return;
		}
		Node<T>* p = Head;
		Node<T>* ThisParent;
		bool DidGoLeft;
		while(p) {
			ThisParent = p;
			if (val >=p->Value) {
				p = p->Right;
				DidGoLeft = false; //I'm not entirely happy with this
			}else {
				p = p->Left;
				DidGoLeft = true;
			}	
		}
		Node<T>* newNode =  new Node<T>(val, nullptr, nullptr, ThisParent);
		if (DidGoLeft){
			ThisParent->Left = newNode;
		}else{
			ThisParent->Right = newNode;
		}
	}

	void erase(Node<T>* k){
		Node<T>* p = k->Parent;
		if (k->Left && k->Right){
			Node<T>* r = successor(k);
			k->Value = r->Value;
			erase(r); //r could have a right child
		}else if(k->Left){
			if (p->Left == k){
				p->Left = k->Left;
			}else{
				p->Right = k->Left;
			}
			k->Left->Parent = p;
			delete k;
		}else if(k->Right){
                        if (p->Left == k){
                                p->Left = k->Right;
                        }else{
                                p->Right = k->Right;
                        }
                        k->Right->Parent = p;
			delete k;
		}else{
			if (p->Left == k){
                                p->Left = nullptr;
                        }else{
                                p->Right = nullptr;
                       }
			delete k;
		}
	}

	Node<T>* successor(Node<T>* k){
		Node<T>* p = k->Right;
		Node<T>* output;
		while (p){
			output = p;
			p = p->Left;
		}
		return output;
	}

	void print(){
		std::cout << "digraph G {" << std::endl;
		Node<T>* n;
                std::stack<Node<T>*> Stack;
		int counter = 0;
		int otherCounter = 0;

                Stack.push(Head);
                while(!Stack.empty()){
                        n = Stack.top();
                        //do visit
			if (!n->Parent){
				std::cout << "HEAD" << "->" << n->Value << ";" << std::endl;
			}else{
				std::cout << n->Parent->Value <<  "->" << n->Value  << ";" << std::endl;  
			}
			if (!n->Left) {
				std::cout << n->Value << "->" << "Leftnull" << counter << ";" << std::endl;
			
			}
			if (!n->Right) {
                                std::cout << n->Value <<"->" << "Righttnull" << counter << ";" << std::endl;
			
                        }
			counter++;

                        Stack.pop();
                        if (n->Right){
                                Stack.push(n->Right);
                        }
                        if (n->Left){
                                Stack.push(n->Left);
                        }
        	}
		std::cout << "}";
	}


	~Tree(){
		Node<T>* p = Head;
		Node<T>* ThisParent;
		while (p) {
			if (!p->Left && !p->Right){
				ThisParent = p->Parent;
				if(ThisParent->Left == p){
					ThisParent->Left = nullptr;
				}else{
					ThisParent->Right = nullptr;
				}
				delete p;
				p = ThisParent;
			} else if (!p->Left) {
				p = p->Right;
			} else {
				p = p ->Left;
			}
		}
	}

};
