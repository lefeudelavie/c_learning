    #include <stdio.h>
    #include "fatal.h"
    #include "hashsep.h"

    #define MinTableSize  (10)

    struct ListNode
    {
        ElementType Element;
        Position Next;
    };

    typedef Position List;

    struct HashTbl
    {
        int TableSize;
        List *ThisList;
    };

    static int
    NextPrime( int N)
    {
        int i;

        if ( N % 2 == 0)
            N ++;
        for ( ; ; N += 2)
        {
            for ( i = 3; i*i < N; i += 2)
                if ( N % i == 0)
                    goto ContOuter;
            return N;
           ContOuter: ;
        }
    };

    Index
    Hash( ElementType Key, int TableSize)
    {
        return Key % TableSize;
    }

    
    HashTable
    InitializeTable( int TableSize )
    {
        HashTable H;
        int i; 

        if ( TableSize < MinTableSize )
        {
            Error("The table size is too small");
            return NULL;
        }

        H = (HashTable)malloc(sizeof(HashTbl));
        if ( H == NULL)
            FatalError("Out of space");

        H->TableSize = NextPrime(TableSize);

        H->ThisList = (List)malloc(sizeof(List) * H->TableSize);

        for ( i = 0; i < H->TableSize ; i++ )
        {
            H->ThisList[ i ] = (Position)malloc(sizeof(struct ListNode));
            if ( H->ThisList[ i ] == NULL)
                FatalError("Out of Space")
            else:
                H->ThisList[ i ]->Next = NULL;
        }

        return H;
        

    }

    Position 
    Find( ElementType Key, HashTable H)
    {
        List L;
        Position P;
        
        L = HashTable->ThisList[ Hash( Key , HashTable->TableSize ) ];
        P = L->Next;
        if ( P !== NULL && Key !== P->Element)
        {
            P = P->Next;
        }
        
        return P; 
    }




    void
    Insert( ElementType Key, HashTable H)
    {
        Position P, NewCell;
        List L;
        P  = Find( Key, H);
        

        if ( P == NULL)
        {
            NewCell = (Postion)malloc(sizeof(struct ListNode));
            if ( NewCell == NULL)
                FatalError("Out of Space");
            L = HashTable[ Hash( Key, HashTable->TableSize)];
            NewCell->Next = L->Next;
            L->Next = NewCell;
            NewCell->Element = Key;    
        }
    };//End of Insert


    ElementType
    Retrieve( Postion P)
    {
        return P->Element;
    }


    void 
    DestoryTable( HashTable H )
    {
        int i;

        for ( i = 0; i < H->TableSize ; i++ )
        {
            Position P = H->Thislist[i];
            Position Tmp;
            while ( P != NULL)
            {
                Tmp = P->Next;
                free(P);
                P = Tmp; 
            } 
        }

        free( H->ThisList);
        free( H );
    }
