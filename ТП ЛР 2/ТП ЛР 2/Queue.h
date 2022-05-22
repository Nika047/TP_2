#pragma once
#include <iostream>
#include <sstream>
#include "QueueElement.h"

using namespace std;

class Queue
{
public:
	Queue();

	friend Queue operator! (const Queue &queue);

	void operator-=(int el);
	Queue operator - (int el);

	void operator+=(int el);
	Queue operator+(int el);

	Queue& operator++();     
	Queue operator++(int);   

	Queue& operator--();     
	Queue operator--(int);  

	void operator*=(int el);
	Queue operator*(int el);

	void Push(int element);
	int Pop();
	void Print();
	bool Zero();
	QueueElement* GetHead();
	void SetHead(QueueElement* elem);

private:
	QueueElement *head;
	int number;
	int size;
};