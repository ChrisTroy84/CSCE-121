#ifndef NODE
#define NODE

struct Node {
	int num;
	Node* next;

	// No Default constructor
	Node(int val):num(val), next(nullptr) {} // remember to initialize next to nullptr

  // The function below is written. Do not modify it
	virtual ~Node() {}
    // write copy constructor and copy assignment to remove warnings
    Node(const Node& src):num(src.num), next(nullptr) {}
    Node& operator=(const Node& src) { num = src.num; next = nullptr; return *this; } 
    // don't have to worry about self assignment here
};

#endif
