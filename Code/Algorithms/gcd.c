#include<stdio.h>

int min(int m, int n){
    if(m<n)
        return m;
    else
        return n;
}


int gcd(int m, int n){
    int t = min(m,n);
    while(t != 0){
        if(m % t == 0){
            if(n % t == 0){
                return t;
            }
            else{
                t--;
            }
        }
        else{
            t--;
        }
    }
}


int gcd2(int m, int n){
    int r;
    while(1){
        if(n == 0)
            return m;
        r = m % n;
        m = n;
        n = r;
    }
}

int gcd_jian(int m, int n){
    int t = n;
    if(m < n)
        t = m;
    int i;
    for(i = t;i >= 1;i--){
        if(m % i == 0 && n % i == 0)
            break;
    }
    return i;
}


int main(){
    //int i = gcd(60,24);
    printf("%d",i);
    return 0;
}


/*
int gcd_count(int m, int n){
    int r,count = 0;
    while(n!=0){

        r = m % n;
        m = n;
        n = r;
        count++;
    }
    return count;
}


int main(){
    int m,n;
    int maxCount = 0;
    for(m = 1;m<=10;m++){
        for(n = m + 1;n <= 10;n++){

            int count = gcd_count(m,n);
            if(maxCount<count)
                maxCount = count;
        }
    }
    printf("%d",maxCount);
    return 0;
}
*/



/*
int main(){
    int m;
    int n = 9;
    clock_t start1,finish1;
    start1 = clock();
    for(m = 10;m < 1000000; m++){
        int i = gcd(m,n);
    }
    finish1 = clock();
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    clock_t start2,finish2;
    start2 = clock();
    for(m = 10;m < 1000000; m++){
        int i = gcd2(m,n);
    }
    finish2 = clock();
    double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
    clock_t start3,finish3;
    start3 = clock();
    for(m = 10;m < 1000000; m++){
        int i = gcd_jian(m,n);
    }
    finish3 = clock();
    double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
    //int i = gcd_jian(60,24);
    printf("连续整数检测法：%fms\n欧几里得法：%fms\n欧几里得减法：%fms",duration1,duration2,duration3);
    return 0;
}
*/
