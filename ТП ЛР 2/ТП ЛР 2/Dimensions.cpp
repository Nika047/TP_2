#include "Dimensions.h"

Dimensions::Dimensions()
{
	double h, w, l;

	cout << "Введите 3 числа (высота, ширина, длина): \n";
	cin >> h;
	cin >> w;
	cin >> l;

	this->h = h;
	this->w = w;
	this->l = l;
};

bool Dimensions::operator==(const Dimensions& d1)
{
	cout << this->h << ((this->h == d1.h) ? " == " : " != ") << d1.h << endl;
	cout << this->w << ((this->w == d1.w) ? " == " : " != ") << d1.w << endl;
	cout << this->l << ((this->l == d1.l) ? " == " : " != ") << d1.l << endl;

	return (this->h == d1.h) && (this->w == d1.w) && (this->l == d1.l);
}

bool Dimensions::operator!=(const Dimensions& d1)
{
	return !this->operator==(d1);
}

void Dimensions::Print()
{
	cout << "Высота: " << this->h << " Ширина: " << this->w << " Длина: " << this->l << endl;
}

Dimensions::operator int()
{
	return (int) (h * w * l);
}

Dimensions::operator float()
{
	return (float) (h * w * l);
}

ostream & operator<<(ostream & out, Dimensions& d)
{
	out << "Высота: " << d.h << " Ширина: " << d.w << " Длина: " << d.l << endl;
	return out;
}

istream & operator>>(istream & input, Dimensions& d)
{
	cout << "Введите 3 числа (высота, ширина, длина): \n";

	input >> d.h;
	input >> d.w;
	input >> d.l;

	return input;
}

bool operator==(const Dimensions& d1, int num)
{
	cout << d1.h << ((d1.h == num) ? " == " : " != ") << num << endl;
	cout << d1.w << ((d1.w == num) ? " == " : " != ") << num << endl;
	cout << d1.l << ((d1.l == num) ? " == " : " != ") << num << endl;

	return (d1.h == num) && (d1.w == num) && (d1.l == num);
}

bool operator!=(const Dimensions& d1, int num)
{
	return !(d1 == num);
}