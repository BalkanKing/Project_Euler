//MinGw is not friendly with VS so another pretty useless source file
#include <iostream>
#include "gmp.h"

using namespace std;

void main()
{
	int wait;

	mpz_t fib_1;
	mpz_init(fib_1);
	mpz_set_str(fib_1, "1", 10);

	mpz_t fib_2;
	mpz_init(fib_2);
	mpz_set_str(fib_2, "1", 10);

	mpz_t fib_n;
	mpz_init(fib_n);
	mpz_set_str(fib_n, "1", 10);

	int index;
	
	for (index = 2; mpz_sizeinbase (fib_n, 10) < 1000; index++)
	{
		mpz_add(fib_n, fib_1, fib_2);
		mpz_set(fib_1, fib_2);
		mpz_set(fib_2, fib_n);
	}

	cout << (index + 1) << '\n'; //No idea - peculiar beahviour of mpz_sizeinbase

	cin >> wait;
}