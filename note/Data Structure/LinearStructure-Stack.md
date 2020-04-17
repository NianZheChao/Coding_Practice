## 堆栈

### 什么是堆栈

思考：计算机如何进行表达式求值？

- 由两类对象构成：运算数和运算符
- 不同运算符优先级不同

中缀表达式：运算符号在两个运算数之间，如，a+b*c-d/e

后缀表达式：运算符号在两个运算数之后，如，abc*+de/-

计算机的求值策略：从左向右扫描，逐个处理运算数和运算符号；若遇到运算数，则存储目前还不参与运算的数，若遇到运算符，则进行运算。

### 堆栈的抽象数据类型描述

堆栈（Stack）：具有一定操作约束的线性表，只在一端（栈顶，Top）做插入、删除。

后入先出：Last In First Out(LIFO)

### 栈的顺序存储实现

栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成。

```c
#define MaxSize <储存数据元素的最大个数>
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
};
```

#### 栈操作

1. 入栈

   ```c
   void Push(Stack PtrS,ElementType item){
       if(PtrS->Top == MaxSize-1){
           printf("堆栈满");
           return;
       }
       else{
           PtrS->Data[++(PtrS->Top)] = item;
           return;
       }
   }
   ```

2. 出栈

   ```c
   ElementType Pop(Stack PtrS){
       if(PtrS->Top == -1){
           printf("堆栈空");
           return ERROR;                         //ERROR是ElementType的特殊值，标志错误
       }
       else{
           return(PtrS->Data[(PtrS->Top)--]);
       }
   }
   ```

### 堆栈的链式存储实现

栈的链式存储结构实际上就是一个单链表，叫做链栈。插入和删除操作只能在链栈的栈顶进行。Top在链表头。

```c
typedef struct SNode *Stack;
struct SNode{
    ELementType Data;
    struct SNode *Next;
};
```

#### 栈操作

1. 建立空栈

   ```c
   Stack CreateStack(){
       Stack S;
       S = (Stack)malloc(sizeof(struct SNode));
       S->Next = NULL;
       return S;
   }
   
   int IsEmpty(Stack S){
       return (S->Next == NULL);
   }
   ```

2. 入栈

   ```c
   void Push(ElementType item,Stack S){
       struct SNode &TmpCell;
       TmpCell = (struct SNode *)malloc(sizeof(struct SNode));
       TmpCell -> Element = item;
       TmpCell -> Next = S->Next;
       S->Next = TmpCell;
   }
   ```

3. 出栈

   ```c
   ElementType Pop(struct *PtrS){
           if(PtrS->Top == -1){
            printf("堆栈空");
               return ERROR;
       }
       else{
           return(PtrS->Data[(PtrS->TOp)--]);
       }
   }
   ```
   

### 堆栈应用：表达式求值

略

