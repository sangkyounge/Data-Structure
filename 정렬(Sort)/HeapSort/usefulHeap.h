#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char Hdata;
typedef int Prioritycomp(Hdata d1, Hdata d2); //우선순위 비교

typedef struct _heap
{
	Prioritycomp* comp;
	int numOfdata;
	Hdata heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph, Prioritycomp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, Hdata data);
Hdata HDelete(Heap* ph);

#endif;