﻿#include <iostream>
using namespace std;
int main()
{
	int size;
	std::cout << "Enter size: "; std::cin >> size;
	int* a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < size; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
