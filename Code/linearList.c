#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

typedef int elemtype;
typedef struct{
	elemtype data[MAXSIZE];
	int len;
}sqlist;
//���Ա�����Ͷ���

void initlist(sqlist *L){
	L->len = 0;
}
//��ʼ�������Ա�

void print(sqlist *L){
	int i;
	for(i = 0;i < L->len;i++)
		if (i<L->len)
			printf("%d",L->data[i]);
		else
			return;
}
//������Ա�

int take(sqlist *L,int i){
	return L->data[i];
}
//ȡ�����е�i��Ԫ�صļ�ֵ 

void delePos(sqlist *L,int i){
	int j;
	if((i > L->len)||(i < 1)){
		printf("λ�ò��ڱ���"); 
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
//�ӱ���ɾ��ָ��λ�õ�Ԫ��


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
//ɾ��Ԫ��ֵ�� x��y(x<=y)֮�������Ԫ��

 


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
//����0�����ַ���B�У�С��0�����ַ���C�� 

//int main(){
//	int a[2];       //����һ�����飬����ǰһλ����Сֵ����һλ�����ֵ 
//}
//int *findMaxMin(sqlist *L,int a[]){   //����ָ�������ָ�� 
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
// �㷨����������������У��������ǵ�һ��if������������Ƚϴ���Ϊ2(n-1)
//�������µ�һ��ifһֱ��������Ƚϴ���Ϊn-1
//���ƽ���Ƚϴ���Ϊ[2(n-1)+n-1] = 3n/2 - 3/2<=3n/2

//��һ��˳���A���ҳ�������Сֵ��Ԫ�� 


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
