#include<stdio.h>
int main(){
    long long num=0;
    for(long long i=10000000000;i<=10000000000000;i*=10){
        num=i%21;
        if(num==1){
            int count=0;
            while(i){
                i/=10;
                count++;
            }
            printf("%d",count);
        }
    }
    return 0;
}