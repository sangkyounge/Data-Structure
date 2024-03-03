#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int p = arr[left];                             //�ǹ��� ��ġ�� ���� ����
	int low = left + 1;
	int high = right;

	while (low <= high)                            //�����Ǳ� ���� ������ �ݺ�
	{   
		//�ǹ����� ū ���� ã�� ����
		while (p > arr[low])
			low++;                                 //low�� ����������

		//�ǹ��� ���� ���� ã�� ����
		while (p < arr[high])
			high--;                                //high�� ��������

		if (low <= high)                           //�������� ���� ���¶�� Swap ����
			Swap(arr, low, high);
	}      
	Swap(arr, left, high);                        //�ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;                                   //�Ű��� �ǹ��� ��ġ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int p = partition(arr, left, right);       //�ѷ� ������
		QuickSort(arr, left, p - 1);               //����
 		QuickSort(arr, p + 1, right);              //������
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