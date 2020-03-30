#include <iostream>
#include "qs.h"
using namespace std;


void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " ;
	}
	cout << endl;
}

int main()
{
	int n;
	int i;

	cout << "Enter array size: ";

	while (!(cin >> n) || (cin.peek() != '\n') || (n <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Wrong number. Enter correct number \n";
	}


	int* arr = new int[n];
	for (i = 0; i < n; i++) {
		cout << "Array[" << i + 1 << "]: ";
		cin >> arr[i];
		cout << endl;

		

	}

	cout << "Entered array: ";
	print(arr, n);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: ";
	print(arr, n);

	system("pause");
}
