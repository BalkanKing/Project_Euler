//I think that it should be working faster but result is already present so no practical reasons for reworking the code

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

bool is_in_vector(vector<int> mas, int value) //essentially binary search; not recursive because of usage of vector
{
	int left = 0;
	int right = mas.size() - 1;
	int current = mas.size()/2 - 1;

	while (right - left > 1)
	{
		if (mas[current] == value)
			//return current;
			return 1;
		else
			if (mas[current] < value)
			{
				left = current;
				current += (right - left + 1)/2;
			}
			else
			{
				right = current;
				current -= (right - left + 1)/2;
			}
	}

	if ((mas[left] == value) || (mas[right] == value))
		return 1;
/*
	if (mas[left] == value)
		return left;
	else
		if(mas[right] == value)
			return right;
*/
	return 0;
}

int cycle_right(int value) //cycle left is much worse: consider 101
{
	string str_value = static_cast<ostringstream*>( &(ostringstream() << value) )->str();

	str_value.insert(0, 1, str_value[str_value.size() - 1]); //should work without 1 but doesn't
	str_value.erase(str_value.size() - 1, 1);

	int result;
	istringstream(str_value) >> result;

	return result;
}

int length(int value)
{
	int result = 1;
	int p_ten = 10;
	while((value % p_ten) != value)
	{
		result++;
		p_ten *= 10;
	}

	return result;
}

int main()
{
	vector<int> primes = find_primes(1000000); //can cut any number with even digit in it but maybe it's not necessary

	int total = 0;

	int temp;

	for (int i = 0; i < primes.size(); i++)
	{
		temp = primes[i];
		total ++;
		for (int k = 0; k < length(primes[i]) - 1; k++)
		{
			temp = cycle_right(temp);
			if (!(temp % 2)  || !is_in_vector(primes, temp))
			{
				total--;
				break;
			}
			//primes[is_in_vector(primes, temp)] = 2;
			cout << temp << endl;
		}
	}

	cout << total << endl; //learned about endl

	return 0;
}
