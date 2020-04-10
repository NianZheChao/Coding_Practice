# C语言学习笔记

## 数组

### 创建数组

- 声明一个数组，声明时用常量表达式指定数组维数，然后使用数组名访问数组元素。

```c
 int  array[5];
```

- 声明一个变长数组，声明时用变量表达式指定数组维数，然后使用数组名访问数组元素。

```c
int n = 5;

int  array[n];    // C99标准下才可以 
```

- 声明一个指针，调用malloc()，然后使用该指针访问数组元素。（需要引入头文件  <malloc.h>）

```c
int  *  array ;

array = (int * ) malloc(5 * sizeof(int));    // 5 个连续的地址
```

或者

```c
int  n = 5;

int  *  array ;

array = (int * ) malloc(n * sizeof(int));         // // n 个连续的地址。 C99标准下才可以
```
### 数组的初始化

```C
int a[5] = {1,2,3,4,5}; //完全初始化
int a[5] = {1,2}; //不完全初始化
int a[5] = {0}; //数组清零
int a[5] = {};//这种写法是错误的

int a[] = {1,2,3,4,5} //自动分配空间的数组初始化
```

```C
# include <stdio.h>
int main(void)
{
	int a[5];
	a[5] = {1, 2, 3, 4, 5};
	return 0;
}//这个程序是错误的，只有在定义的时候“a[常量]”表示的才是数组长度
```

若要令函数返回数组，可以①使用结构体，②返回指向该数组的指针，如下：

```C
#include<stdio.h>
#define N 10
int main(){
    int *addOne(int a[]);
    int a[N]={1,2,3,4,5,6,7,8,9,10};
    int i;
    printf("\n调用函数之后:\n");
    int *b = addOne(a);
    for(i=0;i<N;i++)
        printf("%d\t",b[i]);
}
int *addOne(int a[]){
    int i;
    for(i=0;i<N;i++)//全部加一
        a[i] += 1;
    return a;
}
```



## 指针

### 指针的本质

```c
//指针变量名为ptr
ptr = & pooh; //把pooh的地址赋给ptr指针，其中ptr是变量，pooh是常量
val = *ptr; //找出ptr指向的值

//以上两句相当于以下一句
val = pooh;
```

后跟一个变量名时，&给出该变量的地址。

后跟一个指针名或地址时，*给出储存在指针指向地址上的值。`指针变量本身的本质就是地址。`

C语言把数组名当做一个不可变的指针来使用，当向函数传递一个类型为T的数组对象时，其实就等同于向函数传递一个指向类型为T的对象的指针。

### 指针的声明

声明指针变量时必须指定指针所指向变量的类型

### 注意

```c
int *p;
*p = 1;
//使用这种方式对指针所指赋值时，仅仅是将指针所指向的值赋值，并没有对指针所指向的位置赋值，所以指针所指向的内存空间是随机的，此时无法print指针地址
int k = 1;
int *p;
p = &k;
//此时才可以输出指针所指向的固定地址
```

## 结构体

### 结构体的建立

```c
struct book{
    char title[MAXTITL];    //结构成员列表
    char author[MAXAUTL];
    float value
};                          //结构声明

struct book library;       //将library声明为一个使用book结构布局的结构变量


```

结构体内数组赋值必须用循环的方式