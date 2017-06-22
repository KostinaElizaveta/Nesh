
           #include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

using namespace std;

void matrix::print()
{
	int i, j;
	cout << "\t";
	for (j = 0; j < m; j++) cout << "  " << j+1 << "\t";
	cout << "\n";
	for (i = 0; i < n; i++)
		{
			cout << i+1 << "\t";
			for (j = 0; j < m; j++)
				cout << "(" << A[i][j] << ";" << B[i][j] << ")\t";
			cout << "\n";
		}
}

void matrix::init() //Инициализация игорной матрицы
{
	int i, j;
	cout << "Введите размерность матрицы\n";
	cin >> n >> m;
	A = new int * [n];
	B = new int * [n];
	for (i = 0; i < n; i++)
		{
		A[i] = new int [m];
		B[i] = new int [m];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}

}

void matrix::init_i() //Инициализация известной игры
{
	n = 2;
	m = 2;
	A = new int * [n];
	B = new int * [n];
	for (int i = 0; i < n; i++)
		{
			A[i] = new int [m];
			B[i] = new int [m];
		}
}

void matrix::zakl() //Инициализация дилеммы заключенного
{
	A[0][0] = -8; A[0][1] = 0; A[1][0] = -10; A[1][1] = -1;
	B[0][0] = -8; B[0][1] = -10; B[1][0] = 0; B[1][1] = -1;
}

void matrix::spor() //Инициализация семейного спора
{
	A[0][0] = 4; A[0][1] = 0; A[1][0] = 0; A[1][1] = 1;
	B[0][0] = 1; B[0][1] = 0; B[1][0] = 0; B[1][1] = 4;
}

void matrix::perekrestok() //Инициализация перекрестка
{
	A[0][0] = 2; A[0][1] = 1; A[1][0] = 4; A[1][1] = 0;
	B[0][0] = 2; B[0][1] = 4; B[1][0] = 1; B[1][1] = 0;
}



bool matrix::pareto(int** &A, int** &B, int x, int y)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			{
				if ((A[i][j] > A [x][y] && B [i][j] >= B [x][y]) || (A[i][j] >= A [x][y] && B [i][j] > B [x][y]))
				return false;
			}
	return true;
}

bool matrix::nash(int** &A, int** &B, int x, int y)
{
	int i, j;
	for (i = 0; i < n; i++)
		if (A[i][y] > A[x][y]) return false;
	for (j = 0; j < m; j++)
		if (B[x][j] > B[x][y]) return false;
	return true;

}

void matrix::check() //Проверка
{
	cout << "\n\nУстойчивость по Нэшу\n";
	bool fl = true;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if (nash (A, B, x, y))
			{
				cout << "(" << A[x][y] << "; " << B[x][y] << ") - Ситуация [" << x << "," << y << "]\n";
				fl = false;
			}
	if (fl) cout << "Пустое множество\n";

	cout << "Оптимальность по Парето\n";
	fl = true;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if (pareto (A, B, x, y))
			{
				cout << "(" << A[x][y] << "; " << B[x][y] << ") - Ситуация [" << x << "," << y << "]\n";
				fl = false;
			}
	if (fl) cout << "Пустое множество\n";

	cout << "Пересечение множеств\n";
	fl = true;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if ((nash(A, B, x, y)) && (pareto(A, B, x, y)))
			{
				cout << "(" << A[x][y] << "; " << B[x][y] << ") - Ситуация [" << x << "," << y << "]\n";
				fl = false;
			}
	if (fl) cout << "Пустое множество\n";
}


void matrix::clear() //Очистка памяти
{
	for (int i = 0; i < n; i++)
		{
			delete A[i];
			delete B[i];
		}
	delete [] A;
	delete [] B;
}

void matrix::random()
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			{
				A[i][j] = rand() % 7 + 1;
				B[i][j] = rand() % 9 + 1;
			}
}


