// A simple C++ program for traversal of a linked list
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver code
int main()
{
	Node* head   =NULL;
	Node* second =NULL;
	Node* third  =NULL;
    Node* fourth =NULL;
    Node* fifth  =NULL;
    Node* sixth  =NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();
    fourth = new Node();
	fifth = new Node();
	sixth = new Node();

	head->data = 1;
	head->next = second; 

	second->data = 2; 
	second->next = third;

	third->data = 3; 
	third->next = NULL;

	printList(head);

	return 0;
}

// This is code is contributed by rathbhupendra
