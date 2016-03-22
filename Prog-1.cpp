#include<iostream>


using namespace std;




void swap(int* a, int* b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;


}

int part(int number[], int left, int right)
{
	int x,i;
	int pivot;

	


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
