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

void nonRecInorder(btnode *T){
	
}

int main(){
	btnode *bt=(btnode *)malloc(sizeof(btnode));
	printf("��������������У�������������");
	bt = creatTree(*bt);
//	printf("\n�ö������������������Ϊ��");
//	preorder(bt);
	printf("\n�ö������������������Ϊ��");
	inorder(bt);
//	printf("\n�ö������ĺ�����������Ϊ��");
//	postorder(bt);
//	int L,H;
//	printf("\n�ö�������Ҷ����Ϊ��");
//	L=countLeaf(bt);
//	printf("%d",L);
//	printf("\n�ö����������Ϊ��");
//	H=high(bt);
//	printf("%d",H);
	printf("\n�ö�����ʽ�������ŵ����Ϊ��");
	infixExpression(bt);
	
	
	return 0;
}