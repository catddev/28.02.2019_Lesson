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
void printArray(const int *const a, int n) { // хотим только использовать указатель, а не менять данные или адреса
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void fillArray(int * const a, int n) {// данные меняем, а адреса нет
	for (int i = 0; i < n; i++)
		a[i] = rand() % 50;
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

int* newArray(const int *const a, int n, int &newSize, bool(*f)(int)) { // сам массив и размер нельзя по ссылке, т.к тогда он изменится и другие функции будут работать не с исходным
	int count = 0;
	
	int *tmp;
	for (const int *p = a; p < a + n; p++)
		if (f(*p)==true)
			count++;
		
	tmp = new int[count];
	int *tmp_p = tmp; // указатель на временный массив
	
	for (const int *p = a; p < a + n; p++)
	{
		if (f(*p)==true)
			*tmp_p++ = *p;
	}

	newSize = count;
	return tmp;
}
void chooseType(const int* const a, int n) {
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

			fillArray(a, n);

			printArray(a, n);

			chooseType(a, n);
			
			delete[] a;
		}
		break;
		case 3:
		{
			// void pointers

			int a=100, *ip;
			double b, *dp;
			char c;
			// error: ip=&b, dp=&a;

			void *vp;
			
			vp = &b;
			vp = chooseType;
			vp = &c;
			vp = &a;
			// error: cout<< *vp <<endl;
			cout << *((int*)vp) << endl; //для вывода значений перевести в тип конркетный (int*), (char*), (double*) , ведь войд не знает под ним инт или чар или даббл - 4, 1 или 8 байт

			void *vpp;
			int arr[10] = { 2, 6, 1, 3 };
			vpp = arr;
			cout << *((int*)vpp + 2) << endl;

		}
		break;
		case 4:
		{
			// неконстантный указатель на неконстантную переменнную
			int *p;
			int x, y;
			p = &x;
			p = &y;
			*p = 100;
			*p = 200;

			// неконстантный указаетель на константную переменную
			const int*p1;
			int x1 = 550, y1;
			p1 = &x1;
			p1 = &y1;
			// *p1 = 100; error, переназначать указатель можно, но не значение константной переменной под ним

			// константный указатель на неконстантную переменнную
			int x2, y2;
			int *const p2 = &x2; // при объявлении константного указателя надо сразу его назначать, адрес менять нельзя, но значение под ним можно
			// error p2=&y2;
			*p2 = 100;

			// константный указатель на константную переменнную
			int x3, y3;
			const int*const p3 = &x3;
			// p3 = &y3; error
			// *p3 = 100; error
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