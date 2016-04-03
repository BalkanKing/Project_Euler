#include <iostream>
#include <vector>

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

const vector<int> primes = find_primes(100); //needed primes

//Here we represent a number in terms of factors(up to 100 since our number are < 100) and their powers
class f_number{
public:
	vector<int> powers_of_factors;

	f_number()
	{
		powers_of_factors = factorise(1);
	}

	bool operator !=(const f_number& rhs)//just suppose that their lengths are equal
	{
		for (int i = 0; i < this->powers_of_factors.size(); i++)
			if (this->powers_of_factors[i] != rhs.powers_of_factors[i])
				return 1;
		return 0;
	}

	bool operator ==(const f_number& rhs)//just suppose that their lengths are equal
		{
			for (int i = 0; i < this->powers_of_factors.size(); i++)
				if (this->powers_of_factors[i] != rhs.powers_of_factors[i])
					return 0;
			return 1;
		}

	void operator =(const f_number& rhs)//just suppose that their lengths are equal
	{
		for (int i = 0; i < powers_of_factors.size(); i++)
			this->powers_of_factors[i] = rhs.powers_of_factors[i];
	}

	static vector<int> factorise(int number) //numbers are small so I didn't bother to look up any more efficient ways to factorise numbers
	{
		vector<int> result = primes;
		for (int i = 0; i < primes.size(); i++)
		{
			result[i] = 0;
			while (number % primes[i] == 0)
			{
				number = number/primes[i];
				result[i]++;
			}
			if (number == 1)
			{
				for (int k = i + 1; k < primes.size(); k++)
					result[k] = 0;
				return result;
			}
		}
		return result;
	}

	int power_of_factor(int p) //input prime to learn what's it's contribution in a number
	{
		for (int i = 0; i < powers_of_factors.size(); i++)
			if (primes[i] == p)
				return powers_of_factors[i];
		return -1; //not for a consumer usage but easy to implement exception handling
	}

	f_number pow(int power) //only natural powers obv, also it's better to not change the original value I think
	{
		f_number result = *this;
		for (int i = 0; i < result.powers_of_factors.size(); i++)
			result.powers_of_factors[i] *= power;
		return result;
	}

	void print()
	{
		for (int i = 0; i < powers_of_factors.size(); i++)
			cout << powers_of_factors[i] << ' ';
		cout << '\n';
	}
};

int main()
{
	const int TASK_SIZE = 100; //turned out to be useful in debugging

	f_number one;//functionally  a constant
	for (int i = 0; i < one.powers_of_factors.size(); i++)
		one.powers_of_factors[i] = 0;

	f_number  mas[TASK_SIZE + 1]; //2 extra members, I know

	for (int i = 2; i < TASK_SIZE + 1; i++)
		mas[i].powers_of_factors = f_number::factorise(i);

	f_number powers[TASK_SIZE + 1][TASK_SIZE + 1]; //here it's around 400 (396) unused members, but i can live with this knowledge

	for (int i = 2; i < TASK_SIZE + 1; i++)
		for (int j = 2; j < TASK_SIZE + 1; j++)
			powers[i][j] = mas[i].pow(j);

	//now to the fun part of brute methods
	for (int i = 2; i < TASK_SIZE + 1; i++)
		for (int j = 2; j < TASK_SIZE + 1; j++)
		{
			if (powers[i][j] != one)
				for (int s = 2; s < TASK_SIZE + 1; s++)
					for (int v = 2; v < TASK_SIZE + 1; v++)
						if ((i != s) && (powers[i][j] == powers[s][v]))
							powers[s][v] = one;
		}

	int total = 0;

	for (int i = 2; i < TASK_SIZE + 1; i++)
			for (int j = 2; j < TASK_SIZE + 1; j++)
				if (powers[i][j] != one)
					total++;

	cout << total << '\n';
	return 0;
}
