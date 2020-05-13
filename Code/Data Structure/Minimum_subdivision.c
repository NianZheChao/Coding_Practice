#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

typedef int elemtype;
typedef struct node
{   elemtype data;
    struct node *next;
}QNODE;
//链队列类型定义
typedef  struct
{   QNODE *front;    //队头指针
    QNODE *rear;    //队尾指针
}LQUEUE;
//LQUEUE *q;       //封装了队头指针和队尾指针

void init(LQUEUE *stack);
int isEmpty(LQUEUE *q);
void print(LQUEUE *q,int i);

void enqueue(LQUEUE *q,elemtype s){
    QNODE *t = (QNODE *)malloc(sizeof(QNODE));
    t->data = s;
    t->next = NULL;
    q->rear->next = t;
    q->rear = t;
    q->front->data++;
}

elemtype dequeue(LQUEUE *q){
    QNODE *r=q->front->next;
    elemtype e=r->data;
    q->front->next=r->next;
    if(r->next==NULL)
        q->rear=q->front;
    (q->front->data)--;
    free(r);
    return e;
}

int main(){
    int r[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                     {0,0,1,0,0,0,0,0,0,0},
                     {0,1,0,0,0,1,1,0,1,1},
                     {0,0,0,0,0,0,1,1,0,0},
                     {0,0,0,0,0,1,0,0,0,1},
                     {0,0,1,0,1,0,1,1,0,1},
                     {0,0,1,1,0,1,0,1,0,0},
                     {0,0,0,1,0,1,1,0,0,0},
                     {0,0,1,0,0,0,0,0,0,0},
                     {0,0,1,0,1,1,0,0,0,0}};
    int result[10] = {0,0,0,0,0,0,0,0,0,0};
    int newrela[10] = {0,0,0,0,0,0,0,0,0,0};
    LQUEUE *q=init();
    int i = 1;
    while(i<=9){
        enqueue(q,i);
        i++;
    }
    int group = 1;
    result[1] = 1;
    int pre = 1;
    int count = 0;
    while(!isEmpty(q)){
        int j;
        elemtype e=dequeue(q);
        if(e<pre){
            printf("\nnewrela:");
            print(newrela,9);
            printf("result:");
            print(result,9);
            group++;

            result[e] = group;
            j=1;
            while (j<=9)
                newrela[j]=r[e][j],j++;
        }
        else if(newrela[e]==1)
            enqueue(q,e);
        else{
            result[e]=group;
            int j = 1;
            while (j<=9){
                if(r[e][j]==1)
                    newrela[j] = 1;
                j++;
            }
        }
        pre = e;
    }
    printf("newrela:");
    print(newrela,9);
    printf("result:");
    print(result,9);
}