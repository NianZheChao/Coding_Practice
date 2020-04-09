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

void printList(Lnode *head){
	if(head->next == NULL)
		return;
	Lnode *p = head->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}
}
//输出线性表

elemtype getKey(Lnode *head,int i){
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

void delPos(Lnode *head,int pos){
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

void delKey(Lnode *head,elemtype key){
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

void addHead(Lnode *head,elemtype key){
	Lnode *p = (Lnode *)malloc(sizeof(Lnode));
	p->data = key;
	p->next = head->next;
	head->next = p;
}
//向表的头部添加键值为key的元素

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
//向表的尾部添加键值为key的元素

void addPos(Lnode *head,elemtype key,int pos){
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

int isExist(Lnode *head,elemtype key){
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


int main() {
	return 0;
}
