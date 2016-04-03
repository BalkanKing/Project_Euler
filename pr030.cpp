#include <iostream>

using namespace std;

int main()
{
	int f_powers[10];//since we will be using them all the time

	for (int i = 0; i < 10; i++)
		f_powers[i] = i*i*i*i*i;

	int temp = 0;
	int temp_sum = 0;
	int total_sum = 0;
	int total_number = 0; //for interest

	for (int i = 33; i < 354294; i++) //constants from analysis
	{
		temp = i;
		for (int k = 0; k < 6; k++)
		{
			temp_sum += f_powers[temp % 10];
			temp = (temp - (temp % 10))/10;
		}

		if (temp_sum == i)
		{
			total_sum += i;
			total_number++;
		}
		temp_sum = 0;
	}

	cout << total_sum << ' ' << total_number << '\n';
	return 0;
}
