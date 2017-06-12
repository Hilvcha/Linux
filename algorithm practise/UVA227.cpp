#include<iostream>
#include<cctype>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main(){
    freopen("in","r",stdin);

    char c=0;
    int n=0,i=0,sum=0,cnt=1;
    char puzzle[5][6]={0};
    string ori;
    while(1){
        memset(puzzle,0,sizeof(puzzle));

        ori.clear();
        cin.getline(puzzle[0],6);
      //  cout<<puzzle[0]<<endl;
        //cin.ignore();
        if(puzzle[0][0]=='Z'){
            break;
        }
        for(int i=1;i<=4;i++){
            cin.getline(puzzle[i],6);
        }
        char c;
        while((c=cin.get())!='0'){
        if(c==' '||c=='\n'){
            continue;
        }
        ori+=c;
        }
        cin.ignore();
        cout<<"Puzzle #"<<cnt++<<endl;
        for(size_t j=0;j<=4;j++){

            cout<<puzzle[j]<<endl;
                    }
        cout<<ori<<endl;
        if(cnt==7){break;}
    //     for(auto c:ori){
    //         if(isalpha(c)){
    //             if(isfaild(puzzle[][6],c)){
    //                 cout<<"Puzzle #"<<cnt<<endl;
    //                 cout<<"This puzzle has no final configuration."<<endl;
    //             }else{
    //                 operat(puzzle[][6],c);
    //                 cout<<"Puzzle #"<<cnt<<endl;
    //                 for(size_t j=0;j!=5;j++){
    //                     cout<<&puzzle[j]<<endl;
    //                 }
    //             }
    //         }
    //     }
    // cout<<sum<<endl;
    // sum=cnt=0;
    }
    return 0;
}