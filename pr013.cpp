#include <gmp.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

/////GGWP, arithmetic is dead

using namespace std;

void main()
{
	mpz_t mas[100], sum;
	ifstream table;
	string temp;

	mpz_init(sum);

	table.open("table.txt");

	for(int i = 0; i < 100; i++)
	{
		table >> temp;
		mpz_set_str(mas[i], temp.data(), 10);
	}

	for(int i = 0; i < 100; i++)
	{
		mpz_add (sum, sum, mas[i]);
	}

	mpz_out_str (NULL, 10, sum);

	cin >> temp;
}
