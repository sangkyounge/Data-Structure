#include<stdio.h>
#include "usefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1;        //오름차순 정렬을 위한 문장
	return n1 - n2;
}

void HeapSort(int arr[], int n, Prioritycomp pc)
{
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	//모든 데이터를 힙에 넣는다.
	for (i = 0; i < n; i++)
	{
		HInsert(&heap, arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = HDelete(&heap);
	}
	
}

int main(void)
{
	int arr[4] = { 3,4,2,1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ",arr[i]);
	return 0;
}