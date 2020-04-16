#include <stdio.h>
#include <stdlib.h>

# define elemtype char

typedef struct tree{
	elemtype ch;
	struct tree *lchild,*rchild;
}btnode;        //������������ 

//btnode *creatTree(char string){    //���������н����������� 
//	btnode *bt;
//	if(string == '.')
//		return (NULL);
//	else{
//		bt = (btnode *)malloc(sizeof(btnode));
//		bt->ch = string;
//		bt->lchild = creatTree(string);
//		bt->rchild = creatTree(string);
//		return(bt);
//	}
//}

btnode *creatTree(){  //������������ 
	elemtype ch;
	btnode *bt;
	ch = getchar();
	if(ch=='.')
		return(NULL);
	else{
		bt=(btnode *)malloc(sizeof(btnode));
		bt->ch = ch;
		bt->lchild = creatTree();
		bt->rchild = creatTree();
		return(bt);
	}
}

void preorder(btnode *T){  //������� 
	if(T){
		printf("%c",T->ch);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(btnode *T){  //������� 
	if(T){
		inorder(T->lchild);
		printf("%c",T->ch);
		inorder(T->rchild);
	}
}
void postorder(btnode *T){  //������� 
	if(T){
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c",T->ch); 
	}
}

int countLeaf(btnode *T){  //���������Ҷ���� 
	static int y;
	if(T==NULL)
		return y;
	if(T->lchild==NULL&&T->rchild==NULL)
		y++;
	countLeaf(T->lchild);
	countLeaf(T->rchild);
	return y;
}

int high(btnode *T){  //������������ 
	int i=0;
	int m=0;
	int n=0;
	if(T==NULL)
		return i;
	else{
		m = high(T->lchild);
		n = high(T->rchild);
		i = m>n?m:n;
		i++;
		return i;
	}
}

int precede(char optr1,char optr2){ //���ʽ���ȼ� 
	switch(optr1){
		case'+':case'-':{ 
			if(optr2=='+'||optr2=='-'){
				return 0;
			}
			else{
				return -1;
			}
		}
		case'*':case'/':{ 
			if(optr2=='*'||optr2=='/'){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
}


void infixExpression(btnode *T){  //��������ŵ���׺���ʽ 
	int bracket;
	if(T){
	if(T->lchild!=NULL){
		bracket = precede(T->ch,T->lchild->ch);
		if(bracket==1)
			printf("(");
		infixExpression(T->lchild);
		if(bracket==1)
			printf(")");
	}
	printf("%c",T->ch);
	if(T->rchild!=NULL){
		bracket = precede(T->ch,T->rchild->ch);
		if(bracket==1)
			printf("(");
		infixExpression(T->rchild);
		if(bracket==1)
			printf(")");
	}
}
}

#define MAXSIZE 1024
typedef struct{
	elemtype *bt[MAXSIZE];
	int top;
}STACK;

int isEmpty(STACK *stack){
	if(stack->top==-1)
	return 1;
	return 0;
}

void push(STACK *stack,elemtype *c){
	if(stack->top<MAXSIZE-1)
		stack->bt[++(stack->top)]=c;
}

elemtype *pop(STACK *stack){
	elemtype *c = NULL;
	if(!isEmpty(stack))
		c=stack->bt[(stack->top)--];
	return c;
}

STACK *initstack(){
	STACK *stack=(STACK *)malloc(sizeof(STACK));
	stack->top=-1;
	return stack;
}

int nonRecCountLeaf(btnode *T){     //�ǵݹ��㷨��Ҷ���� 
	STACK *s = initstack();
	if(T==NULL)
		return 0;
	if(!T->lchild&&!T->rchild)
		return 1;
	int count = 0; 
	push(s,T);
	T=T->lchild;
	while(1){
		while(T){
			push(s,T);
			T=T->lchild;
		}
		if(!isEmpty(s)){
			T=pop(s);
			if(!T->lchild&&!T->rchild)
				count++;
			T=T->rchild;
		}
		else{
			free(s);
			return count;
		}
	}
}

btnode *copyBtree(btnode *T){    //���ƶ����� 
	btnode *t;
	if(T==NULL)
		return NULL;
	else{
		t = (btnode *)malloc(sizeof(btnode));
		t->ch = T->ch;
		t->lchild = copyBtree(T->lchild);
		t->rchild = copyBtree(T->rchild); 
		return t;
	}
}

void nonRecInorder(btnode *T){  //�ǵݹ��㷨������� 
	STACK *s = initstack();
	if(T==NULL)
		return 0;
	push(s,T);
	T=T->lchild;
	while(1){
		while(T){
			push(s,T);
			T=T->lchild;
		}
		if(!isEmpty(s)){
			T=pop(s);
			printf("%c",T->ch);
			T=T->rchild;
		}
		else{
			free(s);
			return;
		}
	}
}

int countSingleC(btnode *T){
	static int y;
	if(T==NULL)
		return y;
	if((T->lchild==NULL&&!T->rchild==NULL)||(!T->lchild==NULL&&T->rchild==NULL))
		y++;
	countSingleC(T->lchild);
	countSingleC(T->rchild);
	return y;
}

int main(){
	btnode *bt=(btnode *)malloc(sizeof(btnode));
	printf("��������������У�������������");
	bt = creatTree(*bt);
//	printf("\n�ö������������������Ϊ��");
//	preorder(bt);
//	printf("\n�ö������������������Ϊ��");
//	inorder(bt);
//	printf("\n�ö������ĺ�����������Ϊ��");
//	postorder(bt);
//	int L,H;
//	printf("\n�ö�������Ҷ����Ϊ��");
//	L=countLeaf(bt);
//	printf("%d",L);
//	printf("\n�ö����������Ϊ��");
//	H=high(bt);
//	printf("%d",H);
//	printf("\n�ö�����ʽ�������ŵ����Ϊ��");
//	infixExpression(bt);
	printf("\n�ǵݹ鷽������ö������������У�");
	nonRecInorder(bt);
	btnode *t=(btnode *)malloc(sizeof(btnode));
	t = copyBtree(bt);
	printf("\n���ƺ�������������������Ϊ��");
	inorder(t);
	printf("\n�ǵݹ鷽����ö�������Ҷ����Ϊ��");
	int L;
	L =  nonRecCountLeaf(bt);
	printf("%d",L);
	int C;
	C = countSingleC(bt);
	printf("\n�������ж�Ϊ 1 �Ľ����Ϊ��"); 
	printf("%d",C);
	return 0;
}
