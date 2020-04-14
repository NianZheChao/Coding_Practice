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

int countLeaf(btnode *T){
	static int y; 
//	if(T){
//		countLeaf(T->lchild);
//		countLeaf(T->rchild);
//		if(T->lchild==NULL&&T->rchild==NULL)
//			y++;

//		y = !((T->lchild?1:0)|(T->rchild?1:0));
//		return y+countLeaf(T->lchild)+countLeaf(T->rchild);
//	}
//	return 0;

	if(T==NULL)
		return y;
	if(T->lchild==NULL&&T->rchild==NULL)
		y++;
	countLeaf(T->lchild);
	countLeaf(T->rchild);
	return y;
}

int high(btnode *T){
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

int precede(char optr1,char optr2){
	switch(optr1){
		case'+':case'-':
			if(optr2=='+'||optr2=='-'){
				return 0;
			}
			else{
				return -1;
			}
		case'*':case'/':
			if(optr2=='*'||optr2=='/'){
				return 0;
			}
			else{
				return 1;
			}
	}
}


void infixExpression(btnode *T){
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


int main(){
//	char *str = "abcd";
//	char str[7]="abcd";
//	printf("%s",str);
//	int i;
//	for(i=0;str[i]!='\0';i++)
//	*str(i) = *str(i+1);
//	*str(i) =*str(i+1);
//	printf("%s",str);
	btnode *bt=(btnode *)malloc(sizeof(btnode));
	printf("输入先序遍历序列，创建二叉树：");
	bt = creatTree(*bt);
	printf("\n该二叉树的先序遍历序列为：");
	preorder(bt);
	printf("\n该二叉树的中序遍历序列为：");
	inorder(bt);
	printf("\n该二叉树的后续遍历序列为：");
	postorder(bt);
	int L,H;
	printf("\n该二叉树的叶子数为：");
	L=countLeaf(bt);
	printf("%d",L);
	printf("\n该二叉树的深度为：");
	H=high(bt);
	printf("%d",H);
	printf("\n该二叉表达式树带括号的输出为：");
	infixExpression(bt);
	return 0;
}
