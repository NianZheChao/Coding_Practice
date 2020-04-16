#include <stdio.h>
#include <stdlib.h>

# define elemtype char

typedef struct tree{
	elemtype ch;
	struct tree *lchild,*rchild;
}btnode;        //定义二叉树结点 

//btnode *creatTree(char string){    //按先序序列建立二叉链表 
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

btnode *creatTree(){  //建立二叉链表 
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

void preorder(btnode *T){  //先序遍历 
	if(T){
		printf("%c",T->ch);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(btnode *T){  //中序遍历 
	if(T){
		inorder(T->lchild);
		printf("%c",T->ch);
		inorder(T->rchild);
	}
}
void postorder(btnode *T){  //后序遍历 
	if(T){
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c",T->ch); 
	}
}

int countLeaf(btnode *T){  //求二叉树的叶子数 
	static int y;
	if(T==NULL)
		return y;
	if(T->lchild==NULL&&T->rchild==NULL)
		y++;
	countLeaf(T->lchild);
	countLeaf(T->rchild);
	return y;
}

int high(btnode *T){  //求二叉树的深度 
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

int precede(char optr1,char optr2){ //表达式优先级 
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


void infixExpression(btnode *T){  //输出带括号的中缀表达式 
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

int nonRecCountLeaf(btnode *T){     //非递归算法求叶子数 
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

btnode *copyBtree(btnode *T){    //复制二叉树 
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

void nonRecInorder(btnode *T){  //非递归算法中序输出 
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
	printf("输入先序遍历序列，创建二叉树：");
	bt = creatTree(*bt);
//	printf("\n该二叉树的先序遍历序列为：");
//	preorder(bt);
//	printf("\n该二叉树的中序遍历序列为：");
//	inorder(bt);
//	printf("\n该二叉树的后续遍历序列为：");
//	postorder(bt);
//	int L,H;
//	printf("\n该二叉树的叶子数为：");
//	L=countLeaf(bt);
//	printf("%d",L);
//	printf("\n该二叉树的深度为：");
//	H=high(bt);
//	printf("%d",H);
//	printf("\n该二叉表达式树带括号的输出为：");
//	infixExpression(bt);
	printf("\n非递归方法输出该二叉树中序序列：");
	nonRecInorder(bt);
	btnode *t=(btnode *)malloc(sizeof(btnode));
	t = copyBtree(bt);
	printf("\n复制后二叉树的中序序列输出为：");
	inorder(t);
	printf("\n非递归方法求得二叉树的叶子数为：");
	int L;
	L =  nonRecCountLeaf(bt);
	printf("%d",L);
	int C;
	C = countSingleC(bt);
	printf("\n二叉树中度为 1 的结点数为："); 
	printf("%d",C);
	return 0;
}
