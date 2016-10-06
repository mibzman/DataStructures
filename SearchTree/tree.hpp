#include <stack>

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

	Tree(Node<T>* n)
	:Head(n){}

	 Tree(const Tree<T> & t){
                if (t->Head == nullptr){
			Head = nullptr;
                        return;
                }

		Head = t->Head;
		Node<T>* r = Head;
                Node<T>* n;
		Node<T>* temp;
                std::stack<Node<T>*> Stack;
		std::stack<Node<T>*> twoChild;

                Stack.push(t->Head);
                while(!Stack.empty()){
                        n = Stack.top();
			//do visit                        
			//insert(n);
			if (r->Value < n){
				r->Left = n;
				temp = r->Left;
			}else{
				r->Right = n;
				temp = r->Right;
			}
			temp->Parent = r;
			r = temp;	
			if (n->Left && n->Right){
				twoChild.push(r);
			}else if (!n->Left && !n->Right){
				//this resets r to the last node with two children so that our traversial of the new tree moves in step with our pre-order traversial
				r = twoChild.top();
				twoChild.pop();
			}

 
                        Stack.pop();
                        if (n->Right){
                                Stack.push(n->Right);
                        }
                        if (n->Left){
                                Stack.push(n->Left);
                        }
                }

        }

	Tree & operator=(const Tree & t){ //ugh, n^2log(n)).  not good
		Node<T>* p = Head;
                Node<T>* ThisParent;
                while (p) {
                        if (!p->Left && !p->Right){
                                ThisParent = p->Parent;
                                delete p;
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
                        if (p->Value > val) {
                                p = p->Right;
                        }else if (p->Value < val) {
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
			if (p->Value >= val) {
				p = p->Right;
				DidGoLeft = false; //I'm not entirely happy with this
			}else {
				p = p->Left;
				DidGoLeft = true;
			}	
		}
		Node<T>* temp =  new Node<T>(val, nullptr, nullptr, ThisParent);
		Node<T>* newNode = temp;
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


	~Tree(){
		Node<T>* p = Head;
		Node<T>* ThisParent;
		while (p) {
			if (!p->Left && !p->Right){
				ThisParent = p->Parent;
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
