//Long arithmetic is not very thrilling to write, gmp is better but mingw is much worse
//Because of very specific external dependencies this file alone is only of theoretical value

#include "gmp.h"
#include <iostream>

using namespace std;

void main()
{
	int wait;
	

	mpz_t result;
	mpz_init(result);
	mpz_set_str(result, "1", 10);

	mpz_t one;
	mpz_init(one);
	mpz_set_str(one, "1", 10);

	mpz_t current;
	mpz_init(current);
	mpz_set_str(current, "1", 10);

	for (int i = 0; i < 100; i++)
	{
		mpz_mul(result, result, current);
		mpz_add(current, current, one);
	}

	char* str_result;

	str_result = new char[mpz_sizeinbase (result, 10) + 2];

	mpz_get_str (str_result, 10, result);

	int sum = 0;
	for (int i = 0; i < 157; i++) //faster to look up length in matlab than to look into documantation
		sum += int(str_result[i]) - 48;

	cout << sum << '\n';
	cin >> wait;
}