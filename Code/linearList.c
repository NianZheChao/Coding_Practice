#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

typedef int datatype;
typedef struct{
	datatype data[MAXSIZE];
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


int main()
{
	sqlist *temp = (sqlist *)malloc(sizeof(sqlist));
	int i;
	temp->len = 10;
	for(i=0;i<10;i++){
		temp->data[i] = i;
	}
	print(temp);
	cut(temp,4,8);
	printf("\n");
	print(temp);
	return 0;
}
