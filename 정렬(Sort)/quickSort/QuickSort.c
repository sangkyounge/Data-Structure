#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int p = arr[left];                             //피벗의 위치는 가장 왼쪽
	int low = left + 1;
	int high = right;

	while (low <= high)                            //교차되기 않을 때까지 반복
	{   
		//피벗보다 큰 값을 찾는 과정
		while (p > arr[low])
			low++;                                 //low를 오른쪽으로

		//피벗봐 작은 값을 찾는 과정
		while (p < arr[high])
			high--;                                //high를 왼쪽으로

		if (low <= high)                           //교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);
	}      
	Swap(arr, left, high);                        //피벗과 high가 가리키는 대상 교환
	return high;                                   //옮겨진 피벗의 위치정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int p = partition(arr, left, right);       //둘로 나누기
		QuickSort(arr, left, p - 1);               //왼쪽
 		QuickSort(arr, p + 1, right);              //오른쪽
	}
}

int main()
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	//int arr[3] = { 3,3,3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}