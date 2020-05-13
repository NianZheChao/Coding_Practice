# 链表

### 多项式的表示

思路：

​	多项式的关键数据：多项式项数n、各项系数ai、指数i

- 方法一：顺序存储结构直接表示

  表示方法：数组各分量对应多项式各项  a[i]:项xi的系数ai

  在表达高阶式子时，系数为0的项会占用大量空间。

- 方法二：顺序存储结构表示非零项

  每个非零项涉及两个信息：系数ai和指数i，将一个多项式看成一个(ai,i)二元数组的集合。

  表达方法：用结构数组表示，按照指数大小顺序排列；相加时从头开始比较两个多项式当前对应项的指数，进行相加和输出

- 方法三：链表结构存储非零项

  链表中每个结点存储多项式中的一个非零项，包括系数和指数两个*数据域*以及一个*指针域*。

```c
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
}
```

### 多项式问题的启示

有序线性序列的组织和管理，可以归结为**线性表问题**。

### 线性表

线性表：由同类型数据元素构成有序序列的线性结构。

- 表中元素个数称为线性表的长度。
- 线性表没有元素时，称为空表。
- 表起始位置称表头，表结束位置称为表尾。

### 线性表的抽象数据类型描述

类型名称：线性表（List）

数据对象集：线性表是n（>=0）个元素构成的有序序列（a1,a2,a3,...,an）

操作集：线性表L ∈ List，整数i表示位置，元素X∈ElementType，线性表的基本操作主要有：

1. `List MakeEmpty()` : 初始化一个空线性表L;
2. `ElementType FindKth( int K,List L)` : 跟据位序K，返回相应元素;
3. `int Find(ElementType X,List L)` : 在线性表L中查找X的第一次出现位置;
4. `void Insert(ElementType X,int i,List L)` : 在位序i前插入一个新元素X;
5. `void Delete(int i,List L)` : 删除指定位序i的元素;
6. `int Length(List L)` : 返回线性表L的长度n;

### 线性表的顺序存储实现

利用数组的连续存储空间顺序存放线性表的各元素。

```c
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;
```

线性表的长度：`L.Last+1`或`PtrL->Last+1` 

访问下标为i的元素：`L.Data[i]`或`PtrL->Data[i]`

### 主要操作的实现

1. 初始化（建立空的顺序表）

   ```c
   List MakeEmpty(){
       List PtrL;
       PtrL = (List)malloc(sizeof(struct LNode));
       //申请包括数组与代表最后一个元素的Last的结构，即顺序表
       PtrL -> Last = -1;
       //将结构的Last设为-1
       //因为Last代表最后一个元素，若Last为0,即有一个元素在该表的最后位置，故若Last为-1,即为空表
       return PtrL;
   }
   ```

2. 查找

   ```c
   int Find(ElementType X,List PtrL){
       int i = 0;
       while(i <= PtrL->Last && PtrL->Data[i] != X)
           i++;
       if (i > PtrL->Last)
           return -1;/*未找到，返回-1*/
       else
           return 0;/*若找到，返回存储位置*/
   }
   //查找成功的平均比较次数为(n+1)/2
   //平均时间性能为 O(n)
   ```

3. 插入（第i个位置上插入一个值为X的新元素）

   ```c
   void Insert(ElementType X,int i,List PtrL){
       int j;
       if(PtrL->Last == MAXSIZE-1){          //表空间已满，不能插入
           printf("表满");
           return;
       }
       if(i<1||i>PtrL->Last+2){              //检查插入位置的合法性
           printf("位置不合法");
           return;
       }
       for(j=PtrL->Last;j>=i-1;j--)
           PtrL->Data[j+1] = PtrL->Data[j];  //将ai至an倒序向后移动
       PtrL->Data[i-1] = X;                  //新元素插入
       PtrL->Last++;                         //Last仍指向最后元素
       return;
   }
   //平均移动次数为n/2
   //平均时间性能O(n)
   ```

4. 删除（删除表的第i个位置上的元素）

   ```c
   void Delete(int i,List PtrL){
       int j;
       if(i<1 || i> PtrL->Last+1){               //检查空表及删除位置的合法性
           printf("不存在第%d个元素"，i);
           return;
       }
       for(j = i;j <= PtrL->Last;j++)
           PtrL->Data[j-1] = PtrL->Data[j];      //将ai+1至an顺序向前移动
       PtrL->Last--;                             //Last仍指向最后元素
       return;
   }
   //平均移动次数为(n-1)/2
   //平均时间性能为O(n)
   ```



