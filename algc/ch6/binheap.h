    typedef int ElementType;

    #ifndef _BinHeap_H
    #define _BinHeaP_H

    struct HeapStruct;
    typedef struct HeapStruct *PriorityQueue;
    
    PriorityQueue Initialize(int MaxElements);
    void Destory(PriorityQueue H);
    void MakeEmpty(PriorityQueue H);
    void Insert(ElementType ,PriorityQueue H);
    ElementType DeleteMin(PriorityQueue H);
    ElementType FindMin(PriorityQueue H);
    int IsEmpty( PriorityQueue H);
    int IsFull( PriorityQueue H);  
    


    #endif
