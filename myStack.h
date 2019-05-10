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
