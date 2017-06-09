#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
  //  freopen("in","r",stdin);

    char c=0;
    int n=0,i=0,sum=0,cnt=0;
    cin>>n;
    getchar();
    string line;
    while(n--){
        getline(cin,line);

        for(auto &c:line){
            if(c=='O'){
                sum+=++cnt;
            }else if(c=='X'){
                cnt=0;
            }
        }
    cout<<sum<<endl;
    sum=cnt=0;
    }
    return 0;
}