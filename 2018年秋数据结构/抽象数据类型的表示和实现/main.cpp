/* 
�����������͵ı�ʾ��ʵ��

һ��ʵ��Ŀ��

1.��ϰ����C���ԵĽṹ�塢ָ�롢��������̬�����ڴ��֪ʶ�㡣

2.���ճ����������͵Ķ��塢��ʾ��ʵ�֣�Ϊ����ʵ���û�����

����ʵ������

����Ҫ��

���ʵ�ֳ����������͡���Ԫ�顱��ÿ����Ԫ������������ʵ�������й��ɣ�������������������һ����Ԫ�飬ȡ��Ԫ�������һ������������Ԫ�������һ������������Ԫ���������������Ԫ�����С��������ʾ��Ԫ�飬������Ԫ��ȡ�

ѡ�����ݣ�

ʵ��������Ԫ��Ķ�Ӧ������ӻ����������Ԫ��ĸ�����ͬ��һ���������ӵȲ�����

����ʵ�鲽��

1��д������Ԫ�� ��Triplet���������������͵Ķ��壬�����ݶ������ݹ�ϵ����������

2����ϰ�����������͵ı�ʾ��ʵ�֡�

��������ָ����������Ԫ�顱��Ҫ�󣺶�̬�����ڴ档

3��������л���������C����ʵ������ã���д���Գ���
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

Status initTriplet(Triplet &T,ElemType v0,ElemType v1,ElemType v2); //������Ԫ��T��Ԫ��e1��e2��e3�ֱ𱻸������v1,v2,v3��ֵ
Status destroyTriplet(Triplet &T); //������Ԫ��T
Status getElem(Triplet T,int i,ElemType &e); //��e������Ԫ��T�ĵ�i��Ԫ��
Status putElem(Triplet &T,int i,ElemType e); // ��eֵȡ����Ԫ��T�ĵ�i��Ԫ��
Status isAscending(Triplet T); //�����Ԫ��T������Ԫ�ذ��������У��򷵻�TRUE�����򷵻�FALSE
Status isDescending(Triplet T); //�����Ԫ��T������Ԫ�ذ��������У��򷵻�TRUE�����򷵻�FALSE
ElemType getMax(Triplet T,ElemType &e); //��e����T��3��Ԫ���е����ֵ
ElemType getMin(Triplet T,ElemType &e); //��e����T��3��Ԫ���е���Сֵ

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
	printf("��������Ԫ�������ֵv0,v1,v2:\n");
	scanf("%f,%f,%f",&v0,&v1,&v2);
	flag=initTriplet(T,v0,v1,v2);
	printf("���ó�ʼ��������flag=%d,T������ֵΪ%4.2f,%4.2f,%4.2f\n",flag,T.e[0],T.e[1],T.e[2]);
	if(isAscending(T))	printf("����Ԫ��Ԫ��Ϊ����\n");
	if(isDescending(T))	printf("����Ԫ��Ԫ��Ϊ����\n"); 
	printf("����Ԫ���е����ֵΪ��%4.2f,��СֵΪ��%4.2f",getMax(T,e),getMin(T,e));
	return OK;
}
