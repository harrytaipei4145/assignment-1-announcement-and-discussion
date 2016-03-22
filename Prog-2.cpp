#include<iostream>


using namespace std;




void swap(int* a, int* b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;


}
int mid(int number[],int left, int right)
{
	int mid;
	
	if (right - left >= 2)
	{
		mid = (right + left) / 2;
		if (number[left] > number[mid] && number[mid] > number[right])
			return mid;
		else if (number[right] > number[mid] && number[mid] > number[left])
			return mid;
		else if (number[right] > number[left] && number[left] > number[mid])
			return left;
		else if (number[mid] > number[left] && number[left] > number[right])
			return left;
		else if (number[mid] > number[right] && number[right] > number[left])
			return right;
		else if (number[left] > number[right] && number[right] > number[mid])
			return right;
	}
	else
	{
		return left;
	}
	

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


