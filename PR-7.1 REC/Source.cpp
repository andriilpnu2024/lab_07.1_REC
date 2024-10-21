#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);
void Delete(int** a, int rowCount,int i);
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i1, int i0);
void Change(int** a, const int col1, const int col2, const int rowCount,int j);
void rowmem(int** a, const int rowCount, const int colCount,int i);

int main()
{
	srand((unsigned)time(NULL));

	int rC = 9;
	int	cC = 6;
	int low = -21;
	int high = 34;
	int S = 0;
	int k = 0;
	int** a = new int* [rC];
	rowmem(a, rC, cC,0);
	Create(a, rC, cC, low, high,0,0);
	Print(a, rC, cC,0,0);
	Calc(a, rC, cC, S, k, 0, 0);
	Print(a, rC, cC,0,0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Sort(a, rC, cC,0,0);
	Print(a, rC, cC,0,0);
	Delete(a, rC, 0);
	delete[] a;
	return 0;
}
void rowmem(int** a, const int rowCount, const int colCount,int i)
{
	a[i] = new int[colCount];
	if (i < rowCount - 1)
		rowmem(a,rowCount,colCount,i+1);
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}


void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Sort(int** a, const int rowCount, const int colCount, int i1, int i0)
{
	if ((a[0][i1] < a[0][i1 + 1])
		||
		(a[0][i1] == a[0][i1 + 1] &&
			a[1][i1] < a[1][i1 + 1])
		||
		(a[0][i1] == a[0][i1 + 1] &&
			a[1][i1] == a[1][i1 + 1] &&
			a[2][i1] > a[2][i1 + 1]))
	{
		Change(a, i1, i1 + 1, rowCount, 0);
	}
if (i1 < colCount - 2 - i0)
	Sort(a,rowCount,colCount,i1+1,i0);
else
	if (i0 < colCount-2)
		Sort(a, rowCount, colCount, 0, i0+1);
}
void Change(int** a, const int col1, const int col2, const int rowCount , int j)
{
	int tmp;
	tmp = a[j][col1];
	a[j][col1] = a[j][col2];
	a[j][col2] = tmp;
	if(j < rowCount-1)
	{
		Change(a, col1, col2, rowCount, j + 1);
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k,int i,int j)
{
	if (a[i][j] % 3 == 0 && a[i][j] > 0)
	{
		S += a[i][j];
		k++;
		a[i][j] = 0;
	}
	if (j < colCount - 1)
		Calc(a, rowCount, colCount, S, k, i, j+1);
	else
		if (i < rowCount - 1)
			Calc(a, rowCount, colCount, S, k, i+1, 0);
}

void Delete(int** a, int rowCount , int i)
{
	delete[] a[i];
	if (i < rowCount - 1)
		Delete(a, rowCount, i + 1);
	return;
}