#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <bitset>

using namespace std;

void fillArr(int* a, int num, unsigned char *sortVar)
{
	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
		sortVar[a[i] / 8] = sortVar[a[i] / 8] | (1 << 7 - (a[i] % 8));//т.к. биты считаются справа налево, а нам надо заполнить битовый массив слева направо, мы должны из максимального номера бита (63) вычитать значение считанной переменной
	}
}

void bitSort(int* arr, int num, unsigned char *sortVar, int sortVarSize)
{
	int arrIndex = 0;
	for (int i = 0; i < sortVarSize; i++)//Проходимся по всему битовому массиву векторов
	{
		for (int j = 0; j < 8; j++)//проходимся по всему битовому вектору
		{
			if (sortVar[i] & (1 << 7 - j))//если текущий бит (слева направо считаем) в векторе равен 1, то число есть в исходном массиве
			{
				arr[arrIndex] = j + i * 8;//записываем номер бита в элемент массива вместо его текущего значения; все исходные значения массива хранятся в битовом векторе
				arrIndex++;
			}
		}
	}
}

void printArr(int* a, int num)
{
	cout << endl << "Array:";
	for (int i = 0; i < num; i++)
	{
		cout << ' ' << a[i];
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 16;//меняя число, увеличиваем размер входных данных
	const int arrSize = n * 8;
	int arr[arrSize];
	int num;//количество чисел в массиве
	unsigned char sortVar[n];//массив переменнах, выступающих в качестве последовательности бит, которая значением i-го элемента умноженного на 8 плюс номер j бита показывает наличие элемента со значением i*8+j в массиве.
	for (int i = 0; i < n; i++)
	{
		sortVar[i] = 0;//Одна переменная из массива sortVar включает в себя до 8 чисел
	}
	cout << endl << "Введите количество входных данных (не больше " << n*8 << "): ";
	cin >> num;
	cout << endl << "Вводите числа, не превышающие " << n*8 << ": ";
	fillArr(arr, num, sortVar);//заполнение массива (числами [0,64))
	printArr(arr, num);//вывод начального неосортированного массива
	cout << endl << "Полученный битовый массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << bitset<8>(sortVar[i]);
	}
	bitSort(arr, num, sortVar, n);//сортировка массива с помощью полученного битового вектора
	printArr(arr, num);//вывод отсортированного массива
	return 0;
}
