#include<stdio.h>

void SelSort(int arr[], int n)
{
	int maxIdx;
	int temp;
	int j;
	for (int i = 0; i < n - 1; i++)
	{
		maxIdx = i;
		for (j = i + 1; j < n; j++) //�ּڰ� Ž��
		{
			if (arr[j] < arr[maxIdx])              //3 4 2 1
				maxIdx = j;                        //3
		}
		//��ȯ ����
		temp = arr[i];
		arr[i] = arr[maxIdx];                      //1 4 2 3
		arr[maxIdx] = temp;
	}
}

int main(void)
{
	int arr[4] = { 3,4,2,1 };
	int i;
	SelSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}