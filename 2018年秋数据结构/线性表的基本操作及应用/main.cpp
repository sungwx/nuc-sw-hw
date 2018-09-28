#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREAMENT 10

#define ERROR 0
#define OK 1
#define LIST_INIT_SIZE 10
#define OVERFLOW -1

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L, int i, ElemType e);
Status ListDelete_Sq(SqList &L, int i, ElemType &e);
int LocateElem_Sq(SqList L, ElemType e);
void ShowList_Sq(SqList L);

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length <= L.listsize)
    {
        ElemType *q = &(L.elem[i - 1]);
        ElemType *p;
        for (p = &(L.elem[L.length - 1]); p >= q; --p)
            *(p + 1) = *p;
        *q = e;
        ++L.length;
        return OK;
    }
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    if ((i < 1) || (i > L.length))
        return ERROR;
    ElemType *p = &(L.elem[i - 1]);
    e = *p;
    ElemType *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return OK;
}

int LocateElem_Sq(SqList L, ElemType e)
{
    int i;
    i = 1;
    while (i <= L.length && L.elem[i - 1] != e)
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}

void ShowList_Sq(SqList L)
{
    int i;
    i = L.length + 1;
    printf("线性表为：");
    while (--i)
        printf("%d--", *(L.elem++));
    printf("@\n");
}

int main(int argc, char **argv)
{
    SqList L;
    ElemType e;
    InitList_Sq(L);
    if(ListInsert_Sq(L, 1, 1))
    	printf("插入节点 1 成功！\n");
    if(ListInsert_Sq(L, 2, 2))
    	printf("插入节点 2 成功！\n");
    if(ListInsert_Sq(L, 3, 3))
    	printf("插入节点 3 成功！\n");
    if(ListDelete_Sq(L, 1, e))
    	printf("删除节点 1 成功！\n"); 
    ShowList_Sq(L);
    return 0;
}
