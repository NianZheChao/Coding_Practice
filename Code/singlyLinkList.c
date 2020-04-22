#include <stdio.h>
#include <stdlib.h>

typedef char elemtype;

typedef struct node{
	elemtype data;
	struct node *next;
}Lnode;
//������Ķ��� 

#define LEN sizeof(Lnode)     //�����㳤�� 

Lnode *creatHead(){
	Lnode *head;
	head = (Lnode *)malloc(LEN);
	head->data = NULL;
	head->next = NULL;
	return head;
}//����������ͷ���

void *printList(Lnode *head){
	if(head->next == NULL)
		return;
	Lnode *p = head->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}
}
//������Ա�

elemtype *getKey(Lnode *head,int i){
	int counter;
	Lnode *p = head;
	if(p == NULL)          //������Χ 
		return;
	for(counter = 0;counter < i; counter++){
		p = p->next;
		if(p == NULL)               //������Χ 
			return;
	}
	return p->data;
}
//ȡ���еĵ�i��Ԫ�صļ�ֵ

void *delPos(Lnode *head,int pos){
	int i = 1;
	Lnode *q,*p = head->next;
	if(p == NULL)          //�ձ����� 
		return;
	while(i < pos-1){      //Ѱ��ɾ��λ�õ�ǰ����� 
		p = p->next;
		i++;
		if(!p->next)         //��ɾ��λ��ΪNULLʱ����
			return;
	}
	q = p->next;
	p->next = q->next;
	free(q);              //ɾ�����ͷ��ڴ� 
	return;
}
//�ӱ���ɾ��ָ��λ�õ�Ԫ��

void *delKey(Lnode *head,elemtype key){
	Lnode *q,*p = head->next;
	if(p == NULL)          //�ձ����� 
		return;
	while(key != p->data){
		p = p->next;
		if(!p)         //��ɾ��λ��ΪNULLʱ���� 
			return;
	}
	q = p->next;
	p->next = q->next;
	free(q);              //ɾ�����ͷ��ڴ� 
	return;
}
//�ӱ���ɾ��ָ����ֵ��Ԫ��

void *addHead(Lnode *head,elemtype key){
	Lnode *p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	p->next = head->next;
	head->next = p;
}
//����ͷ����Ӽ�ֵΪkey��Ԫ��

void *addTail(Lnode *head,elemtype key){
	Lnode *tail=head->next,*p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	p->next = NULL;
	while(tail->next != NULL){
		tail = tail->next;
	}
	p = tail->next;
	free(tail);
}
//����β����Ӽ�ֵΪkey��Ԫ��

void *addPos(Lnode *head,elemtype key,int pos){
	int i = 0;
	Lnode *q,*r,*p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	q->next = head;
	while(i < pos-1){                 //���λ�õ�ǰ�� 
		q = q->next;
		i++; 
	}
	r = q->next;                    //���λ�õĺ�� 
	p->next = r;
	q->next = p;
	free(r);                         //�ͷŸ�������ڴ� 
	free(q);
}
//�����ָ����λ��pos����Ӽ�ֵΪkey��Ԫ��

int *isExist(Lnode *head,elemtype key){
	Lnode *p;
	p->next = head->next;
	while(p->data != key){
		p = p->next;
		if(p->next == NULL)
			return 0;          //����������� 
	}
	return 1;
}
//�ڱ�����������ֵΪkey��Ԫ�أ������Ƿ���� 

Lnode *copy(Lnode *L){
	Lnode *p,*head,*tail;
	tail = (Lnode *)malloc(sizeof(Lnode));
	head = (Lnode *)malloc(sizeof(Lnode));
	head->next = NULL;
	while(p->next != NULL){
		L = L->next;
		p = (Lnode *)malloc(sizeof(Lnode));
		p->data = L->data;
		tail->next = L;
		tail = p;
		tail->next = NULL;
	}
	return head;
}
//���������Ƶ���һ����������


Lnode *defference(Lnode *A,Lnode *B){   //����������Ĳ 
	Lnode *p,*q;
	p->next = A->next;
	q->next = B->next;
	Lnode *R = (Lnode *)malloc(sizeof(Lnode));
	while(1){
		if(p->data < q->data||!q){
			Lnode *L =(Lnode *)malloc(sizeof(Lnode));
			L->next = R->next;
			R->next = L;
			L->data = p->data;
			p = p->next;
		}
		if(p->data > q->data){
			q = q->next;
		}
		if(p->data == q->data){
			p = p->next;
			q = q->next;
		}
		if(!p)
			break;
	}
	return R;
}



//������ʵ�ֶ���ʽ��ͣ���bug��

//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node{
//	int ext;       //ָ�� 
//	float coef;    //ϵ�� 
//	struct node *next;
//}polynode;
//
//
//void *printList(polynode *head){
//	if(head->next == NULL)
//		return;
//	polynode *p = head->next;
//	while(p){
//		printf("%+.1f",p->coef);
//		printf("x^%d",p->ext);
//		p = p->next;
//	}
//}
//
//
//polynode *putIn(polynode *head){
//	polynode *p;
//	int i;
//	printf("Enter the number of terms in the polynomial:");
//	scanf("%d",&i);          //���� 
//	int j;
//	for(j=0;j<i;j++){
//		int e;
//		float c;
//		printf("Enter exponent and coefficient:");
//		scanf("%d%f",&e,&c);
//		polynode *p = (polynode *)malloc(sizeof(polynode));
//		p->coef = c;
//		p->ext = e;
//		p->next = head->next;
//		head->next = p;
//	}
//	return head;
//}
//
//polynode *sum(polynode *A,polynode *B){
//	polynode *p,*head,*a,*b;
//	a->next = A->next;
//	b->next = B->next;
//	while(a->next != NULL||b->next != NULL){
//		if(a->ext == b->ext){
//			polynode *p = (polynode *)malloc(sizeof(polynode));
//			p->ext = a->ext;
//			p->coef = a->coef + b->coef;
//			p->next = head->next;
//			head->next = p;
//			a = a->next;
//			b = b->next;
//		}
//		else if(a->ext > b->ext){
//			polynode *p = (polynode *)malloc(sizeof(polynode));
//			p->ext = a->ext;
//			p->coef = a->coef;
//			a = a->next; 
//		}
//		else if(a->ext < b->ext){
//			polynode *p = (polynode *)malloc(sizeof(polynode));
//			p->ext = b->ext;
//			p->coef = b->coef;
//			b = b->next;
//		}
//		else if(a->next == NULL){
//			polynode *p = (polynode *)malloc(sizeof(polynode));
//			p->ext = b->ext;
//			p->coef = b->coef;
//			b = b->next;
//		}
//		else if(b->next ==NULL){
//			polynode *p = (polynode *)malloc(sizeof(polynode));
//			p->ext = a->ext;
//			p->coef = a->coef;
//			a = a->next; 
//		}
//	}
//	return head;
//}



int main() {
//	polynode *A = (polynode *)malloc(sizeof(polynode));
//	A->next = NULL;
//	A = putIn(A);
//	polynode *B = (polynode *)malloc(sizeof(polynode));
//	B->next = NULL;
//	B = putIn(B);
//	printList(B);
//	printList(sum(A,B));
	return 0;
}



//int main() {
//	return 0;
//}
