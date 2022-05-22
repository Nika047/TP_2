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

	cout << "Выберите действие: \n";
	cout << "1. Проверка первого задания  \n";
	cout << "2. Проверка второго задания  \n";
	cout << "3. Выход  \n";
	cout << "\nВыберите номер команды: ";
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
		cout << "Такой команды не существует \n\n";
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

		cout << "\nСписок возможных действий: \n\n";
		cout << "1. Добавить элемент (+=) \n";
		cout << "2. Извлечь элемент (-=) \n";
		cout << "3. Дублировать элементы (*=) \n\n";
		cout << "4. Увеличение на заданное число (++int) \n";
		cout << "5. Увеличение на размер очереди (int++) \n";
		cout << "6. Уменьшение на заданное число (--int) \n";
		cout << "7. Уменьшение на два размера очереди (int--) \n";
		cout << "8. Получить отрицательные значения (!) \n\n";
		cout << "9. Выход в меню \n\n";
		cout << "Выберите номер команды: ";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << "Введите число: ";
			cin >> num;
			*queue += num;
			cout << "Добавлено \n\n";
			enter();
			break;

		case 2:
			*queue -= 1;
			cout << "Удалено \n\n";
			enter();
			break;

		case 3:
			*queue *= 2;
			cout << "Дублированно \n\n";
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
			cout << "Такой команды не существует \n\n";
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

		cout << "\nСписок возможных действий: \n\n";
		cout << "1. Оператор == для Габариты 1 и Габариты 2 \n";
		cout << "2. Оператор != для Габариты 1 и Габариты 2 \n";
		cout << "3. Оператор == для Габариты 1 и число \n";
		cout << "4. Оператор != для Габариты 1 и число \n";
		cout << "5. Оператор преобразования в int \n";
		cout << "6. Оператор преобразования в float \n";
		cout << "7. Вывод в поток \n";
		cout << "8. Ввод в поток \n\n";
		cout << "9. Выход в меню \n\n";
		cout << "Выберите номер команды: ";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << ((Dimensions1 == Dimensions2) ? "Равны" : "Не равны") << endl;
			enter();
			break;

		case 2:
			cout << ((Dimensions1 != Dimensions2) ? "Не равны" : "Равны") << endl;
			enter();
			break;

		case 3:
			cout << "Введите число: ";
			cin >> num;
			cout << ((Dimensions1 == num) ? "Равны" : "Не равны") << endl;
			enter();
			break;

		case 4:
			cout << "Введите число: ";
			cin >> num;
			cout << ((Dimensions1 != num) ? "Не равны" : "Равны") << endl;
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
			cout << "Такой команды не существует \n\n";
		}
		system("cls");
	}
}

void enter()
{
	cout << "Нажмите ENTER \n";
	_getch();
}