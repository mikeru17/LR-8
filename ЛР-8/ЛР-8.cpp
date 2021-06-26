#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

const string TASK1_DESCRIPT = "Задача 1.\nСоставить программу, которая будет считывать введённое пятизначное число. После чего, каждую цифру этого числа необходимо вывести в новой строке.\n\n";
const string TASK2_DESCRIPT = "Задача 2.\nНапишите программу, которая позволяет пользователю ввести в консоли латинскую букву нижнего регистра, переводит её в верхний регистр и результат выводит в консоль.\n\n";
const string TASK3_DESCRIPT = "Задача 3.\nНаписать функцию, подсчитывающую среднее арифметическое целого массива. Предварительно объявив и, при необходимости, инициализировав переменные.\n\n";
const int COUNT = 5;

// Задача 1.
void RunTask1() {
	int number;

	cout << "Введите ваше 5-тизначное число: ";
	do {
		cin >> number;
		// Проверяем на пятизначность.
		if (abs(number / 10000) >= 10 || abs(number / 10000) == 0) cout << "Пожалуйста, введите 5-тизначное число: ";
	} while (abs(number / 10000) >= 10 || abs(number / 10000) == 0);

	// Делаем копию number, чтобы не потерять его значение (т.к. будем отбрасывать цифры числа).
	int copyNumber = number;
	// Массив цифр числа copyNumber.
	int arr[COUNT];

	// Т.к. цифры числа будут отбрасываться с конца,
	// пускаем обратный цикл, чтобы в последний элемент массива пошла последняя цифра,
	// в предпоследний - предпоследняя и т.д.
	for (int i = COUNT - 1; i >= 0; i--) {
		arr[i] = copyNumber % 10;
		copyNumber /= 10;
	}

	cout << "\nКаждая цифра введенного числа в новой строке:\n";
	for (int i = 0; i < COUNT; i++)
	{
		if (i != COUNT - 1) cout << arr[i] << "\n";
		else cout << arr[i];
	}
}

// Задача 2.
void RunTask2() {
	char letter;
	cout << "Введите вашу латинскую букву в нижнем регистре: ";
	cin >> letter;

	// Переводим букву в верхний регистр.
	letter -= 32;
	cout << "\nВаша латинская буква в верхнем регистре: " << letter;
}

// Задача 3.
void RunTask3() {
	int arr[COUNT];
	float average = 0;
	cout << "Ввод массива из " << COUNT << " элементов\n";
	for (int i = 0; i < COUNT; i++) {
		cout << "Введите " << i << "-й элемент: ";
		cin >> arr[i];
		average += arr[i];
	}
	average /= COUNT;

	cout << "\nСреднее арифметическое вашего массива: " << average;
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "----- ЛР-8 начала выполнение! -----\n\n";
	int userChoice;
	// Главное меню для перехода между задачами.
	do
	{
		cout << "----- Главное меню -----\n";
		cout << "Что вы хотите сделать?\nНа выбор есть 4 варианта:\n";
		cout << "1 - Задача 1\n2 - Задача 2\n3 - Задача 3\n0 - Выход\n\nВведите номер вашего выбора: ";
		cin >> userChoice;
		cout << "\n";

		switch (userChoice)
		{
		case 1:
			cout << TASK1_DESCRIPT;
			RunTask1();
			break;
		case 2:
			cout << TASK2_DESCRIPT;
			RunTask2();
			break;
		case 3:
			cout << TASK3_DESCRIPT;
			RunTask3();
			break;
		case 0:
			cout << "Выбран вариант выхода из программы. Программа завершается...\n\n";
			break;
		default:
			cout << "Введен некорректный номер. Пожалуйста, повторите попытку";
			break;
		}

		if (userChoice != 0)
		{
			cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
		}
	} while (userChoice != 0);

	system("pause");
	return 0;
}
