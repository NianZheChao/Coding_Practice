## 矩阵/数组

数据结构讨论的数组是一个**逻辑概念**，是一种特殊的线性表，表中数据元素本身可以是不可再分解的元素，也可以是一个线性表。

**数组**结构固定，每一个维度上的元素同构。

### 数组在内存中的存储

行主序：$Loc(a_{ij})=Loc(a_{00})+(i×n+j)×L$

列主序：$Loc(a_{ij})=Loc(a_{00})+(j×m+i)×L$

### 对称矩阵

相对于主对角线，两侧的对应值相等。【地图染色问题】

压缩存储方式，只存一半即可。第n行存n个元素。

### 三角矩阵

相对于主对角线，对角线以下为一个三角形矩阵，对角线以上被一个常数C填充。

$Loc(a_{n-1,n-1}) = \frac{n(n+1)}{2}-1$

$Loc(C) =  \frac{n(n+1)}{2}$

### 对角矩阵(带状矩阵)

以主对角线为对称轴，其上下各n条斜线存储数据，其他位置以0元填充。

### 稀疏矩阵（sparse matrix）

若非零元个数远小于零元个数，且分布无规律，则称之为稀疏矩阵。（density<=5%）

#### 三元组表

存储稀疏矩阵非零元素的行、列下标及其值，行列维数，非零元个数。

数据结构可视化如下：

| 0    | 行总数       | 列总数       | 非零元个数 |
| ---- | ------------ | ------------ | ---------- |
| 1    | 非零元行下标 | 非零元列下标 | 非零元素值 |
| 2    | 同上         | 同上         | 同上       |
| 3    | ...          | ...          | ...        |
| ...  | ...          | ...          | ...        |

```C
#define T 8
typedef struct node{
    int i,j,v;
}NODE;
NODE M[T+1];
//在该例中，创建了一个非零元个数为8的三元组表
//i,j,v,三个参数在第一行中分别表示行维度、列维度、非零元个数
//i,j,v,三个参数在除第一行的其他行中分别表示每个非零元的行下标、列下标、元素值
```

#### 稀疏矩阵快速转置

思路：

- 按M中三元组次序转置，转置结果放入N中恰当位置
- 确定M中每一列第一个非零元在N中位置
  - 为确定这些位置，应先计算M每一列中非零元个数
- 设两个辅助数组
  - num[col]：表示M中第col列中非零元个数
  - cpot[col]：指示M中第col列第一个非零元在N中位置
- 显然有：
  - cpot[1] = 1;
  - cpot[col] = cpot[col - 1] + num[col - 1];           (2<=col<=M[0].j)
  

**代码实现**

```C
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1250
 
#define    OK      1
#define    ERROR   0
#define    TRUE    1
#define    FLASE   0
 
typedef    int     ElemType;
 
typedef struct{
    int   i, j;       //该非零元的行下标和列下标
    ElemType e;       //非零元对应的值
}Triple;
 
typedef struct{
    Triple   data[MAXSIZE];       //非零元三元组表
    int      mu, nu, tu;            //矩阵的行数，列数，非零元个数
}TSMatrix;
 
void FastTransposeSMatrix(TSMatrix M, TSMatrix &T)              //快速转置
{                                                      //采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if(T.tu)
    {
        int col;
        int num[100], cpot[100];
        for (col = 0; col < M.nu; col++)
            num[col] = 0;                 //num数组的初始化
        for (int t = 0; t < M.tu; t++)
            ++num[M.data[t].j];         //求M中每一列含有的非零元个数
        cpot[0] = 0;
        for (col = 1; col < M.nu; col++)
            cpot[col] = cpot[col - 1] + num[col - 1];         //求cpot向量
        int q;
        for (int p = 0; p < M.tu; p++)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }//for
    }//if
    return;
}//FastTransposeSMatrix
 
int main()
{
    TSMatrix M;
    TSMatrix T;
    scanf("%d %d", &M.mu, &M.nu);
    int x,y,z;
    M.tu=0;
    for (int i = 0; ; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if(x==0&&y==0&&z==0)break;
        M.data[i].i=x;M.data[i].j=y;M.data[i].e=z;
        M.tu++;
    }
 
    FastTransposeSMatrix(M, T);
 
    for (int t = 0; t < T.tu; t++)
        printf("%d %d %d\n", T.data[t].i, T.data[t].j, T.data[t].e);
    return 0;
}
```

#### 十字链表

**背景**：在某些运算中，如矩阵加法：$C = A + B$，可能使稀疏矩阵的非零元**位置发生变化**，将引起三元组表中元素的移动；此时对顺序存储的三元组表，移动元素的时间**开销大**，且为了维护行、列主序，可能产生更多开销。

**概念**：

- 十字链表是稀疏矩阵的另一种存储策略。

- 每个非零元为一个结点，每个结点含5个域
  - 其中，行域i、列域j、值域v分别表示非零元素的行下标、列下标、值
  - 向右域right链接同一行中下一个非零元素
  - 向下域down链接同一列中下一个非零元素
- 十字链表存储需要额外的指针域、行、列指针
- 一般地，当非零元数不超过总元素个数的20%，适用十字链表存储。

