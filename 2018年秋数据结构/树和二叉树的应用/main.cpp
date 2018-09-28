#include <stdio.h>
#include <stdlib.h>

typedef int myType;

typedef struct treeNode
{
    myType element;
    struct treeNode *lchild;
    struct treeNode *rchild;
} Btree;

void createTree(Btree **T)
{
    myType data;
    scanf("%d", &data);

    if (data == -1)
    {
        *T = NULL;
    }
    else
    {
        *T = (Btree *)malloc(sizeof(Btree));
        (*T)->element = data;
        printf("%d", data);
        createTree(&((*T)->lchild));
        printf("%d", data);
        createTree(&((*T)->rchild));
    }
}

void preOrder(Btree *T)
{
    if (T != NULL)
    {
        printf("%d", T->element);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(Btree *T)
{
    if (T != NULL)
    {
        preOrder(T->lchild);
        printf("%d", T->element);
        preOrder(T->rchild);
    }
}

void postOrder(Btree *T)
{
    if (T != NULL)
    {
        preOrder(T->lchild);
        preOrder(T->rchild);
        printf("%d", T->element);
    }
}

int main(int argc, char **argv)
{
    Btree *b;
    createTree(&b);
    postOrder(b);
    return 0;
}
