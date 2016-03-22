#include<iostream>


using namespace std;




void swap(int* a, int* b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;


}

int choose(int number[],int i)
{
	
		
		if (number[i] > number[i+1] && number[i+1] > number[i+2])
			return i+1;
		else if (number[i+2] > number[i+1] && number[i+1] > number[i])
			return i+1;
		else if (number[i+2] > number[i] && number[i] > number[i+1])
			return i;
		else if (number[i+1] > number[i] && number[i] > number[i+2])
			return i;
		else if (number[i+1] > number[i+2] && number[i+2] > number[i])
			return i+2;
		else if (number[i] > number[i+2] && number[i+2] > number[i+1])
			return i+2;

	
}
int mid(int number[], int left, int right)
{
	int mid;
	int number_temp[100];
	int i = 0;
	int j = left;
	int x;
	int k = 0;
	while (j <= right)
	{
		number_temp[i] = number[j];
		i++;
		j = j + 2;
	}
	

	while (i > 2)
	{
		int temp = 0;
		 x = 0;
		while (temp <= i)
		{
			if (i - temp < 2)
				break;
			int z = choose(number_temp, temp);
			number_temp[x] = number_temp[z];
			temp = temp + 3;
			x++;
		}
		i = (i + 1) / 3;
	}

	while (true)
	{
		 
		if (number[k] == number_temp[0])
		{
			break;
		}
		else
		{
			k++;
			continue;
		}

	}

	return k;

}
int part(int number[], int left, int right)
{
	int x,i;
	int pivot;

	pivot = mid(number, left, right);
	
	swap(&number[pivot], &number[right]);

	x = number[right];
	i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{
		if (number[j] <= x)
		{
			i = i + 1;
			swap(&number[i], &number[j]);
		}		
	}
	swap(&number[i+1], &number[right]);
	return i + 1;
}
void quick_sort(int number[],int left,int right)
{
	int q;
	
	if (right > left)
	{
		q = part(number, left, right);
		quick_sort(number, left, q - 1);
		quick_sort(number, q+1, right);
	}
	
	
}



int main()
{
	int count = 0;
	int number[10000];
	while (!cin.fail())
	{
		cin >> number[count];
		count++;
	}
	count = count - 2;
	quick_sort(number, 0, count);

	for (int i = 0; i <= count-1; i++)
	{
		cout << number[i] << " ";
	}
	cout << number[count];
	system("pause");
}

