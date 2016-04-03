#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> find_primes(int limit)	//obvious sieve
{
	vector<int> result;

	int* index = new int[limit];
	for (int i = 0; i < limit; i++)
		index[i] = 0;

	for (int k = 2; k < limit + 1; 1)
	{
		for (int j = 2; k * j < limit + 1; j++)
			index[k * j - 1] = 1;

		k++;

		while ((index[k - 1] != 0) && (k < limit + 1))
			k++;
	}

	for (int i = 1; i < limit; i++)
		if (index[i] == 0)
			result.push_back(i + 1);

	return result;
}

bool check_primality(int p) //can be done more efficiently via using sieve but that way is more practical here
{
	for (int i = 2; i <= sqrt(p); i++)
		if ((p % i) == 0)
			return 0;
	return 1;
}

int check_polynomial(int a, int b) //returns amount of consecutive primes
{
	int i = 0;
	while (check_primality((i*i) + a*i + b) == 1)
		i++;
	return i;
}

int main() //Visual Studio is much more lenient in terms of what it allows main to return
{
	vector<int> primes;

	primes = find_primes(1000);

	//Now simple analysis shows that b must be prime(more than 41 because of problem statement) and |a| < 2*sqrt(b) which throws out a lot of options

	int max_seq = 40; //Euler polynomial
	int max_a = 1;
	int max_b = 41;

	int k = 0;
	while (primes[k] <= 41)
		k++;

	int j = 0;

	for (int i = k; i < primes.size(); i++)
	{
		j = 0;
		while ((1 + j * 2) < 2 * sqrt(primes[i]))
		{
			if (check_polynomial(1 + j * 2, primes[i]) > max_seq)
			{
				max_seq = check_polynomial(1 + j * 2, primes[i]);
				max_a = 1 + j * 2;
				max_b = primes[i];
			}
			j++;
		}

		j = 0;
		while ((-1 + j * 2) > (-2) * sqrt(primes[i]))
		{
			if (check_polynomial((-1) + j * 2, primes[i]) > max_seq)
			{
				max_seq = check_polynomial((-1) + j * 2, primes[i]);
				max_a = (-1) + j * 2;
				max_b = primes[i];
			}
			j--;
		}
	}

	cout << max_seq << ' ' << max_a << ' ' << max_b << '\n' << max_a * max_b << '\n';
	return 0;
}
