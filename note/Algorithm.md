# 算法笔记

### 不多于3n/2的平均比较次数

设计一个算法：用不多于3n/2的平均比较次数，在数组A[1,...,n]中找出最大值和最小值的元素

算法分析：在这个函数中，最坏的情况是第一个if均不成立，则比较次数为`2(n-1)`，最好情况下第一个if一直成立，则比较次数为`n-1`，则平均比较次数为`[2(n-1)+n-1] = 3n/2 - 3/2<=3n/2`

```	C
    void maxmin(int A[],int n)
    {
        int i;
        int max,min;
        max=A[1];
        min=A[1];
        for(i=2;i<=n;i++)
        {
            if(A[i]>max)
                max=A[i];
            else if(A[i]<min)
                min=A[i];
        }
        cout<<max<<endl;
        cout<<min<<endl;
    }
```

