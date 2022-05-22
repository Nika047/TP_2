#include "QueueElement.h"

QueueElement::QueueElement(int data, QueueElement *prev) {
	this->data = data;
	this->prev = prev;
}

QueueElement::QueueElement(const QueueElement &QueueElement) {
	this->data = QueueElement.data;
	this->prev = QueueElement.prev;
}

QueueElement::~QueueElement() {
	this->data = 0;
	this->prev = nullptr;
}

int QueueElement::GetData() 
{
	return data;
}

void QueueElement::operator+=(int num) {
	this->data += num;
}

void QueueElement::operator-=(int num) {
	this->data -= num;
}

void QueueElement::operator*=(int num) {
	this->data *= num;
}

void QueueElement::operator/=(int num) {
	this->data /= num;
}

QueueElement* QueueElement::GetPrev() {
	return prev;
}

void QueueElement::SetPrev(QueueElement* prev) {
	this->prev = prev;
}
