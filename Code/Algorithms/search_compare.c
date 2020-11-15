#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define maxSize 500000
#define timesRecord 100

int seq_Search(int a[],int num,int k){
    int i;
    int times = 0;
    for (i = 0;i <= num;i++) {
        times++;
        if(a[i] == k) {
            return times;
        }
    }
    return times;
}

int bin_Search(int a[],int num,int k){
    int low = 0,high = num - 1,mid,times = 0;
    while (low <= high){
        times++;
        if(a[low] == k)
            return times;
        else if(a[high] == k)
            return times;
        mid = low + (high - low) / 2;
        if(a[mid] == k)
            return times;
        else if(a[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return times;
}

int main(){
    int i,j,k;
    int sum = 0;
    int a[maxSize],T[timesRecord];

    srand((unsigned)time(NULL));

    for (i = 0;i < maxSize;i++){
        a[i] = i;
    }

    for(j=0;j<timesRecord;j++){
        k = (int)(round(1.0 * rand() / RAND_MAX * maxSize));
        T[j] = bin_Search(a,maxSize,k);
        sum = sum + T[j];
    }
    printf("进行%d次二分查找，得到平均基本操作次数为：%d(其查找空间为%d)\n",timesRecord,sum/timesRecord,maxSize);
    sum = 0;
    for(j=0;j<timesRecord;j++){
        k = (int)(round(1.0 * rand() / RAND_MAX * maxSize));
        T[j] = seq_Search(a,maxSize,k);
        sum = sum + T[j];
    }
    printf("进行%d次顺序查找，得到平均基本操作次数为：%d(其查找空间为%d)\n",timesRecord,sum/timesRecord,maxSize);
    return 0;
}
