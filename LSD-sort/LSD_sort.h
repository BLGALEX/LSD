#ifndef LSD_sort
#define LSD_sort

int Getdigit(int number, int digit)
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
	int* buffer = new int[length];
	int indexes_of_numbers[10] = { 0 };
	int max=abs(first[0]);
	int digits=0;
	for (int i = 1; i < length; i++)
		if (max < abs(first[i]))
			max = abs(first[i]);
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
		for(int j=0; j<length; j++)
		{ 
			indexes_of_numbers[Getdigit(first[j], i)]++;
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
			buffer[indexes_of_numbers[Getdigit(first[j], i)]] = first[j];
			indexes_of_numbers[Getdigit(first[j], i)]++;	
		}
		for (int j = 0; j < length; j++)
			first[j] = buffer[j];
	}
}

#endif

