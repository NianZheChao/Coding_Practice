#include <stdio.h>
#include <stdlib.h>

typedef char elemtype;

typedef struct node{
	elemtype data;
	struct node *next;
}Lnode;
//单链表的定义 

#define LEN sizeof(Lnode)     //定义结点长度 

Lnode *creatHead(){
	Lnode *head;
	head = (Lnode *)malloc(LEN);
	head->data = NULL;
	head->next = NULL;
	return head;
}//创建单链表头结点

void *printList(Lnode *head){
	if(head->next == NULL)
		return;
	Lnode *p = head->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}
}
//输出线性表

elemtype *getKey(Lnode *head,int i){
	int counter;
	Lnode *p = head;
	if(p == NULL)          //超出范围 
		return;
	for(counter = 0;counter < i; counter++){
		p = p->next;
		if(p == NULL)               //超出范围 
			return;
	}
	return p->data;
}
//取表中的第i个元素的键值

void *delPos(Lnode *head,int pos){
	int i = 1;
	Lnode *q,*p = head->next;
	if(p == NULL)          //空表，跳出 
		return;
	while(i < pos-1){      //寻找删除位置的前驱结点 
		p = p->next;
		i++;
		if(!p->next)         //所删除位置为NULL时跳出
			return;
	}
	q = p->next;
	p->next = q->next;
	free(q);              //删除，释放内存 
	return;
}
//从表中删除指定位置的元素

void *delKey(Lnode *head,elemtype key){
	Lnode *q,*p = head->next;
	if(p == NULL)          //空表，跳出 
		return;
	while(key != p->data){
		p = p->next;
		if(!p)         //所删除位置为NULL时跳出 
			return;
	}
	q = p->next;
	p->next = q->next;
	free(q);              //删除，释放内存 
	return;
}
//从表中删除指定键值的元素

void *addHead(Lnode *head,elemtype key){
	Lnode *p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	p->next = head->next;
	head->next = p;
}
//向表的头部添加键值为key的元素

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
//向表的尾部添加键值为key的元素

void *addPos(Lnode *head,elemtype key,int pos){
	int i = 0;
	Lnode *q,*r,*p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	q->next = head;
	while(i < pos-1){                 //添加位置的前驱 
		q = q->next;
		i++; 
	}
	r = q->next;                    //添加位置的后继 
	p->next = r;
	q->next = p;
	free(r);                         //释放辅助结点内存 
	free(q);
}
//向表中指定的位置pos处添加键值为key的元素

int *isExist(Lnode *head,elemtype key){
	Lnode *p;
	p->next = head->next;
	while(p->data != key){
		p = p->next;
		if(p->next == NULL)
			return 0;          //链表搜索完毕 
	}
	return 1;
}
//在表中中搜索键值为key的元素，看其是否存在 

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
//将单链表复制到另一个单链表中


Lnode *defference(Lnode *A,Lnode *B){   //两个单链表的差集 
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



//单链表实现多项式求和（有bug）

//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node{
//	int ext;       //指数 
//	float coef;    //系数 
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
//	scanf("%d",&i);          //项数 
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
