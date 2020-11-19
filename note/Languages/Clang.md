# C语言学习笔记

## 循环

### while循环

```C
//while循环的炫酷写法
while(scanf("%d",&a)){   //节省时间开销可以写为 scanf("%d",&a) != EOF
    /**************/
    printf("%d",a);
}
//scanf与printf的返回值为其中的数据项数，即 % 的个数
```

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

```C
int i;
for(i=0;A[i]!='\0';i++){
}
//用C语言迭代char字符数组的方法
```

C语言把数组名当做一个不可变的指针来使用，当向函数传递一个类型为T的数组对象时，其实就等同于向函数传递一个指向类型为T的对象的指针。

## 指针

### 指针的本质

```c
//指针变量名为ptr
ptr = & pooh; //把pooh的地址赋给ptr指针，其中ptr是变量，pooh是常量
val = *ptr; //找出ptr指向的值

//以上两句相当于以下一句
val = pooh;

int *p;
*p = 1;
//使用这种方式对指针所指赋值时，仅仅是将指针所指向的值赋值，并没有对指针所指向的位置赋值，所以指针所指向的内存空间是随机的，此时无法print指针地址
int k = 1;
int *p;
p = &k;
//此时才可以输出指针所指向的固定地址
```

**后跟一个变量名时，& 给出该变量的地址。**

**后跟一个指针名或地址时，* 给出储存在指针指向地址上的值。**

**指针变量本身的本质就是地址。**

### 指针的声明

声明指针变量时必须指定指针所指向变量的类型。

### 字符串指针

```C
char *a = “abcd”; //此时"abcd"存放在常量区。通过指针只可以访问字符串常量，而不可以改变它。

char a[20] = “abcd”； //此时 "abcd"存放在栈。可以通过指针去访问和修改数组内容。
```

### 指针函数

指针函数就是返回指针值的函数，本质是一个函数，所以指针函数等价于**返回值为指针的函数**。

声明形式：type *func(参数列表)

```c++
#include <iostream>
using namespace std;


int *GetNum(int x); //指针函数声明形式


void main(void)
{
    cout << "===============start================" << endl;
    int num;
    cout << "Please enter the number between 0 and 6: ";
    cin >> num;
    cout << "result is:" << *GetNum(num) << endl;    //输出返回地址块中的值
    system("pause");
}

int *GetNum(int x) {
    static int num[] = { 0,1,2,3,4,5,6 };
    return &num[x];  //返回一个地址
}
```

用指针函数的方式返回数组

```C
//函数返回数组（返回数组指针）
int *solution(){
    int a[100];
    a[0] = 1;
    return a;
}

int main(){
    int *b;
    b = solution();
    printf("%d",a[0]);
}
//结果输出1
```



### 函数指针

函数指针就是一个指向函数的指针。每个函数在编译时，会被分配一个入口地址，一般用函数名来表示，这个地址就是该函数的指针。

声明形式：type (*func)(参数列表)

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

## 文件操作

FILE是一种结构类型

代码示例：

```C
FILE* fp = fopen("file","r");
//fp是一个指向FILE的指针
//FILE其实是一种结构，它代表我们所打开的文件中的信息
//fopen的参数为：1.文件名 2.r表示read
if(fp){   //判断fp指向的位置是否为NULL
    fscanf(fp,...);       //fscanf遇到空格和换行时结束
    fclose(fp,...);       //关闭文件
}
else{
    ...
}
```

MSDN中的示例：

```C
#include <stdio.h>
FILE *stream;
int main(void)
{
    long l;
    float fp;
    char s[81];
    char c;
    stream = fopen("fscanf.out", "w+");
    if(stream==NULL)
    printf("The file fscanf.out was not opened\n");
    else
    {
        fprintf(stream,"%s%ld%f%c","a-string", 65000,3.14159, 'x');
        /*将指针设置至文件开头*/
        fseek(stream,0L,SEEK_SET);
        /*从文件中读取数据*/
        fscanf(stream,"%s",s);
        fscanf(stream,"%ld",&l);
        fscanf(stream,"%f",&fp);
        fscanf(stream,"%c",&c);
       /*输出读取的数据*/
        printf("%s\n",s);
        printf("%ld\n",l);
        printf("%f\n",fp);
        printf("%c\n",c);
        fclose(stream);
    }
    return 0;
}//这样会有意外输出
```

fopen的参数说明：

`文件指针名=fopen（文件名,使用文件方式）;`

- r：打开只读
- r+：打开读写，从文件头开始
- w：打开只写，如果不存在则新建，如果存在则清空
- w+：打开读写，如果不存在则新建，如果存在则清空
- a：打开追加，如果不存在则新建，如果存在则从文件尾开始
- ..x：只新建，如果文件已存在则不能打开

fscanf的参数说明：

```C int fscanf(FILE * stream, const char * format, [argument...]); 
int fputs(const char *str, FILE *stream)
```

一般的使用方式示例：

```c
fscanf(fp,"%s%d%lf",a,&b,&c);
```

fputs的参数说明：

```c
int fputs(const char *str, FILE *stream)
```

fputs示例：

```c
int main ()
{
   FILE *fp;

   fp = fopen("file.txt", "w+");

   fputs("这是 C 语言。", fp);
   fputs("这是一种系统程序设计语言。", fp);

   fclose(fp);
   
   return(0);
}
```

fprintf的参数说明：

```c
int fprintf(FILE *stream, const char *format, ...)
```

fprintf示例：

```c
void initFile(){
    int i;
    int a = 0;
    FILE* fp = fopen("T.txt","w+");
    for(i=0;i<100;i++){
        fprintf(fp,"%d\n",a);
        printf("%d",a);
        a++;
    }
    fclose(fp);
}
```

