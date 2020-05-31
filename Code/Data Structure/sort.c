#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 10000

clock_t start,stop;
double duration;

int insertionSort(int array[],int n){  //直接插入排序
    int i,j;
    for(i = 2;i <= n;i++){
        array[0] = array[i];    //监视哨
        j = i-1;
        while(array[0]<array[j]){
            array[j+1]=array[j];
            j--;
        }
        array[j+1] = array[0];
    }
    return 0;
}

void bubbleSort (int arr[], int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (j=0; j<len-1-i; j++) { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (arr[j] > arr[j+1]) { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

void selectionSort(int array[],int length){
    int i,j,m;
    int temp;
    for(i = 0;i<length-1;i++){
        m = i;
        for(j = i+1;j<length;j++){
            if(array[j] < array[m])
                m = j;
            if(m != i){
                temp = array[i];
                array[i] = array[m];
                array[m] = temp;
            }
        }
    }
}

void quickSort(int a[],int n){
    int i,j;
    int pivot = a[0];	//设置基准值
    i = 0;
    j = n - 1;
    while(i < j){
        //大于基准值者保持在原位置
        while(i < j && a[j] > pivot){	j--;}
        if(i < j){
            a[i] = a[j];
            i++;
        }
        //不大于基准值者保持在原位置
        while(i < j && a[i] <= pivot){ 	i++;}
        if(i < j){
            a[j] = a[i];
            j--;
        }
    }
    a[i] = pivot;	//基准元素归位
    if(i > 1){
        //递归地对左子序列 进行快速排序
        quickSort(a,i);
    }
    if(n-i-1 > 1){
        quickSort(a+i+1,n-i-1);
    }
}

void shellSort(int R[],int n)
{
    int i,j,d;
    d = n/2;
    while(d >= 1)
    {
        //注意i的起始和最后的那个“=，我们的第一个数是R[1],所以i-d要从1开始
        for(i = d + 1;i <= n;i++)
        {
            j = i - d;
            //将R[i]暂存
            R[0] = R[i];
            //这边的R[0]就是R[j+d]也就是R[i]
            while(j>0 && R[j] > R[0])
            {
                //将j位置的值给j+d位置
                R[j+d] = R[j];
                j -= d;
            }
            //这边就是对应着上面的j-=d，如果上面的while执行了，j
            //位置的值已经给了j+d位置了，那么j+d的值也要给j位置，互换
            //这就要求下标必须是对应的。所以要将j-d才能满足这边是R[j]
            //如果while没有执行，那么还将原来的R[i]的值放到原来位置上
            R[j+d] = R[0];
        }
        //d减半
        d/=2;
    }
}

void HeapAdjust(int a[],int s,int m)//一次筛选的过程
{
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//通过循环沿较大的孩子结点向下筛选
    {
        if(j<m&&a[j]<a[j+1]) j++;//j为较大的记录的下标
        if(rc>a[j]) break;
        a[s]=a[j];s=j;
    }
    a[s]=rc;//插入
}
void heapSort(int a[],int n)
{
    int temp,i,j;
    for(i=n/2;i>0;i--)//通过循环初始化顶堆
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//将堆顶记录与未排序的最后一个记录交换
        HeapAdjust(a,1,i-1);//重新调整为顶堆
    }
}

void merge(int* arr, int start, int mid, int end)
{
    int len_l, len_r; //左右待合并区间的长度
    len_l = mid - start + 1;
    len_r = end - mid;
    int l[len_l], r[len_r]; //gcc, 两个临时数组，分别保存待合并的两个区间
    //int l[100], r[100]; //vc
    memcpy(l, arr + start, sizeof(int) * len_l);
    memcpy(r, arr + mid + 1, sizeof(int) * len_r);

    int i = 0, j = 0, k = start;
    while(i < len_l && j < len_r)
    {
        arr[k++] = l[i] < r[j] ? l[i++] : r[j++];
    }

    while(i < len_l)
    {
        arr[k++] = l[i++];
    }
}
/*
函数功能：归并排序
函数参数：
 arr: 待排序的数组
 start: 待排序数组开始下标
 end: 待排序数组结束下标
 */
void mergeSort(int* arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        //归
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        //并
        merge(arr, start, mid, end);
    }
}


int main() {
    FILE *fp1,*fp2;
    fp1 = fopen("preProcess.txt","w");
    fp2 = fopen("processed.txt","w");
    int preProcess[N];
    int processed[N];
    int i = 0;

    srand( (unsigned)time(NULL));
    printf("start initializing array\n");
    for(;i<N;i++){            //wait to sorted array
        preProcess[i] = rand();
    }

    i = 0;
    printf("start writing random array into file\n");
    for(;i<N;i++){
        fprintf(fp1,"%d\n",preProcess[i]);    //file waiting to sort
    }

    printf("\nsorting......\n\n");
    start = clock();
    int a = clock();

    //insertionSort(preProcess,N);

    //bubbleSort(preProcess,N);

    //quickSort(preProcess,N);

    //selectionSort(preProcess,N);

    //shellSort(preProcess,N);

    //heapSort(preProcess,N);

    //mergeSort(preProcess,0,N);

    int b = clock();
    stop = clock();
    duration = ((double)(stop - start)/CLOCKS_PER_SEC);

    printf("start writing sorted array into file\n");
    i = 0;
    for(;i<N;i++){
        fprintf(fp2,"%d\n",preProcess[i]);    //sorted file
    }

    //printf("function runs in %d ns.\n",duration);
    printf("sorting runs in %d ms.(windows method)",b-a);
}
