#include <iostream>
#include <cmath>

using namespace std;

int specific_numeral(int i, int input)
{
	return ((input % int(pow(10, i))) - input % int (pow(10, i - 1)))/(int (pow(10, i - 1)));
}

bool check_for_palindrom(int input)
{	
	bool check = 1;
	int length = 1;
	while (input - (input % int (pow(10, length))) != 0)
		length++;

	for (int i = 0; i < (length - (length % 2))/2; i++)
		if (specific_numeral(i + 1, input) != specific_numeral(length - i, input))
			return 0;

	return 1;
}

void main()
{
	int max_palindrom = 10000;
	int res1 = 0, res2 = 0;
	for(int number1 = 100; number1 < 1000; number1++)
		for(int number2 = number1; number2 < 1000; number2++)
			if (check_for_palindrom(number1 * number2) && (number1*number2 > max_palindrom))
			{
				max_palindrom = number1*number2;
				res1 = number1;
				res2 = number2;
			}

	cout << max_palindrom << '\n' << res1 << '\n' << res2 << '\n';
	cin >> max_palindrom;
}
