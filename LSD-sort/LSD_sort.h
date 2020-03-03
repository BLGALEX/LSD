#ifndef LSD_sort
#define LSD_sort

int Getdigit(unsigned int number, int digit)
{
	for (digit; digit > 1; digit--)
	{
		number /= 10;
	}
	number %= 10;
	return number;
}

void LSDSort(int* first, int* last)
{
	int length = (abs((char)first - (char)last))/4;
	length++;
	unsigned int* buffer = new unsigned int[length];
	unsigned int* first_u = new unsigned int[length];
	for (int i = 0; i < length; i++)
		first_u[i] = first[i] - std::numeric_limits<int>::min();
	int indexes_of_numbers[10] = { 0 };
	unsigned int max=(first_u[0]);
	int digits=0;
	for (int i = 1; i < length; i++)
		if (max < (first_u[i]))
			max = (first_u[i]);
	while(max!=0)
	{
		digits++;
		max /= 10;
	}
	for (int i = 1; i <= digits; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			indexes_of_numbers[j] = 0;
		}
		for (int j = 0; j < length; j++)
		{
			indexes_of_numbers[Getdigit(first_u[j], i)]++;
		}
		int count = 0;
		for (int j = 0, temp; j < 10; j++)
		{
			temp = indexes_of_numbers[j];
			indexes_of_numbers[j] = count;
			count += temp;
		}
		for (int j = 0; j < length; j++)
		{
			buffer[indexes_of_numbers[Getdigit(first_u[j], i)]] = first_u[j];
			indexes_of_numbers[Getdigit(first_u[j], i)]++;
		}
		for (int j = 0; j < length; j++)
			first_u[j] = buffer[j];
	}
	for (int j = 0; j < length; j++)
		first[j] =( first_u[j] + std::numeric_limits<int>::min());
}

#endif

