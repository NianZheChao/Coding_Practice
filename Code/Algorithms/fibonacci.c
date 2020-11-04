#include <stdio.h>
#include <time.h>

int fibonacci(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n - 2);
}

int main(){
    int i;
    for(i = 0;i < 50;i++){
        //clock_t start,finish;
        const double start = clock();
        int t = fibonacci(i);
        const double finish = clock();
        printf("F(%d)的运行时间为：%fms\n",i,(finish - start));
    }
    return 0;
}
