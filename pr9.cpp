#include <iostream>

using namespace std;

void main()
{
	for (int i = 1; i < 1000; ++i)
	{
		for (int j = 1; j < (1000 - i)/2; ++j)
		{
			if ((j*j + (1000 - i - j)*(1000 - i - j)) == (i*i))
				cout << j*i*(1000 - i - j) << "\n" << j << "\n" << i << "\n" << (1000 - i - j) << "\n";
		}
	}
	int x;
	cin >> x;
}