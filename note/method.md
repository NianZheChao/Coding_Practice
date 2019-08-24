- 定义方法

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

- 调用方法

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

    
