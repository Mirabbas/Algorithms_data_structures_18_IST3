#include <iostream>
using namespace std;
int getValue(int border)
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		int value;
		cin >> value;

		if (cin.fail() || (value > border) || (value <= 0)) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Please, enter the positive number less then " << border + 1 << ": ";
		}
		else
		{
			cin.ignore(32767, '\n'); // удаляем лишние значения

			return value;
		}
	}
}
void create_lot(int stones[], int size) //создание массива весов камней
{
	cout << size << " stones in the heap. Weight:\n";
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ": ";
		stones[i] = getValue(1000);
	}
}
void arrange_lot(int stones[], int size) //сортировка по убыванию
{
	int i, j, cur;
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (stones[i] < stones[j])
			{
				cur = stones[i];
				stones[i] = stones[j];
				stones[j] = cur;
			}
}
void arrange_bags(int stones[], int size) //создание двух куч, как можно более близких по весу
{
	int sum1 = 0, sum2 = 0, k1 = 0, k2 = 0, i;
	int* bag1 = new int[size - 1];
	int* bag2 = new int[size - 1];
	for (i = 0; i < size; i++)
	{
		if (sum1 <= sum2)
		{
			bag1[k1] = stones[i];
			sum1 += stones[i];
			k1++;
		}
		else
		{
			bag2[k2] = stones[i];
			sum2 += stones[i];
			k2++;
		}
	}
	if (1.0 * sum1 / sum2 <= 1.5)
	{
		cout << "\nHeap 1: ";
		for (i = 0; i < k1; i++)
			cout << bag1[i] << " ";
		cout << "\nWeight 1: " << sum1 << endl;
		cout << "\nHeap 2: ";
		for (i = 0; i < k2; i++)
			cout << bag2[i] << " ";
		cout << "\nWeight 2: " << sum2 << endl;
	}
	else cout << "The difference in weight is more than 1.5\n";
	delete[] bag1;
	delete[] bag2;
}
int main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	cout << "Enter the number of stones less then 21:\nNumber = ";
	n = getValue(20);
	int *lot = new int [n];
	create_lot(lot, n);
	arrange_lot(lot, n);
	arrange_bags(lot, n);
	delete[] lot;
	cin.get();
	return 0;
}