### 线性表的链式存储实现

- 不要求逻辑上相邻的两个元素物理上也相邻；通过“链”建立起数据元素之间的逻辑关系。
- 插入、删除不需要移动数据元素，只需要修改“链”。

```c
typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List Next;
};
struct Lnode L;
List PtrL;
```

### 主要操作的实现

1. 求表长

   ```c
   int Length(List PtrL){
       List p = PtrL;       //p指向表的第一个结点
    int j = 0;
       while (p){
           p = p->Next;
           j++;             //当前p指向的是第j个结点
       }                    //p为NULL时退出循环
       return j;
   }
   //时间性能为O(n)
   ```
   
2. 查找

   （1）按序号查找：`FindKth`;

   ```c
   List FindKth(int K,List PtrL){
       List p = PtrL;
       int i = 1;
       while (p != NULL && i < K){
           p = p->Next;
           i++;
       }
       if(i == K)                   //找到第K个，返回指针
           return p;
       else
           return NULL;             //否则返回空
   }
   ```

   （2）按值查找：Find

   ```c
   List Find(ElementType X,List ptrL){
       List p = PtrL;
       while (p != NULL && p->Data != X)
           p = p->Next;
       return p;
   }
   ```

   > 思考：如果将链式存储中`FindKth`的函数实现（如下）做个修改：把函数最后的if语句判断条件改为判断p是否为NULL，即：
   >
   > ```c
   > if (p==NULL) return NULL;
   > 
   > else return p;
   > ```
   >
   > 或者说直接简化为：return p;
   >
   > 对于这样的修改，程序还正确吗？为什么？
   >
   >  
   >
   > 答：错误。因为p初始被设为头指针PtrL，所以当输入不合法（k<1)时，程序不会进入循环，此时find函数未找到元素，因返回Null，但p却为PtrL

3. 插入（在第i-1个结点后插入一个值为X的新结点）

   （1）先构造一个新结点，用s指向;

   （2）再找到链表的第i-1个结点，用p指向;

   （3）然后修改指针，插入结点（p之后插入新结点是s）
   
   ```c
   List Insert(ElementType X,int i,List PtrL){
       List p,s;
       if(i == 1){                                     // 新结点在表头
           s = (List)malloc(sizeof(struct LNode));     //申请、填装结点
           s->Data = X;
           s->Next = PtrL;
           return s;                                   //返回新表头指针
       }
       p = FindKth(i-1,PtrL);
       if(p == NULL){
           printf("参数i错误");
           return NULL;
       }
       else{
           s = (List)malloc(sizeof(struct LNode));
           s->Data = x;
           s->Next = p->Next;
           p->Next = s;
           return PtrL;
       }
   }
   ```
   
4. 删除

   （1）先找到链表的第i-1个结点，用p指向;

   （2）再用指针s指向要被删除的结点（p的下一个结点）;

   （3）然后修改指针，删除s所指结点;

   （4）释放s所指结点空间

   ```c
   List Delete(int i,List PtrL){
       List p,s;
       if(i == 1){                      
           s = PtrL;
           if(PtrL != NULL)
               PtrL = PtrL->Next;
           else
               free(s);
           return PtrL;
       }
       P = FindKth(i-1,PtrL);
       if(p == NULL){
           printf("第%d个结点不存在"，i-1);
           return NULL;
       }
       else if(p->Next == NULL){
           printf("第%d个结点不存在"，i);
           return NULL;
       }
       else{
           s = p->Next;
           p->Next = s->Next;
           free(s);
           return PtrL;
       }
   }
   ```

### 广义表

---

略

### 多重链表

---

略

### 备注

手动在main()中编写测试样例

```C
int main()
{
	sqlist *temp = (sqlist *)malloc(sizeof(sqlist));
	int i;
	temp->len = 10;
	for(i=0;i<10;i++){         //结构体内数组赋值只能用循环的方式
		temp->data[i] = i;
	}
	print(temp);
	return 0;
}//在主函数中编写测试代码的方法
```

