#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    vector<int> marble;
    vector<int>::iterator it;
    int n,q,num,case1=1;
    while(cin>>n>>q&&n){
        marble.clear();  
        cout<<"CASE# "<<case1++<<':'<<endl;
        for(int i=0;i<n;i++){
            cin>>num;
            marble.push_back(num);
        }
        sort(marble.begin(),marble.end());
        for(int i=0;i<q;i++){
            num=0;
            cin>>num;
            int p=lower_bound(marble.begin(),marble.end(),num)-marble.begin();
            if(marble[p]==num){
                cout<<num<<" found at "<<p+1<<endl;
            }else{
                cout<<num<<" not found"<<endl;
            }
        }
    }
    return 0;
}


