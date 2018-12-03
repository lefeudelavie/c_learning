typedef int ElementType;

    typedef unsigned int Index;

    #ifndef _HashSep_H
    #define _HashSep_H

    struct ListNode;
    typedef struct ListNode *Position;
    struct HashTbl;
    typedef struct HashTbl *HashTable;

    HashTable InitializeTable( int TableSize );
    void DestoryTable( HashTable H );
    Position Find( ElementType Key, HashTable H);
    void insert( ElementType Key, HashTable H);
    ElementType Retrieve( Position P);
    

    #endif
