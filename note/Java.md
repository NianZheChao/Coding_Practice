# JAVA笔记

## 数组

### 数组声明

声明一个引用数组的变量，指明数组的元素类型。只是创建一个对数组的引用的存储位置，不分配空间。

```java
int [] Mylist;
```

### 创建数组

分配内存空间，将引用赋给一个变量。

```java
Mylist = new int[10];
```

### 同时声明与创建数组

```java
int [] mylist = new int[10]
```

### 数组初始化

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



## 方法

### 定义方法

修饰符   返回值类型   方法名（参数列表） { 

// 方法体； 

}

例如：

```java
public static int max(int m,int n){
	int result;
    if (m>n)
        result = m;
    else
        result = n;
    return result;
}
```

### 调用方法

- 调用本类中的静态方法（被static修饰）

  可以在其他方法中直接调用，如：

  ```java
  public static void main(String[] args){
  	int a = 1,b = 2;
  	int result = max(a,b);
  }
  ```

- 调用本类中的非静态方法（未被static修饰）

  通过类的实例化进行调用，如：

  ```java
   public static void main(String[] args) {
          int a=0;
          int b=a+1;
          int result=0;
              //Add方法调用
              //类的实例化
              HelloWorld helloworld=new HelloWorld();//此主类名为HelloWorld
              //通过实例化的类进行Add方法调用
              result=helloworld.Add(a, b);
  }
  ```

- 调用外部类的方法

  同样通过类的实例化进行调用，如：

  ```java
  //外部类
  public class Test {
      /**
       * 被调用方法Add
       * @param x 
       * @param y
       * @return
       */
      public int Add(int x,int y)
      {
          
          return x+y;
      }
      
      /**
       * 被调用方法Sub
       * @param x 
       * @param y
       * @return
       */
      public static int Sub(int x,int y)
      {
          
          return x-y;
      }
  }
  ```

  ```java
  //调用类
  public class HelloWorld {
  
      /**
       * @param args
       */
      public static void main(String[] args) {
          // TODO Auto-generated method stub
          String str="HelloWorld!";
          int a=5;
          int b=a+1;
          int result=0;
          
          for(int i=0;i<20;i++)
          {
              //Add方法调用
              //类的实例化
              Test test=new Test();
              
              //通过实例化的类进行Add方法调用
              result=test.Add(a, b);                        
              
              System.out.println(str+" "+ result);
              
              result=test.Sub(b, 1);                        
              
              System.out.println(str+" "+ result);
              
              a+=i;
              
          }
      }
      
  }
  ```