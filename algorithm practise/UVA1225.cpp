#include<iostream>
//#include<map>
//#include<iomanip>
//#include<cstdio>
#include<cstring>
#include<cctype>
#include<typeinfo>
using namespace std;
int a[10]={0};
int deal(int num){
    if(num<10){
        a[num]++;
        return 0;
    }
    a[num%10]++;
    num/=10;
    return deal(num);
}
int main(){
   freopen("in","r",stdin);

    double sum=0;
    int flag=0,num_value=0,n=0;
    cin>>n;
    cin.ignore();
    while(n--){
        cin>>num_value;
        cin.ignore();;
        for (int i = 1; i <= num_value; i++){
            deal(i);
        }
        for(int i=0;i<9;i++){
            cout<<a[i]<<' ';
        }
        cout<<a[9]<<endl;
        memset(a,0,sizeof(a));
    }
    return 0;
}