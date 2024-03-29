#include <stack>
#include <queue>
#include <iostream>

template<typename T>
struct AVLNode {
	T Value;
	int Height = 1; //the height of the subtree
	AVLNode* Left;
	AVLNode* Right;
	AVLNode* Parent;

	AVLNode() = default;

	AVLNode(T v, AVLNode* l, AVLNode* r, AVLNode* p)
	:Value(v), Left(l), Right(r), Parent(p){}

	AVLNode & operator=(const AVLNode & N){
		Value = N.Value;
		Right = N.Right;
		Left = N.Left;
		Parent = N.Parent;
		Height = N.Height;
		return *this;
	}

};

template<typename T>
struct AVLTree {
	AVLNode<T>* Head;

	AVLTree()
	:Head(nullptr){}
	
	/*
        average: O(n)
        worst case: O(n)
        again, we have to traverse the whole set
        */
	 AVLTree(const AVLTree<T> & t){
                if (t.Head == nullptr){
			Head = nullptr;
                        return;
                }

		Head = new AVLNode<T>(*t.Head);
		AVLNode<T>* r = Head;
                AVLNode<T>* n;
		
                std::stack<AVLNode<T>*> Stack;
		std::stack<AVLNode<T>*> twoChild;

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
			AVLNode<T>* newAVLNode = new AVLNode<T>(*n);
			if (r->Value > n->Value){
				r->Left = newAVLNode;
			}else{
				r->Right = newAVLNode;
			}
			newAVLNode->Parent = r;
			r = newAVLNode;

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

	/*
        average: O(k+n)
        worst case: O(k+n)
        again, we have to traverse the whole set of both the old and the new tres
        */
	AVLTree & operator=(const AVLTree & t){
		AVLNode<T>* p = Head;
                AVLNode<T>* ThisParent;
                while (Head) {
			
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
		AVLTree newAVLTree = AVLTree(t);
		Head = newAVLTree->Head;
		return *this;

	}

	/*
        average: O(log(n))
        worst case: O(log(n))
        since the avl tree is always balanced we reduce the search time for all cases
        */
	AVLNode<T>* find(T val) {
		AVLNode<T>* p = Head;
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


	/*
	average case: O(2log(n))
	worst case: O(2.5log(n))
	we have the same comlexity for both since the tree is always balanced.  
	on average we have to work our way down to find the insertion point and then work our way back up and rebalance.
	the actual rotation is a constant time operation, but in the worst case we would have to rotate every other node which would be O(1/2log(n))
	*/
	void insert(T val) {
		if (Head == nullptr){
			AVLNode<T>* temp = new AVLNode<T>(val, nullptr, nullptr, nullptr);
			Head = temp;
			return;
		}
		AVLNode<T>* p = Head;
		AVLNode<T>* ThisParent;
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
		AVLNode<T>* newAVLNode =  new AVLNode<T>(val, nullptr, nullptr, ThisParent);
		if (DidGoLeft){
			ThisParent->Left = newAVLNode;
		}else{
			ThisParent->Right = newAVLNode;
		}
		if(!newAVLNode){
			//breakpoint
		}
		balance(newAVLNode);
	}

	

	 /*
        average case: O(log)n))
        worst case: O(2log(n))
        the average case arises when we are deleting a node with zero or one children
        the worst case is if we have a large set and we are deleting the head and have to traverse all the way to the bottom to get the successor,
	and then all the way back up to rebalance 
        */
	void erase(AVLNode<T>* k){
		AVLNode<T>* p = k->Parent;
		AVLNode<T>* parent = k->Parent;
		if (k->Left && k->Right){
			AVLNode<T>* r = successor(k);
			k->Value = r->Value;
			parent = r;
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
		balance(parent);
	}

	AVLNode<T>* successor(AVLNode<T>* k){
		AVLNode<T>* p = k->Right;
		AVLNode<T>* output;
		while (p){
			output = p;
			p = p->Left;
		}
		return output;
	}

	void print(){
		std::cout << "digraph G {" << std::endl;
		AVLNode<T>* n;
                std::stack<AVLNode<T>*> Stack;
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

	//a convenience function because i'm that lazy
	void stitch(AVLNode<T>* parent, AVLNode<T>* child, bool IsLeft){
		if (IsLeft){
			parent->Left = child;
		}else{
			parent->Right = child;
		}
		if(child){
			child->Parent = parent;
		}
	}

	//assumes: https://upload.wikimedia.org/wikipedia/commons/2/23/Tree_rotation.png
	void rotateRight(AVLNode<T>* q, AVLNode<T>* p){
		if (Head == q){
			Head = p;
		}
		if (q->Parent){
			AVLNode<T>* superRoot = q->Parent;
			if(superRoot->Left == q){
				stitch(superRoot, p, true);
			}else{
				stitch(superRoot, p, false);
			}
		}else{
			p->Parent = nullptr;
		}
		AVLNode<T>* a = p->Left;
		AVLNode<T>* b = p->Right;
		AVLNode<T>* c = q->Right;
		
		stitch(p, a, true);
		stitch(p, q, false);
		stitch(q, b, true);
		stitch(q, c, false);
	}

	void rotateLeft(AVLNode<T>* p, AVLNode<T>* q){
		if (Head == p){
                        Head = q;
                }

                AVLNode<T> debug = *p;
		if (p->Parent){
                        AVLNode<T>* superRoot = p->Parent;
                        if(superRoot->Left == p){
                                stitch(superRoot, q, true);
                        }else{
                                stitch(superRoot, q, false);
                        }
                }else{
                        q->Parent = nullptr;
                }

		AVLNode<T>* a = p->Left;
                AVLNode<T>* b = q->Left;
                AVLNode<T>* c = q->Right;

                stitch(q, p, true);
                stitch(q, c, false);
                stitch(p, a, true);
                stitch(p, b, false);
        }

	int getHeight(AVLNode<T>* p){//yet another lazy function
		if(p){
			return p->Height;
		}
		return 0;
	}
	
	void balance(AVLNode<T>* p){//where p is a newly inserted node
		
		if(!p){
			//breakpoint
		}
		if (p->Parent == nullptr){
			//std::cout <<"root";
			return;
		}
		//std::cout<<"balancing";
		
		int balance;
		AVLNode<T>* q = p->Parent;
		while(q){
			if(!p){
				break;
			}
			//std::cout << " " << p->Value;
			
			//AVLNode<T> debug = *q;
			AVLNode<T> debug2 = *p;
			
			p->Height = std::max(getHeight(p->Left), getHeight(p->Right)) + 1;
			//std::cout << p->Height;
			balance = getHeight(p->Right) - getHeight(p->Left);
			
			if (balance <= -2){
			//	std::cout<< "rotate right";
				rotateRight(p, p->Left);
				//balance = 0;
				//AVLNode<T>* temp = q;
				q = p->Parent;
				p = p->Right;
			}
			if (balance >= 2){
				//std::cout<< "rotate left";
				rotateLeft(p, p->Right);
                               // balance = 0;
				//AVLNode<T>* temp = q;
                                q = p->Parent;
                                p = p->Left;
			}
			if(p){
				p = q->Parent;
			}
			if(q){
				q = q->Parent;
			}
		}
		//std::cout << std::endl;
	}


	~AVLTree(){
		AVLNode<T>* p = Head;
		AVLNode<T>* ThisParent;
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
