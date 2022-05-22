#pragma once

class QueueElement {
public:
	QueueElement(int data, QueueElement *prev);
	QueueElement(const QueueElement &QueueElement);

	~QueueElement();
	int GetData();
	void operator+=(int num);
	void operator-=(int num);
	void operator*=(int num);
	void operator/=(int num);

	QueueElement* GetPrev();
	void SetPrev(QueueElement* prev);

private:
	int data;
	QueueElement *prev;
};