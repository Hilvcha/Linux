#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
bool is_period(string &line,int period){
    for(int p=0;p<period;p++){
        for(int i=p;i<line.length();i+=period){
            if(line[p]!=line[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
   // freopen("in","r",stdin);

    char c=0;
    int n=0,flag=0,sum=0,cnt=0;
    cin>>n;
    cin.ignore();
    string line;
    while(n--){
        cin.ignore();
        getline(cin,line);
        flag=1;
        for(int i=1;i<line.length()/2+1;i++){
            if(line.length()%i!=0){
                continue;
            }else if(is_period(line,i)){
                cout<<i<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<line.length()<<endl;
        }
        if(n){
            cout<<endl;
        }
    }
    return 0;
}