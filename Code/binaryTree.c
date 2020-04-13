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

void infixExpression(btnode *T){
	
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
	printf("��������������У�������������");
	bt = creatTree(*bt);
	printf("\n�ö������������������Ϊ��");
	preorder(bt);
	printf("\n�ö������������������Ϊ��");
	inorder(bt);
	printf("\n�ö������ĺ�����������Ϊ��");
	postorder(bt);
	int L,H;
	printf("\n�ö�������Ҷ����Ϊ��");
	L=countLeaf(bt);
	printf("%d",L);
	printf("\n�ö����������Ϊ��");
	H=high(bt);
	printf("%d",H);
	return 0;
}