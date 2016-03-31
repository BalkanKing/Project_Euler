#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	int temp;
	int numbers[20][20];
	ifstream table;

	table.open("table.txt");

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			table >> numbers[i][j];
	}

	/*
	just to see if everithing is right

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			cout << numbers[i][j] << ' ';
		cout << '\n';
	}
	*/

	table.close();

	int max_product = 0;
	for (int i = 0; i < 20; i++)
		for(int j = 0; j < 17; j++)
			if (numbers[i][j] * numbers[i][j + 1] * numbers[i][j + 2] * numbers[i][j + 3] > max_product)
				max_product = numbers[i][j] * numbers[i][j + 1] * numbers[i][j + 2] * numbers[i][j + 3];

	for (int i = 0; i < 17; i++)
		for(int j = 0; j < 20; j++)
			if (numbers[i][j] * numbers[i + 1][j] * numbers[i + 2][j] * numbers[i + 3][j] > max_product)
				max_product = numbers[i][j] * numbers[i + 1][j] * numbers[i + 2][j] * numbers[i + 3][j];

	for (int i = 0; i < 17; i++)
		for(int j = 0; j < 17; j++)
			if (numbers[i][j] * numbers[i + 1][j + 1] * numbers[i + 2][j + 2] * numbers[i + 3][j + 3] > max_product)
				max_product = numbers[i][j] * numbers[i + 1][j + 1] * numbers[i + 2][j + 2] * numbers[i + 3][j + 3];

	for (int i = 3; i < 20; i++)
		for(int j = 0; j < 17; j++)
			if (numbers[i][j] * numbers[i - 1][j + 1] * numbers[i - 2][j + 2] * numbers[i - 3][j + 3] > max_product)
				max_product = numbers[i][j] * numbers[i - 1][j + 1] * numbers[i - 2][j + 2] * numbers[i - 3][j + 3];

	cout << max_product << '\n';
	cin >> temp;
}
