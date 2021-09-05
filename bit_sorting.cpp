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
		sortVar[a[i] / 8] = sortVar[a[i] / 8] | (1 << 7 - (a[i] % 8));//�.�. ���� ��������� ������ ������, � ��� ���� ��������� ������� ������ ����� �������, �� ������ �� ������������� ������ ���� (63) �������� �������� ��������� ����������
	}
}

void bitSort(int* arr, int num, unsigned char *sortVar, int sortVarSize)
{
	int arrIndex = 0;
	for (int i = 0; i < sortVarSize; i++)//���������� �� ����� �������� ������� ��������
	{
		for (int j = 0; j < 8; j++)//���������� �� ����� �������� �������
		{
			if (sortVar[i] & (1 << 7 - j))//���� ������� ��� (����� ������� �������) � ������� ����� 1, �� ����� ���� � �������� �������
			{
				arr[arrIndex] = j + i * 8;//���������� ����� ���� � ������� ������� ������ ��� �������� ��������; ��� �������� �������� ������� �������� � ������� �������
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
	const int n = 16;//����� �����, ����������� ������ ������� ������
	const int arrSize = n * 8;
	int arr[arrSize];
	int num;//���������� ����� � �������
	unsigned char sortVar[n];//������ ����������, ����������� � �������� ������������������ ���, ������� ��������� i-�� �������� ����������� �� 8 ���� ����� j ���� ���������� ������� �������� �� ��������� i*8+j � �������.
	for (int i = 0; i < n; i++)
	{
		sortVar[i] = 0;//���� ���������� �� ������� sortVar �������� � ���� �� 8 �����
	}
	cout << endl << "������� ���������� ������� ������ (�� ������ " << n*8 << "): ";
	cin >> num;
	cout << endl << "������� �����, �� ����������� " << n*8 << ": ";
	fillArr(arr, num, sortVar);//���������� ������� (������� [0,64))
	printArr(arr, num);//����� ���������� ����������������� �������
	cout << endl << "���������� ������� ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << bitset<8>(sortVar[i]);
	}
	bitSort(arr, num, sortVar, n);//���������� ������� � ������� ����������� �������� �������
	printArr(arr, num);//����� ���������������� �������
	return 0;
}
