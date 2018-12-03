#include "tree.h"
#include <stlib.h>
#include "fatal.h"


struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

/*   This implementation is wrong 
SearchTree 
MakeEmpty(SearchTree T)
{
    if ( T == NULL)
        return T;
    if ( T->Left != NULL)
        return MakeEmpty( T->Left );
    else if ( T->Right != NULL)
        return MakeEmpty( T->Right );
}
*/

SearchTree
MakeEmpty(Search T)
{
    if ( T == NULL )
        return NULL;
    else {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }

}



Position
Find(SearchTree T, ElementType X)
{
    if ( T == NULL)
        return T;
    if ( X < T->Element)
        return Find( T->Left, X);
    else if ( X > T->Element)
        return Find( T->Right, X);
    else
        return T;
}


Position
FindMin(SearchTree T )
{
    if ( T == NULL)
        return T;
    if ( T->Left != NULL) 
        return FindMin(T->Left);
    else if ( T->Left == NULL)
        return T;
}


/* Not so correct 
Position
FindMax( SearchTree T)
{ 
    while ( T->Right != NULL)
        T = T->Right;
    return T;
}
*/


Position
FindMax( SearchTree T)
{
    if ( T != NULL);
        while ( T->Right != NULL)
            T = T->Right;
    return T;    
}




SearchTree
Insert( SearchTree T, ElementType X)
{
    if ( T == NULL)
        T = (SearchTree)malloc(sizeof(TreeNode));
        T->Element = X;
        T->Left = NULL;
        T->Right = NULL;
        return T;
    else
         if ( X > T->Element )
            return Insert( T->Right , X);
    else 
        if ( X < T->Element)
            return Insert( T->Left, X);
    else
        return T;
}




/* following code is not correct 
SearchTree Delete( ElementType X, SearchTree T)
{
    Position TmpCell;
    if ( T == NULL)
        Error("Empty Tree,quit");
    else if ( X > T->Right )
        T = Delete( X, T->Right);
    else if ( X < T->Left )
        T = Delete( X, T->Left );
    else 
    if ( T->Right && T->Left )
    {
        TmpCell = T;
        T = FindMin( T->Right);
        
        free(TmpCell);
    }
    else 
    {
        TmpCell = T;
        if ( T->Left == NULL)
            T = T->Left;
        else if ( T->Right == NULL )
            T = T->Right;
        free(TmpCell);
    }
    
} */


SearchTree 
Delete( ElementType X, SearchTree T)
{
    Position TmpCell;
    if ( T == NULL )
        Error("Cannot find the element");
    if ( X > T->Element)
        T->Right = Delete(X, T->Right);
    else if ( X < T->Element)
        T->Left = Delete(X, T->Left);
    else 
    if ( T->Right && T->Left )
    {
       TmpCell = FindMin( T->Right); 
       T->Element = TmpCell->Element;
       T->Right = Delete( TmpCell->Element, T->Right);
    }
    else 
    {
        TmpCell = T;
        if ( T->Left == NULL)
            T = T->Right;
        else if ( T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;    
}
