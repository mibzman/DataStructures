template<typename T>
struct Node {
	T Value;
	Node* LeftChild
	Node* RightChild
	Node* Parent

	//borrowed from my linked list project last semester
	Node() = default;
	Node(T v, Node* l, Node* r, Node* p)
	:Value(v), LeftChild(l), RightChild(r), Parent(p){}

	Node & operator=(const Node & N){
		value = N.value;
		RightChild = N.RightChild;
		LeftChild = N.LeftChild;
		Parent = N.Parent
		return *this;
	}
}
