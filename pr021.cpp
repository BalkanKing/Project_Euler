//Sleep is precious, brutality ensues, moreover 10000 is laughably small

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
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
*/

int divisor_sum(int number)
{
	int result = 0;
	for (int i = 2; i <= number / 2; i++)
		if (number % i == 0)
			result += i;

	result++;
	return result;
}

void main()
{
	int wait;

	divisor_sum(220);

	int div_sum[10000];
	for (int j = 0; j < 10000; j++)
		div_sum[j] = divisor_sum(j + 1);

	int sum = 0;

	for (int i = 1; i < 10000; i++)
		if ((div_sum[i] < 10000) && ((i + 1) == div_sum[div_sum[i] - 1]) && ((i + 1) != div_sum[i]))
			sum += (i + 1);

	cout << sum << '\n';
	cin >> wait;
}