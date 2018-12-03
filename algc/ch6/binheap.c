#include "binheap.h"
#include "fatal.h"
#include <stdio.h>

#define MinPQSize (10)
#define MinData (-32767)

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
}


PriorityQueue
Initialize(int MaxElements)
{
    PriorityQueue H;
    if ( MaxElements < MinPQSize )
        Error("Priority Queue size is too small");

    H = (PriorityQueue) malloc( sizeof( struct HeapStruct) );
    if ( H == NULL)
        FatalError(" Out of space!!!");

    H->Elements = (ElementType*)malloc( (MaxElements + 1) * sizeof(ElementType))

    if ( H->Elements == NULL)
        FataError( "Out of Space !!!")

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}


void
Insert(ElementType X, PriorityQueue H)
{
    int i;

    if ( IsFull( H ) )
    {
        Error("Priority queue is full");
        return;
    }

    for ( i = ++H->Size; H->Elements[ i/2 ] > X; i /=2 )
       H->Elements[i] = H->Elements[i/2]; 

    H->Elements[i] = X;
}


ElementType
DeleteMin(PriorityQueue H)
{
    int i, child;
    int MinElement, LastElement;

    MinElement = H->Element[1];
    LastElement = H->Element[H->size -1 ];

    if ( IsEmpty( H) )
    {
        Error("Priority queue is empty");
        return;
    }

    for ( i = 1; i*2 < H->size ; i = child) 
    {
        child = i*2;
        if ( H->Element[child + 1] < H->Element[child] )
            child += 1;

        if ( LastElement > H->[i])
        {
            H->Element[i] = H->Element[child]; 
        }
        else
        {
            break;
        }
    }

    H->Element[i] = LastElement;
    return MinElement;
}


