/*
program name: LinkedList.cpp
programmer:	  Andrew Valle
Date:		  3-17-2018
*/

#include <iostream>
using namespace std;

template <class T>

class LinkedList {
private:
	struct Node {
		T data;
		Node *next;
	};

	Node *head;		//Head Pointer

public:
	//constructor
	LinkedList() {
		head = NULL;
	}

	//destructor
	~LinkedList()
	{
		Node *nodePtr;   // To traverse the list.
		Node *nextNode; // To point to the next node.

						// Position nodePtr at the head of the list.
		nodePtr = head;

		// While nodePtr is not at the end of the list.
		while (nodePtr != NULL)
		{
			// Save a pointer to the next node.
			nextNode = nodePtr->next;

			// Delete the current node.
			delete nodePtr;

			// Position nodePtr at the next node.
			nodePtr = nextNode;
		}
	}


	void addNode(T);
	void insertNode(T);
	void display();
	void deleteNode(T);
	void reverse();
	void menuDisplay();
	int search(T);
	void mergeArray(T[], int);
};

template <class T>
	void LinkedList<T>::addNode(T num) {
		Node *n; // To point to a new node.
		Node *nPtr; // To move through the list.


		n = new Node;
		n->data = num;
		n->next = NULL;

		// If there are no nodes in the list.
		// make newNode the first node.
		if (!head)
			head = n;
		else // else, insert newNode at end.
		{
			// Initialize nPtr to head of list.
			nPtr = head;

			// Find the last node in the list.
			while (nPtr->next)
				nPtr = nPtr->next;

				// Insert newNode as the last node.
				nPtr->next = n;
		}
}

template <class T>
	void LinkedList<T>::insertNode(T num) {
		Node *curr;
		Node *n;
		Node *preNode;
		n = new Node;
		n->data = num;
		n->next = NULL;

		if (head == NULL) {
			head = n;
		}

		else {
			curr = head;
			preNode = NULL;

			while (curr != NULL && curr->data < num) {
				preNode = curr;
				curr = curr->next;
			}

			if (preNode == NULL) {  //only one node we have
				head = n;
				n->next = curr;
			}

			else {            //insert after the previos node
				preNode->next = n;
				n->next = curr;

			}
		}
}

template <class T>
void LinkedList <T>::display() {
	Node *curr;
	curr = head;

	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

template <class T>
	void LinkedList <T>::deleteNode(T m) {
		Node *delptr = NULL;
		Node *temp;
		Node *curr;

		temp = head;
		curr = head;

		while (curr != NULL && curr->data != m) {
			temp = curr;
			curr = curr->next;
		}

		if (curr == NULL) {
			cout << m << " not in list. " << endl;
			delete delptr;
		}

		else {
			delptr = curr;
			curr = curr->next;
			temp->next = curr;

			if (delptr == head) {
				head = head->next;
				temp = NULL;
			}
			delete delptr;

			cout << "The Value " << m << " was deleted. " << endl;
		}

}

template <class T>
	void LinkedList<T>::reverse() 
	{
		Node *previous;
		Node *current;
		Node *next;

		previous = NULL;

		// Position current at the head of the list.
		current = head;

		if (head == NULL)
		{
			cout << "The list is empty." << endl;
			return;
		}

		else {
			while (current != NULL)
			{
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}

			head = previous;
		}
}

template <class T>
void LinkedList<T>::menuDisplay() {
	char choice;
	T num;
	T *list = NULL;

	do {
		cout << "Menu:" << endl;
		cout << "1. Add Node to End of List. " << endl;
		cout << "2. Insert Node Numerically. " << endl;
		cout << "3. Delete Node. " << endl;
		cout << "4. Display Node List. " << endl;
		cout << "5. Reverse List. " << endl;
		cout << "6. Search for Position of Number. " << endl;
		cout << "7. Merge Array into Linked List. " << endl;
		cout << "q. Quit. " << endl;
		cin >> choice;
		cout << endl;


		switch (choice) {
		case '1':
			cout << "Enter the number you want to add. ";
			cin >> num;
			addNode(num);
			cout << endl;
			break;
		case '2':
			cout << "Enter the number you want to insert. ";
			cin >> num;
			insertNode(num);
			cout << endl;
			break;
		case '3':
			cout << "Enter the number you want to delete. ";
			cin >> num;
			deleteNode(num);
			cout << endl;
			break;
		case '4':
			display();
			cout << endl;
			break;
		case '5':
			reverse();
			cout << endl;
			break;
		case '6':
			cout << "Enter the number you want to search for. ";
			cin >> num;

			if (search(num) == -1)
			{
				cout << "The number " << num << " is not on the list. " << endl << endl;
			}

			else
			{
				cout << num << " is at positon " << search(num) << ". " << endl << endl;
			}
			break;
		case '7':
			int arraySize;
			cout << "How many numbers do you want to add? ";
			cin >> arraySize;
			list = new T[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				cout << "Enter number " << (i + 1) << ": ";
				cin >> list[i];
			}

			mergeArray(list, arraySize);
			delete[] list;
			cout << endl << endl;
			break;
		default:
			break;
		}

	}

	while (choice != 'q');
}

template <class T>
int LinkedList<T>::search(T x) 
{
	Node *check;
	int position = 0;
	int listLength = 0;
	check = head;

	while (check != NULL)
	{
		if (check->data == x)
		{
			return position;
		}

		position++;
		listLength++;
		check = check->next;
	}

	return -1;
}

template <class T>
void LinkedList<T>::mergeArray(T x[], int y)
{
	T *tempArray;
	T temp;
	Node *n;
	tempArray = new T[y];

	for (int i = 0; i < y; i++)
	{
		tempArray[i] = x[i];
	}

	
	for (int i = 0; i<y; i++)
	{
		for (int j = i + 1; j<y; j++)
		{
			if (tempArray[i]<tempArray[j])
			{
				temp = tempArray[i];
				tempArray[i] = tempArray[j];
				tempArray[j] = temp;
			}
		}
	}
	

	for (int i = 0; i < y; i++)
	{
		n = new Node;
		n->data = tempArray[i];
		if (head != NULL)
		{
			n->next = head;
			head = n;
		}

		else
		{
			head = n;
			n->next = NULL;
		}
	}


	cout << endl;

}


int main()
{
	char choice;
	cout << "do you want to create a Linked List of Integers or Doubles? (I = Integers, D=Doubles) ";
	cin >> choice;

	if (choice == 'I') {
		LinkedList<int> l;
		l.menuDisplay();
	}

	else {
		LinkedList<double> l;
		l.menuDisplay();
	}
	

	return 0;
}

