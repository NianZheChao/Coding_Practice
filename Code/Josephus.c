#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(Lnode)

typedef int elemtype;

typedef struct node{
	elemtype data;
	struct node *next;
}Lnode;


Lnode *creat(){           //构造有30个结点的循环链表 
	Lnode *p,*head,*tail;
	tail = head = (Lnode *)malloc(LEN);
	head->next = NULL;
	int i = 0;
	while(1){
		p = (Lnode *)malloc(LEN);
		p->data = i;
		tail->next = p;
		tail = p;
		tail->next = NULL;
		i++;
		if(i=31)break;
	}
	tail->next = head->next;
	return head;
}


void *printList(Lnode *head){     //输出循环链表 
	if(head->next == NULL)
		return;
	Lnode *p = head->next;
	while(p->next!=head){
		printf("%d",p->data);
		p = p->next;
	}
	return;
}

void *del(Lnode *head){  //删除第15个结点，并返回被删除位置后的结点 
	int i = 1;
	int pos = 15;
	Lnode *q,*p = head->next;
	if(p == NULL)
		return;
	while(i < pos-1){
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return p->next;
}

int main(){
	Lnode *P = creat();
	printList(P);
	int i;
	for(i=0;i<15;i++){  //删除15次 
		P = del(P);
	}
	printList(P);
}


//#include<stdio.h>

//int c = 0;
//int i = 1;
//int j = 0;
//int a[30] = { 0 };
//int b[30] = { 0 };
// 
//int main()
//{
//    while (i<=31)
//    {
//        if (i == 31)
//        {
//            i = 1;
//        }
//        else if (c == 15)
//        {
//            break;
//        }
//        else
//        {
//            if (b[i] != 0)
//            {
//                i++;
//                continue;
//            }
//            else
//            {
//                j++;
//                if (j != 9)
//                {
//                    i++;
//                    continue;
//                }
//                else
//                {
//                    b[i] = 1;
//                    a[i] = j;
//                    j = 0;
//                    printf("第%d号下船了\n", i);
//                    i++;
//                    c++;
//                }
//            }
//        }
//    }
//}



