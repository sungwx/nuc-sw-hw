- 栈(stack) 定义
- 抽象数据类型以及三个属性-顶部、基址、长度
- 基础操作  
    初始化  
    获取元素  
    入栈  
    出栈  
- 应用
    数制转换  
    表达式求值  

<!-- more -->

## 定义

本节课从栈的定义开始讲  

> 栈是一个只能在表尾进行插入和删除的线性表。

![栈](https://r.photo.store.qq.com/psb?/V146EW4F0E6ZOW/lLYkwM1ilt9u4.X4*5PcqMTvocWpVrsCiBAkznR3VZU!/r/dFkAAAAAAAAA)

## 抽象数据类型

那我们首先来定义这个栈的抽象数据类型，但其实我们知道他就跟线性表一样，只是基础操作不同。下面是栈的ADT  

![栈](https://r.photo.store.qq.com/psb?/V146EW4F0E6ZOW/Nzb4bZZfv3hN3.LWrDwjJkMvAk2SgRAjMRPai15ZzUg!/r/dDUBAAAAAAAA)

## 顶部、基址、长度

我们定义栈的时候，我们一般会给三个属性，那第一个属性的就是基址，第二个属性是top对应的地址，第三个属性是长度，我们会利用这三个属性进行基础操作，下面我会用代码给大家实现这四种基础操作。  

### 定义

首先，先在程序中定义stack 

```c
typedef struct
{
    elemptr base;
    elemptr top;
    int len;
}stack,*stackptr;
```

下面介绍几个基本操作  

### 初始化

```c
status init(stackptr s)
{
    s->base = (elemptr)malloc(size*sizeof(elem));
    if(!s->base) exit(overflow);
    s->top = s->base;
    s->len = 0;
    return ok;
}
```

### 清空

```c
status clear(stackptr s)
{
    if(s->top == s->base) return ok;
    while(--s->top)
    {
        if(s->top == s->base) break;
    }
    s->len = 0;
    return ok;
}
```

### 取长度

```c
status lenth(stack s)
{
    return (&s)->len;
}
```

### 是否为空

```c
status empty(stack s)
{
    if((&s)->top == (&s)->base || (&s)->len == 0) return true;
    return false;
}
```

### 取栈顶

```c
status get(stack s,elemptr e)
{
    if(s.len == 0 || s.base == s.top) return err;
    (--s.top) == *e;
    return ok;
}
```

### 压栈

```c
status push(stackptr s,elem e)
{
    if(s->len==size) return err;
    *(s->top) = e;
    ++s->top;
    ++s->len;
    return ok;
}
```

### 出栈

```c
status pop(stackptr s,elemptr e)
{
    if(s->len==0 || s->base == s->top) return err;
    *e = *(--s->top);
    --s->len;
    return ok;
}
```

## 应用

那栈其实是基于线性表的，它的原理并不难，难点在于它的应用上，我们如何去利用栈，这个这种数据结构去解决实际问题，我们不妨先来看看他已经解决过哪些实际问题，那第一个实际问题呢，就是数制转换，第二个实际问题是表达式求值。

### 数制转换

对于数制转换，我们拿十进制转换八进制为例，那我们实际分析一下，每次将数字除以8，将余数取出来，当我们取出来最后一位，也就是将被除数算得为零的时候，我们再将结果逆序输出，这样我们就得到了最终的八进制，那我们其实注意到两点，第一点就是转换的结果各位产生顺序与输出顺序正好相反，所以说，遇到这种特征的时候，我们可以利用栈来解决。


```c
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
```

### 表达式求值

第二个案例的话是表达式的计算，我们如何去计算表达式，波兰一个科学家，杨武卡谢维奇，他最先引入的数学表达方程式，他用后缀表达形式，利用堆栈结构，减少计算机内存的访问，我们在这里只做简单实现，并不深入研究。
  
**下次更新！**


### 写在后面

在考研或者其他题目中，更多的会出现，给你一系列数字，你来判断这个是否能由栈结构来推出，对于一般的题目，我关通过观察，看出来一些规律，如果说在式子中出现了大小中，这种结构，那他是不能推出来的，我这里说一下，比如3入栈，那么21必入栈，那我们谈出来的顺序，即使321，而不会出现312的情况，我们家312换成大小中，那其实我们这种情况是不可能出现的，所以说，大小中必错。


