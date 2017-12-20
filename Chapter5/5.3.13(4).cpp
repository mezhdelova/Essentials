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
	void push_front(int value);
	bool pop_front(int &value);
	void push_back(int value);
	int size();
private:
	// other members you may have used
	Node* head;
	Node* tail;
};
List::List() : head(nullptr),tail(nullptr)
{
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
	if (head == nullptr)
	{
		head = new_head;
		tail = head;
	}
	else {
		head = new_head;
	}
}
bool List::pop_front(int &value)
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
void List::push_back(int value)
{
	Node* new_head = new Node(value);
	if (head == nullptr)
	{
		head = new_head;
		tail = head;
	}
	else {
		head->next = new_head;
		head = new_head;
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
	List list;
	//
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	int value = 0;
	while (list.pop_front(value))
	{
		cout << value << endl;
	}
	return 0;
}
