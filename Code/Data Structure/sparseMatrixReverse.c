#include <stdio.h>
#include <stdlib.h>

#define T 28

typedef struct node{
    int i,j,v;
} NODE;

void initMatrix(NODE* matrix,int nums [11][10]){
    int i,j;
    for(i=0;i<matrix[0].i;i++){
        for(j=0;j<matrix[0].j;j++){
            if(nums[i][j]==1){
                matrix[0].v++;
                matrix[matrix[0].v].i=i;
                matrix[matrix[0].v].j=j;
                matrix[matrix[0].v].v=nums[i][j];
            }
        }
    }
}

void putMatrix(NODE* matrix){
    int i,j;
    int count=1;
    for(i=0;i<matrix[0].i;i++){
        for(j=0;j<matrix[0].j;j++){
            if(i==matrix[count].i&&j==matrix[count].j){
                printf("*",matrix[count].v);
                count++;
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void reverse(NODE* matrix,NODE* new_matrix){
    int num[matrix[0].j],cpot[matrix[0].j];
    int tmp,first,i;
    new_matrix[0].i=matrix[0].j;
    new_matrix[0].j=matrix[0].i;
    new_matrix[0].v=matrix[0].v;
    for(i=0;i<matrix[0].j;i++){
        num[i]=0;
    }
    for(i=1;i<=matrix[0].v;i++){
        num[matrix[i].j]++;
    }
    cpot[0]=1;
    for(i=1;i<matrix[0].j;i++){
        cpot[i]=cpot[i-1]+num[i-1];
    }
    for(i=1;i<=matrix[0].v;i++){
        tmp=matrix[i].j;
        first=cpot[tmp];
        new_matrix[first].i=matrix[i].j;
        new_matrix[first].j=matrix[i].i;
        new_matrix[first].v=matrix[i].v;
        cpot[tmp]++;
    }
}


int main() {
    int nums[11][10]={
            {0,1,1,1,1,1,1,1,0,0},
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,0,1,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,1,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1}
    };
    NODE M[T+1];
    M[0].i = 11;
    M[0].j = 10;
    M[0].v = 0;
    initMatrix(M,nums);
    putMatrix(M);
    NODE m[T+1];
    reverse(M,m);
    putMatrix(m);
    return 0;
}
