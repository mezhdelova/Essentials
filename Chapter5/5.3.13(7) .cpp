#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
	//cout << "+Node" << endl;
}
Node::~Node()
{
	//cout << "-Node" << endl;
}
class List
{
public:
	List();
	List(List &other);
	void push_front(int value);
	bool pop_front(int &value);
		void push_back(int value);
	bool pop_back(int &value);
		int at(int index);
		void insert_at(int index, int value);
		void remove_at(int index);
		int size();
private:
	// other members you may have used
	Node* head;
	Node* tail;
};
List::List() : head(nullptr),tail(nullptr)
{
}
List::List(List &other)
{
	Node* temp = other.head;
	Node* newHead = new Node(other.head->value);
	head = newHead;
	for (int i = 1; i < other.size(); i++)
	{
		Node* newChild = new Node(temp->next->value);
		newHead->next = newChild;
		temp = temp->next;
		newHead = newHead->next;

	}
}
int List::size()
{
	Node* memento = head;
	int size = 0;
	while (memento != nullptr)
	{
		size++;
		memento = memento->next;
		
	}
	delete memento;
	return size;
}
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
}
bool List::pop_back(int &value)
{
	if (tail != nullptr)
	{
		Node* popped = tail;
		tail = popped->next;
		
		value = popped->value;
		delete popped;
		return true;
	}
	return false;
}
bool List::pop_front(int &value)
{
	if (head != nullptr)
	{
		Node* popped = tail;
		head = popped->next;
		tail = tail->next;
		value = popped->value;
		delete popped;
		return true;
	}
	return false;
	
}
void List::push_back(int value)
{
	Node* new_head = new Node(value);
	if (head == nullptr)
	{
		head = new_head;
		tail = head;
	}
	else {
		tail->next = new_head;
		tail = new_head;
	}
}
int List::at(int i)
{
	Node* pointer = head;
	int position = 0;
	while (pointer != nullptr)
	{
		if (position == i)
			return pointer->value;
		position++;
		pointer = pointer->next;

	}
	delete pointer;
	return -1;
}
void List::remove_at(int n)
{
	
		if ((head != NULL) && (n < size()) && (n >= 0)) 
		{
			
			Node *temp = head, *helping = head;

			for (int i = 0; i < n; i++)
			{
				helping = temp; 
				temp = temp->next;
			}

			if (temp == head) 			{
				head = temp->next;
			}
			else
			{
				helping->next = temp->next;
			}
			
			free(temp);
		}
}
void List::insert_at(int pos, int val)
{
	Node* inserted = new Node(val);
	Node* temp = head;
	Node* helping = head;
	if (pos == 0)
	{
		
		inserted->next = temp;
		head = inserted;
	}
	else
	{

		for (int i = 0; i < pos; i++)
		{
			helping = temp;
			temp = temp->next;
		}
		helping->next = inserted;
		inserted->next = temp;
	}
}
void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == "<< list.at(i) << endl;
	}
}

//List::~List()
//{
//	while (head != nullptr)
//	{
//		Node* deleted = head;
//		head = head->next;
//		delete deleted;
//	}
//}

// ...
int main()
{
	List list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	cout << "list1" << endl;
	printList(list1);
	cout << endl;
	List list2(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;
	list1.insert_at(1, 6);
	list2.remove_at(2);
	cout << "list1" << endl;
	printList(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;
	return 0;
}
