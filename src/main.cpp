#include "matrix.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	bool flag = true;
	int i, a;
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);


	do {
		cout << "\n1 - Дилемма заключенного\n2 - Семейный спор\n3 - Перекресток\n4 - Случайная матрица\n5 - Закончить работу программы\n \n";
		cin >> a;
		switch (a)
		{
			case 1:
			{
				matrix *one = new matrix;
					one->init_i();
					one->zakl();
					one->print();
					one->check();
					one->clear();

				flag = false;
				break;
			}

			case 2:
			{
				matrix *one = new matrix;
					one->init_i();
					one->spor();
					one->print();
					one->check();
					one->clear();

				flag = false;
				break;
			}

			case 3:
			{
				matrix *one = new matrix;
					one->init_i();
					one->perekrestok();
					one->print();
					one->check();
					one->clear();

				flag = false;
				break;
			}


			case 4:
			{
				matrix *one = new matrix;
					one->init();
					one->random();
					one->print();
					one->check();
					one->clear();

				flag = false;
				break;
			}
			case 5:
			{
				flag = true;
				break;
			}
			default:
			{
				cout << "Значение неккоректно" << endl;
				break;
			}
		}
	} while (!flag);

	system("pause");
	return 0;
}

