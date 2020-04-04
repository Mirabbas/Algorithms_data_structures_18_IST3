#include <iostream>
using namespace std;

int a = 0;
int b = 0;
int c = 0;

int p = 8;
int q = 7;
int r = 3;

int x[] = { 3, 5, 6, 8, 9, 10, 15, 21 };
int y[] = { 3, 4, 5, 6, 7, 8, 9 };
int z[] = { 7, 8, 9 };

int result;

int main()
{
	while (a < p)
	{
		while (x[a] > y[b] && b < q)
		{
			b++;
		}
		if (x[a] == y[b]) 
		{
			while (x[a] > z[c] && c < r)
			{
				c++;
			}
			if (x[a] == z[c]) 
			{				
				cout << "Ishodnie massivy:" << endl;
				cout << "Massiv a: ";
				for (int i = 0; i <= p; i++)
				{
					cout << x[i] << " ";
				}
				cout << "\n";
				cout << "Massiv b: ";
				for (int i = 0; i <= q; i++)
				{
					cout << y[i] << " ";
				}
				cout << "\n";
				cout << "Massiv c: ";
				for (int i = 0; i <= r; i++)
				{
					cout << z[i] << " ";
				}
				cout << "\n";
				cout << "Chislo naideno: " << x[a] << endl << "\n Ono nahoditsya v massivah \nx[" << a << "]  \ny[" << b << "]  \nz[" << c << "]"  << endl;
				cin >> result;
				return 0;
			}
		}
		a++;
	}

	return 0;
}
