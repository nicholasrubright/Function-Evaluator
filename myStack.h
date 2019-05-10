#include <iostream>
#include <string>
using namespace std;

class List;

class Node
{
private:
	int value;
	Node* prev;
	Node* next;
public:
	Node(int value, Node* prev = NULL, Node* next = NULL);
	friend class List;
};

class List
{
private:
	Node* h;
	Node* t;
public:
	List();
	~List();
	bool IsEmpty() const;
	int getHead() const;
	int getTail() const;
	void addToHead(int v);
	void addToTail(int v);
	int removeHead();
	int removeTail();
	void addToEmpty(int v);
	bool hasOne() const;
	void removeLast();

	friend ostream& operator<< (ostream& os, const List& list);
	operator string() const;
};

List::List()
{
	h = t = NULL;
}

bool List::IsEmpty() const
{
	return (h == NULL);
}

Node::Node(int v, Node* p, Node* n)
{
	value = v;
	prev = p;
	next = n;
}

bool List::hasOne() const
{
	return (h != NULL && h == t);
}

void List::removeLast()
{
	if (hasOne() == true)
	{
		delete h;
		h = t = NULL;
	}
}

List::~List()
{
	while (h != NULL)
	{
		Node* r = h;
		h = h->next;
		delete r;
	}
	h = t = NULL;
}

void List::addToEmpty(int v)
{
	Node* r = new Node(v);
	r->next = NULL;
	r->prev = NULL;
	h = r;
	t = r;
}

int List::getHead() const
{
	return h->value;
}

int List::getTail() const
{
	return t->value;
}

void List::addToHead(int v)
{
	if (IsEmpty())
		addToEmpty(v);
	else
	{
		Node* r = new Node(v, NULL, NULL);
		r->next = h;
		h->prev = r;
		h = r;
	}
}

void List::addToTail(int v)
{
	if (IsEmpty())
		addToEmpty(v);
	else
	{
		Node* r = new Node(v, NULL, NULL);
		r->prev = t;
		t->next = r;
		t = r;
	}
	
}

int List::removeHead()
{
	if (hasOne())
	{
		int t = getHead();
		removeLast();
		return t;
	}
	else
	{

	}
}