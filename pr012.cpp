#include <iostream>

using namespace std;

int factors(long long n)
{
	int i = 0;
	for (int j = 1; j < n; ++j)
		if ((n % j) == 0)
			++i;
	return i + 1;
}

void main()
{
	long long test;
	int k;
	cin >> k;
	long long n = 12370 + k;
	long long tri = 1;
	while (factors(tri) < 501)
	{
		n = n + 4;
		tri = n*(n + 1)/2;
		test = factors(tri);
	}
	cout << n;
	cin >> n;
}
