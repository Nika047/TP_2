#pragma once
#include <iostream>
#include <sstream>    

using namespace std;

class Dimensions
{
public:
	friend bool operator==(const Dimensions &d1, int num);
	friend bool operator!=(const Dimensions& d1, int num);

	Dimensions();
	bool operator==(const Dimensions& d1);
	bool operator!=(const Dimensions& d1);
	void Print();

	operator int();
	operator float();

	friend ostream& operator<<(ostream &out, Dimensions& d);
	friend istream& operator>>(istream &out, Dimensions& d);

	double h, w, l;

private:
};