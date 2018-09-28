#include <stdio.h>
#include <stdlib.h>

#define ok 1
#define true 1
#define false 1
#define err -1
#define overflow -1
#define size 10

typedef int status;
typedef int elem;
typedef int* elemptr;
typedef struct
{
    elemptr base;
    elemptr top;
    int len;
} stack,*stackptr;

status init(stackptr s);

status init(stackptr s)
{
    s->base = (elemptr)malloc(size*sizeof(elem));
    if(!s->base)
        exit(overflow);
    s->top = s->base;
    s->len = 0;
    return ok;
}

status clear(stackptr s)
{
    if(s->top == s->base)
        return ok;
    while(--s->top)
    {
        if(s->top == s->base)
            break;
    }
    s->len = 0;
    return ok;
}

status lenth(stack s)
{
    return (&s)->len;
}

status empty(stack s)
{
    if((&s)->top == (&s)->base || (&s)->len == 0)
        return true;
    return false;
}

status get(stack s,elemptr e)
{
    if(s.len == 0 || s.base == s.top)
        return err;
    (--s.top) == *e;
    return ok;
}

status push(stackptr s,elem e)
{
    if(s->len==size)
        return err;
    *(s->top) = e;
    ++s->top;
    ++s->len;
    return ok;
}

status pop(stackptr s,elemptr e)
{
    if(s->len==0 || s->base == s->top)
        return err;
    *e = *(--s->top);
    --s->len;
    return ok;
}

status traverse(stack s)
{

    printf("base->");
    while(s.len>0 && s.len--)
    {
        printf("%d->",*(s.base++));
    }
    printf("over\n");
}

status destoy(stackptr s)
{
    clear(s);
    free(s);
    printf("destory!\n");
    return ok;
}

void transfer()
{
    stack s;
    elem e;
    init(&s);
    int n = 2;
    int N = 8;
    while(N)
    {
        push(&s,N%n);
        N /= n;
    }
    int len = s.len;
    while(len--)
    {
        pop(&s,&e);
        printf("%d\n",e);
    }


}

int main()
{
    transfer();
    return 0;
}




