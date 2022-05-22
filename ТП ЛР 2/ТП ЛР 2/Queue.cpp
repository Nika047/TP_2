#include "Queue.h"
#include <ctime>

Queue::Queue() 
{
	int n;
	srand(time(NULL));
	size = 3 + rand() % 7;
	for (int i = 0; i < size; ++i)
	{
		n = rand() % 100;
		QueueElement *element = new QueueElement(n, head);
		this -> head = element;
	}
};

void Queue::SetHead(QueueElement* elem)
{
	this->head = elem;
}

void Queue::Push(int elem)
{
	QueueElement *element = new QueueElement(elem, head);
	this->head = element;
}

int Queue::Pop()
{
	if (Zero()) 
		return -1;

	QueueElement *last = this->head;
	QueueElement *prev = last;

	while (last)
	{
		if (last->GetPrev()) 
		{
			prev = last;
			last = last->GetPrev();
		}
		else
			break;
	}
	int val = last->GetData();
	prev->SetPrev(nullptr);
	delete last;
	return val;
}

QueueElement* Queue::GetHead()
{
	return head;
}

void Queue::Print()
{
	QueueElement *current = this->head;
	while (current)
	{
		std::cout << current->GetData();
		current = current->GetPrev();
		if (current)
			std::cout << "  ||  ";
	}
	std::cout << std::endl;
}

bool Queue::Zero()
{
	return this->head == nullptr;
}

void Queue::operator+=(int el) 
{
	QueueElement *element = new QueueElement(el, head);
	this->head = element;
}

Queue Queue::operator+(int el) 
{
	QueueElement *last = this->head;

	do
	{
		*last += el;
	} while (last = last->GetPrev());

	return *this;
}

void Queue::operator-=(int el) 
{
	Pop();
}

Queue Queue::operator-(int el) 
{
	QueueElement *last = this->head;

	do
	{
		*last += -el;
	} while (last = last->GetPrev());

	return *this;
}

void Queue::operator*=(int el)
{
	Queue *newQueue = new Queue;
	newQueue->head = new QueueElement(*this->head);
	QueueElement *current = newQueue->head;

	while (current)
	{
		QueueElement *prev = current->GetPrev();

		if (prev) 
		{
			QueueElement *tmp = new QueueElement(*prev);
			current->SetPrev(tmp);
			current = tmp;
		}
		else break;
	}

	current = newQueue->GetHead();

	while (current->GetPrev())
		current = current->GetPrev();

	current->SetPrev(this->GetHead());
	this->SetHead(newQueue->GetHead());
}

Queue Queue::operator*(int el)
{
	QueueElement *last = this->head;

	do
	{
		*last *= el;
	} 
	while (last = last->GetPrev());

	return *this;
}

Queue operator!(const Queue &queue)
{
	QueueElement *last = queue.head;

	do
	{
		*last *= -1;
	} while (last = last->GetPrev());

	return queue;
}



Queue & Queue::operator--()
{
	int num;
	cout << "¬ведите число: ";
	cin >> num;

	QueueElement *last = this->head;

	do
	{
		*last -= num;
	} while (last = last->GetPrev());

	return *this;
}

Queue Queue::operator--(int)
{
	QueueElement *last = this->head;

	do
	{
		*last -= size*2;
	} while (last = last->GetPrev());

	return *this;
}

Queue & Queue::operator++()
{
	int num;
	cout << "¬ведите число: ";
	cin >> num;

	QueueElement *last = this->head;

	do
	{
		*last += num;
	} while (last = last->GetPrev());

	return *this;
}

Queue Queue::operator++(int)
{
	QueueElement *last = this->head;

	do
	{
		*last += size;
	} while (last = last->GetPrev());

	return *this;
}