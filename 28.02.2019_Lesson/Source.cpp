#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

bool asc(int a, int b) {
	return (a > b); // возвращает 1 TRUE ри данном условии
}
bool desc(int a, int b) {
	return (a < b);
}

void bubbleSort(int *a, int n, bool(*f)(int, int)){
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (f(a[j], a[j + 1]) == true) // переданная функция определяет порядок сортировки
				swap(a[j], a[j + 1]);
	
}
void printArray(int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// 14.	***Реализовать 3 функции каждая из которых принимает указатель на массив и количество элементов и возвращает указатель на новый массив.
// Первая функция ищет простые числа и заносит их в новый массив,
// вторая – все числа кратные трем,
// третья – все четные числа.
// Затем напишите функцию, которая принимает указатель на одну из этих функций, а указатель на массив и количество элементов.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию.
// Простое число – это число, которое делиться ТОЛЬКО на 1 и на себя(2, 5, 7, 11 и т.д.).
// Рекомендации :
// Сначала посчитайте количество простых элементов в массиве, потом уже создайте новый массив и занесите туда эти числа.

bool isPrime(int a) {
	if (a == 0) return false;
	for (int i = 2; i < abs(a); i++)
		if (a%i == 0) return false;
	return true;
}
bool isEven(int a) {
	return(a % 2 == 0);
}
bool isTimes3(int a) {
	return(a % 3 == 0);
}

int* newArray(int*a, int n, int &newSize, bool(*f)(int)) { // сам массив и размер нельзя по ссылке, т.к тогда он изменится и другие функции будут работать не с исходным
	int count = 0;
	
	int *tmp;
	for (int *p = a; p < a + n; p++)
		if (f(*p)==true)
			count++;
		
	tmp = new int[count];
	int *tmp_p = tmp; // указатель на временный массив
	
	for (int *p = a; p < a + n; p++)
	{
		if (f(*p)==true)
			*tmp_p++ = *p;
	}

	newSize = count;
	return tmp;
}
void chooseType(int*a, int n) {
	bool(*fs[3])(int) = { isPrime, isEven, isTimes3 };
	int *b, b_size;

	int choice;
	while (true)
	{
		cout << "Enter 1 to create with prime numbers" << endl;
		cout << "Enter 2 to create with even numbers" << endl;
		cout << "Enter 3 to create with times 3 numbers" << endl;
		cin >> choice;
		if (choice < 1 || choice>3) break;
		b = newArray(a, n, b_size, fs[choice - 1]); // choice-1 тк. не по индексу 0-2 в массиве, а 1-3 порядковый номер из меню
		printArray(b, b_size);
		delete[] b;
		b = 0; //nullptr
	}
}



int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int arr[10] = {4, 7, 2, 12, 78, 21, -5, -8, 0, 4};
			bool(*fs[])(int, int) = { asc, desc };
			printArray(arr, 10);
			bubbleSort(arr, 10, fs[0]); //bubbleSort(arr, 10, asc);
			printArray(arr, 10);
			bubbleSort(arr, 10, fs[1]); //bubbleSort(arr, 10, desc);
			printArray(arr, 10);
		}
		break;
		case 2: //14
		{
			int*a;
			int n = 10;

			a = new int[n];

			for (int i = 0; i < n; i++)
				a[i] = rand() % 50;

			printArray(a, n);

			chooseType(a, n);
			
			delete[] a;
		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}