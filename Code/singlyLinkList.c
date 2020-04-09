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

void printList(Lnode *head){
	if(head->next == NULL)
		return;
	Lnode *p = head->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}
}
//������Ա�

elemtype getKey(Lnode *head,int i){
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

void delPos(Lnode *head,int pos){
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

void delKey(Lnode *head,elemtype key){
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

void addHead(Lnode *head,elemtype key){
	Lnode *p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	p->next = head->next;
	head->next = p;
}
//����ͷ����Ӽ�ֵΪkey��Ԫ��

void addTail(Lnode *head,elemtype key){
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

void addPos(Lnode *head,elemtype key,int pos){
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

int isExist(Lnode *head,elemtype key){
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


int main() {
	return 0;
}
