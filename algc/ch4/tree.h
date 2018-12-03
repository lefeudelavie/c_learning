typedef int ElementType;

/*START declration */

#ifdef _Tree_H
#define _Tree_H
struct TreeNode;
typedef TreeNode *SearchTree;
typedef TreeNode *Position;

Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /* _Tree_H */
