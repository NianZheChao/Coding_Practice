#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

typedef int elemtype;
typedef struct{
	elemtype data[MAXSIZE];
	int len;
}sqlist;
//线性表的类型定义

void initlist(sqlist *L){
	L->len = 0;
}
//初始化空线性表

void print(sqlist *L){
	int i;
	for(i = 0;i < L->len;i++)
		if (i<L->len)
			printf("%d",L->data[i]);
		else
			return;
}
//输出线性表

int take(sqlist *L,int i){
	return L->data[i];
}
//取出表中第i个元素的键值 

void delePos(sqlist *L,int i){
	int j;
	if((i > L->len)||(i < 1)){
		printf("位置不在表内"); 
		return;
	}
	else{
		//y = L->data[i-1];
		for(j = i;j < L->len;j++)
			L->data[j-1] = L->data[j];
		L->len--;
		return;
	}
}
//从表中删除指定位置的元素


void cut(sqlist *L,int x,int y){
	int i=0;
	while(i++ < L->len){
		if(L->data[i] > x && L->data[i] < y){
			L->data[i+1] = L->data[i];
			L->len--; 
		}
		else{
			i++;
		}
	}
}
//删除元素值在 x和y(x<=y)之间的所有元素

 


//int main(){
//	sqlist *A = (sqlist *)malloc(sizeof(sqlist));
//	A->len = 10;
//	int n;
//	for(n=0;n<10;n++){
//		A->data[n] = n-5;
//	}
//	sqlist *B = (sqlist *)malloc(sizeof(sqlist));
//	sqlist *C = (sqlist *)malloc(sizeof(sqlist));
//	B->len = 0;
//	C->len = 0;
//	int i;
//	for(i=0;i<A->len;i++){
//		if(A->data > 0){
//			B->data[B->len] = A->data[i];
//			B->len++;
//		}
//		else{
//			C->data[C->len] = A->data[i];
//			C->len++;
//		}
//	}
//}
//大于0的数字放在B中，小于0的数字放在C中 

//int main(){
//	int a[2];       //构造一个数组，其中前一位放最小值，后一位放最大值 
//}
//int *findMaxMin(sqlist *L,int a[]){   //返回指向数组的指针 
//	int i;
//	a[0] = L->data[0];
//	a[1] = L->data[0];
//	for(i = 1;i < L->len;i++){
//		if(L->data[i] < a[0])
//			a[0] = L->data[i];
//		else if(L->data > a[1])
//			a[1] = L->data[i];
//	}
//	return a;
//}
// 算法分析：在这个函数中，最坏的情况是第一个if均不成立，则比较次数为2(n-1)
//最好情况下第一个if一直成立，则比较次数为n-1
//因此平均比较次数为[2(n-1)+n-1] = 3n/2 - 3/2<=3n/2

//在一个顺序表A中找出最大和最小值的元素 


//int main()
//{
//	sqlist *temp = (sqlist *)malloc(sizeof(sqlist));
//	int i;
//	temp->len = 10;
//	for(i=0;i<10;i++){
//		temp->data[i] = i;
//	}
//	print(temp);
//	cut(temp,4,8);
//	printf("\n");
//	print(temp);
//	return 0;
//}
