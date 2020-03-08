#include <iostream>
using namespace std;
int getValue(int border)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ����� ���������� ��������
	{
		int value;
		cin >> value;

		if (cin.fail() || (value > border) || (value <= 0)) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "Please, enter the positive number less then " << border + 1 << ": ";
		}
		else
		{
			cin.ignore(32767, '\n'); // ������� ������ ��������

			return value;
		}
	}
}
void create_lot(int stones[], int size) //�������� ������� ����� ������
{
	cout << size << " stones in the heap. Weight:\n";
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ": ";
		stones[i] = getValue(1000);
	}
}
void arrange_lot(int stones[], int size) //���������� �� ��������
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
void arrange_bags(int stones[], int size) //�������� ���� ���, ��� ����� ����� ������� �� ����
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