#include<iostream>
#include<map>
#include<iomanip>
//#include<cstdio>
#include<string>
#include<cctype>
#include<typeinfo>
using namespace std;
int main(){
   //freopen("in","r",stdin);

    char c=0,temp=0;
    map<char,double>table={
        {'C',12.01},  {'H',1.008},
        {'O',16.00},  {'N',14.01}
    };
    double sum=0;
    int flag=0,num_value=0,n=0;
    cin>>n;
    cin.ignore();
    while(n--){
        cin.get(c);
        temp=c;
        flag=1;
        while(cin.get(c)){
            if(c=='\n'||c==EOF){
                if(flag==1){
                    sum+=table[temp];
                    flag=0;
                }
                break;
            }else if(isdigit(c)){
                cin.putback(c);
                cin>>num_value;                
                sum+=table[temp]*num_value;
                flag=0;
            }else{          //字符
                if(flag==1){
                    sum+=table[temp];
                    temp=c;
                    flag=1;
                }else{
                    temp=c;
                    flag=1;
                }
            }
        }
        cout.setf(ios::fixed);
        cout<<setprecision(3)<<sum<<endl;
        sum=0;
    }
    return 0;
}