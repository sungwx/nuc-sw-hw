/* 
抽象数据类型的表示和实现

一、实验目的

1.复习巩固C语言的结构体、指针、函数、动态分配内存等知识点。

2.掌握抽象数据类型的定义、表示和实现，为后续实验打好基础。

二、实验内容

基本要求：

设计实现抽象数据类型“三元组”。每个三元组由任意三个实数的序列构成，基本操作包括：创建一个三元组，取三元组的任意一个分量，置三元组的任意一个分量，求三元组的最大分量，求三元组的最小分量，显示三元组，销毁三元组等。

选作内容：

实现两个三元组的对应分量相加或相减，给三元组的各分量同乘一个比例因子等操作。

三、实验步骤

1、写出“三元组 （Triplet）”抽象数据类型的定义，即数据对象、数据关系、基本操作

2、练习抽象数据类型的表示和实现。

方法：用指针描述“三元组”，要求：动态分配内存。

3、完成所有基本操作的C语言实现与调用，并写测试程序。
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef float ElemType;
typedef struct
{
	ElemType e[3];
}Triplet;

Status initTriplet(Triplet &T,ElemType v0,ElemType v1,ElemType v2); //构造三元组T，元素e1，e2和e3分别被赋予参数v1,v2,v3的值
Status destroyTriplet(Triplet &T); //销毁三元组T
Status getElem(Triplet T,int i,ElemType &e); //用e返回三元组T的第i个元素
Status putElem(Triplet &T,int i,ElemType e); // 用e值取代三元组T的第i个元素
Status isAscending(Triplet T); //如果三元组T的三个元素按升序排列，则返回TRUE；否则返回FALSE
Status isDescending(Triplet T); //如果三元组T的三个元素按降序排列，则返回TRUE，否则返回FALSE
ElemType getMax(Triplet T,ElemType &e); //用e返回T的3个元素中的最大值
ElemType getMin(Triplet T,ElemType &e); //用e返回T的3个元素中的最小值

Status initTriplet(Triplet &T,ElemType v0,ElemType v1,ElemType v2){
	T.e[0]=v0;
	T.e[1]=v1;
	T.e[2]=v2;
	return OK;
}

Status destroyTriplet(Triplet &T){
	return OK;
}

Status getElem(Triplet T,int i,ElemType &e){
	if(i<1||i>3)
	return ERROR;
	else e=T.e[i-1];
	return OK;
}

Status putElem(Triplet &T,int i,ElemType e){
	if(i<1||i>3)
		return ERROR;
	else 
		T.e[i-1]=e;
	return OK;
}

Status isAscending(Triplet T){
	return (T.e[0]<=T.e[1]) && (T.e[1]<=T.e[2]);
} 

Status isDescending(Triplet T){
	return (T.e[0]>=T.e[1]) && (T.e[1]>=T.e[2]);
} 

ElemType getMax(Triplet T,ElemType &e){
	if(T.e[0]>T.e[1])
		e=T.e[0];
   	else
		e=T.e[1];
    if(T.e[2]>e)
       e=T.e[2];
    return e;
} 

ElemType getMin(Triplet T,ElemType &e){
	if(T.e[0]<T.e[1])
		e=T.e[0];
   	else
		e=T.e[1];
    if(T.e[2]<e)
       e=T.e[2];
    return e;
} 

int main(int argc, char** argv){
	Triplet T;
	Status flag;
	ElemType v0,v1,v2,e;
	printf("请输入三元组的三个值v0,v1,v2:\n");
	scanf("%f,%f,%f",&v0,&v1,&v2);
	flag=initTriplet(T,v0,v1,v2);
	printf("调用初始化函数后，flag=%d,T的三个值为%4.2f,%4.2f,%4.2f\n",flag,T.e[0],T.e[1],T.e[2]);
	if(isAscending(T))	printf("该三元组元素为升序\n");
	if(isDescending(T))	printf("该三元组元素为降序\n"); 
	printf("该三元组中的最大值为：%4.2f,最小值为：%4.2f",getMax(T,e),getMin(T,e));
	return OK;
}
