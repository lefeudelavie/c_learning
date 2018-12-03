
typedef int ElementType;

        #ifndef _HashQuad_H
        #define _HashQuad_H
        
        typedef unsigned int Index;
        typedef Index Position;

        struct HashTbl;
        typedef struct HashTbl *HashTable;

        HashTable InitializeTable( int TableSize );
        void DestoryTable( HashTable H);
        Position Find( ElementType Key, HashTable H);
        void insert( ElementType Key, HashTable H);
        ElementType Retrieve( Position P, HashTable H);
        HashTable Rehash( HashTable H);




        #endif 
