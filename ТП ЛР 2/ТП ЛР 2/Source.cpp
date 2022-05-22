#include <iostream>
#include <conio.h>
#include "Queue.h"
#include "Dimensions.h"

using namespace std;

Queue* queue = new Queue();

void menu();
void QueueLoop();
void DimensionsLoop();
void enter();

int main()
{

	setlocale(LC_ALL, "Russian");

	menu();
}

void menu()
{
	int command = 0;

	cout << "�������� ��������: \n";
	cout << "1. �������� ������� �������  \n";
	cout << "2. �������� ������� �������  \n";
	cout << "3. �����  \n";
	cout << "\n�������� ����� �������: ";
	cin >> command;
	cout << endl;

	switch (command)
	{
	case 1:
		QueueLoop();
		break;

	case 2:
		DimensionsLoop();
		break;

	default:
		cout << "����� ������� �� ���������� \n\n";
	}
}

void QueueLoop()
{
	system("cls");
	int num;
	int command = 0;

	while (1)
	{
		queue->Print();

		cout << "\n������ ��������� ��������: \n\n";
		cout << "1. �������� ������� (+=) \n";
		cout << "2. ������� ������� (-=) \n";
		cout << "3. ����������� �������� (*=) \n\n";
		cout << "4. ���������� �� �������� ����� (++int) \n";
		cout << "5. ���������� �� ������ ������� (int++) \n";
		cout << "6. ���������� �� �������� ����� (--int) \n";
		cout << "7. ���������� �� ��� ������� ������� (int--) \n";
		cout << "8. �������� ������������� �������� (!) \n\n";
		cout << "9. ����� � ���� \n\n";
		cout << "�������� ����� �������: ";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << "������� �����: ";
			cin >> num;
			*queue += num;
			cout << "��������� \n\n";
			enter();
			break;

		case 2:
			*queue -= 1;
			cout << "������� \n\n";
			enter();
			break;

		case 3:
			*queue *= 2;
			cout << "������������ \n\n";
			enter();
			break;

		case 4:
			++(*queue);
			enter();
			break;

		case 5:
			(*queue)++;
			enter();
			break;

		case 6:
			--(*queue);
			enter();
			break;

		case 7:
			(*queue)--;
			enter();
			break;

		case 8:
			!(*queue);
			enter();
			break;

		case 9:
			system("cls");
			menu();
			break;

		default:
			cout << "����� ������� �� ���������� \n\n";
		}
		system("cls");
	}
}

void DimensionsLoop()
{
	Dimensions Dimensions1 = Dimensions();
	Dimensions Dimensions2 = Dimensions();

	system("cls");

	int num;
	int command = 0;

	while (1)
	{
		Dimensions1.Print();
		Dimensions2.Print();

		cout << "\n������ ��������� ��������: \n\n";
		cout << "1. �������� == ��� �������� 1 � �������� 2 \n";
		cout << "2. �������� != ��� �������� 1 � �������� 2 \n";
		cout << "3. �������� == ��� �������� 1 � ����� \n";
		cout << "4. �������� != ��� �������� 1 � ����� \n";
		cout << "5. �������� �������������� � int \n";
		cout << "6. �������� �������������� � float \n";
		cout << "7. ����� � ����� \n";
		cout << "8. ���� � ����� \n\n";
		cout << "9. ����� � ���� \n\n";
		cout << "�������� ����� �������: ";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << ((Dimensions1 == Dimensions2) ? "�����" : "�� �����") << endl;
			enter();
			break;

		case 2:
			cout << ((Dimensions1 != Dimensions2) ? "�� �����" : "�����") << endl;
			enter();
			break;

		case 3:
			cout << "������� �����: ";
			cin >> num;
			cout << ((Dimensions1 == num) ? "�����" : "�� �����") << endl;
			enter();
			break;

		case 4:
			cout << "������� �����: ";
			cin >> num;
			cout << ((Dimensions1 != num) ? "�� �����" : "�����") << endl;
			enter();
			break;

		case 5:
			cout << (int) Dimensions1 << endl;
			enter();
			break;

		case 6:
			cout << (float) Dimensions1 << endl;
			enter();
			break;

		case 7:
			cout << Dimensions1;
			enter();
			break;

		case 8:
			cin >> Dimensions1;
			enter();
			break;

		case 9:
			system("cls");
			menu();
			break;

		default:
			cout << "����� ������� �� ���������� \n\n";
		}
		system("cls");
	}
}

void enter()
{
	cout << "������� ENTER \n";
	_getch();
}