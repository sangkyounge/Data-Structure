#include "usefulHeap.h"

void HeapInit(Heap* ph, Prioritycomp* pc)
{
	ph->numOfdata = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)        //힙의 공백 확인
{
	if (ph->numOfdata == 0)
	{
		return TRUE;
	}
	else
		return FALSE;

}

int GetParentIDX(int idx)      //부모 노드의 인덱스 값 반환
{
	return idx / 2;
}

int GetLChildIDX(int idx)      //왼쪽자식 노드의 인덱스 값 반환
{
	return idx * 2;
}

int GetRChildIDX(int idx)      //오른쪽 자식노드의 인덱스 값 반환
{
	return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfdata)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfdata)
		return GetLChildIDX(idx);
	else
	{
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, Hdata data)
{
	int idx = ph->numOfdata + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}

	}
	ph->heapArr[idx] = data;
	ph->numOfdata += 1;

}

Hdata HDelete(Heap* ph)
{
	Hdata retData = ph->heapArr[1];
	Hdata lastElem = ph->heapArr[ph->numOfdata];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfdata -= 1;
	return retData;
}