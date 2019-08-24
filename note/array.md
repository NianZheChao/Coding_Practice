- 数组声明

  声明一个引用数组的变量，指明数组的元素类型。只是创建一个对数组的引用的存储位置，不分配空间。

  ```java
  int [] Mylist;
  ```

- 创建数组

  分配内存空间，将引用赋给一个变量。
  
  ```java
  Mylist = new int[10];
  ```
  
- 同时声明与创建数组

  ```java
  int [] mylist = new int[10]
  ```

- 数组初始化

  ```java
  int[] mylist = {1,2,3,4,5,6}; //声明，创建，并初始化
  ```

  或

  ```java
  int[] mylist = new int[4];
  mylist[0] = 1;
  mylist[1] = 1;
  mylist[2] = 1;
  mylist[3] = 1;
  ```

  
