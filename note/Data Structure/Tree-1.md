## 树

客观世界中许多事物存在层次关系；分层次组织在管理上具有更高的效率。

### 引子：查找

查找：给定某个给定关键字K，从集合R中找出关键字与K相同的记录

静态查找：集合中的记录是固定的；动态查找：集合中记录是动态变化的（除查找还可能发生插入和删除）。

#### 静态查找的方法

- 顺序查找

  ```c
  int SequentialSearch(List Tbl ,ElementType K){
      int i;
      Tbl->Element[0] = K;                              //建立哨兵
      for(i = Tbl->Length; i>0 && Tbl->Element[i] != K; i--);
      return i;
  }
  ```

-  二分查找（Binary Search）

  要求：N个数据元素的关键字有序存放在一个数组里

  ```c
  int BinarySearch(List Tbl ,ElementType K){
      int left,right,mid,NoFound = -1;
      
      left = 1;
      right = Tbl -> Length;
      while(left <= right){
          mid = (left + right)/2;
          if(K < Tbl -> Element[mid])
              right = mid - 1;                   //调整右边界
          else if(K > Tbl -> ELement[mid])
              left = mid + 1;                    //调整左边界
          else
              return mid;
      }
      return NotFound;
  }
  
  //T=O(logN)
  ```

### 树的定义

树（Tree）：n(n>=0)个结点构成的有限集合。当n=0时，称为空树；对于任一棵非空树（n>0），它具备以下性质：

- 树中有一个称为根（root）的特殊结点，用"r"表示；
- 其余结点可分为m个互不相交的有限集T1,T2,...，Tm，其余每个集合本身又是一棵树，称为原来树的“子树（SubTree）”

树的基本术语：

- 结点的度（Degree）：结点的子树个数。
- 树的度：树的所有结点中最大的度数。
- 叶结点：度为0的结点。
- 父结点：有子树的结点是其子树的根结点的父结点。

