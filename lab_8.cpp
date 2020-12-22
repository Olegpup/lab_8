#include <iostream>
#include <ctime>
using namespace std;

int** create_an_array(int n);
void array_filling(int** array, int n);
void show_array(int** array, int n);
void array_sorting(int** array, int n);
void diagonal(int** array, int n);

int main()
{
	srand(time(0));

	int size;
	int** A;

	cout << "Enter size of matrix: ";
	cin >> size;
	A = create_an_array(size);
	array_filling(A, size);
	cout << "Your matrix: " << endl;
	show_array(A, size);
	array_sorting(A, size);
	cout << "Sorted matrix: " << endl;
	show_array(A, size);
	cout << "Diagonal: " << endl;
	diagonal(A, size);

	return 0;
}

int** create_an_array(int n)
{
	int** array = new int* [n];

	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}
	return array;
}

void array_filling(int** array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 101;
		}
	}
}

void show_array(int** array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << array[i][j];
		}
		cout << endl;
	}
}

void array_sorting(int** array, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (array[i][j] < array[i][k])
				{
					temp = array[i][j];
					array[i][j] = array[i][k];
					array[i][k] = temp;
				}
			}
		}
	}
}

void diagonal(int** array, int n)
{
	for (int k = 0; k < n; k++)
	{
		cout.width(4);
		cout << array[k][k];
	}
}