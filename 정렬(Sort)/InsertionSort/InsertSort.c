#include<stdio.h>

void InsertSort(int arr[], int n)
{
	int i, j;
	int Data;

	for (i = 1; i < n; i++)
	{
		Data = arr[i];   //3               //정렬대상을 Data에 저장

		for (j = i - 1; j >= 0; j--)       //5 3 2 4 1
		{
			if (arr[j] > Data)
				arr[j + 1] = arr[j];
			else
				break;                     //삽입 위치 찾음!
		}
		arr[j + 1] = Data;				   //0 1 2 3 4
	}
}

int main()
{
	int arr[5] = { 5,3,2,4,1 };
	int i;

	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}