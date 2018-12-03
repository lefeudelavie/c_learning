#include <stdlib.h>
#include "fatal.h"
#include "avltree.h"


    typedef struct AvlNode {
        ElementType Element;
        AvlTree Left;
        AvlTree Right;
        int Height;
    };

    AvlTree 
    MakeEmpty(AvlTree T)
    {
        if ( T != NULL)
        {
            MakeEmpty(T->Left);
            MakeEmpty(T->Right);
            free(T);
        }
        return T;
    }


    Position
    Find(ElementType X, AvlTree T)
    {
        if ( T == NULL)
            Error("Element not found");
            return NULL;
        else if ( X > T->Element)
            return Find( X, T->Right);
        else if ( X < T->Element)
            return Find( X, T->Left);
        else 
            return T;
    }


    Position
    FindMin(AvlTree T)
    {
        if ( T == NULL )
            return NULL
        else if ( T->Left == NULL)
            return T;
        else
            return FindMin(T->Left);
    }    

    Position
    FindMax(AvlTree T)
    {
        if ( T != NULL)
            while ( T !== NULL )
                T = T->Right;
        return T;
    }


    /* incorret solution by me
    AvlTree 
    SingleRotateLeft( AvlTree K2)
    {
        AvlTree K1 = K2->Left;
        K2->Left = K1->Right;
        K1->Right = K2;
        K2->Height -= 1;
        return K1;
    }

    AvlTree
    SingleRotateRight( AvlTree K1)
    {
        AvlTree K2 = K1->right;
        K1->Right = K2->Left;
        K2->Left = K1;
        return K2;
    }
    
    */
    
    int
    Height ( AvlTree T)
    {
        if ( T == NULL)
            return -1;
        return T->Height;
    }
    
    static int
    Max( int Lhs, int Rhs)
    {
        return Lhs > Rhs ? Lhs : Rhs;
    }

    Position 
    SingleRotateWithLeft( AvlTree K2)
    {
        Position K1;

        K1 = K2->Left;
        K2->Left = K1->Right;
        K1->Right = K2;

        K1->Height = Max( Height(K1->Left), Height(K1->Right)) + 1;
        K2->Height = Max( Height(K2->Left), Height(K2->Right)) + 1;
        
        return K1;
    }
    




    Position 
    SingleRotateWithRight( AvlTree K1)
    {
        Position K2;

        K2 = K1->Right;
        K1->Right = K2->Left;
        K2->Left = K1;

        K1->Height = Max( Height(K1->Left), Height(K1->Right)) + 1;
        K2->Height = Max( Height(K2->Left), Height(K2->Right)) + 1;
        
        return K2;
    }


    Position
    DoubleRotateWithLeft( AvlTree K1 ) 
    {
        K1->Left = SingleRotateWithRight(K1->Left);
        return SingleRotateWithLeft(K1);
    }  

    
    Position
    DoubleRotateWithRight( AvlTree K1 ) 
    {
        K1->Right = SingleRotateWithLeft(K1->Right);
        return SingleRotateWithRight(K1);
    }  


    AvlTree
    Insert( ElementType X, AvlTree T)
    {
        if ( T == NULL )
        {
           T = (struct AvlNode*)malloc(sizeof(AvlNode));
           T-Left = T->Right = NULL;
           T->Element = X;
           T->Height = 0;
        }
        else
        {
            if ( X > T->Element)
            {
                T->Right = Insert( X, T->Right);
                if ( T->Right->Height - T->Left->Height == 2 )
                    if ( X > T->Right->Element )
                        SingleRotateWithRight( T );
                    else 
                        DoubleRotateWithRight(T);

            }
            else if ( X < T->Element)
            {
                T->Left = Insert( X, T->Left);
                if ( T->Left->Height - T->Right->Height == 2)
                    if ( X < T->Left->Element)
                       SingleRotateWithLeft(T);
                    else
                       DoubleRotateWithLeft(T); 
            } 
                
                
        }

        T->Height = Max( Height(T->Right), Height(T->Left() ) + 1;
        return T;
    } 


    AvlTree
    Delete( ElementType X, AvlTree T)
    {
    }


    ElementType
    Retrieve( Position P )
    {
        return P->Element;
    }


