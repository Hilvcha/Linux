#include<cstdio>
#include<cstring>
int code[8][1<<8];

using namespace std;


int inputCodeHead(int code[][1<<8]){
    memset(code,0,sizeof(code));
    int ch=0;
    for(int len = 0; len <= 8;len++){   
        for(int i=0;  i < 1<<len; i++)
        {
            ch=getchar();
            if(ch=='\n'){
                return 1;
            }else if (ch==EOF){
                return 0;
            }
            code[len][i]=ch;
        }
        
    }
}
int inputLen(int len){
    int n=0;
    for(int i = 0; i < len; i++)
    {
        n*=2;
        n+=getchar()-'0';
    }
    return n;
}
int main(int argc, char const *argv[])
{
    freopen("in","r",stdin);
    // shuru bian ma tou yingshe
    while(inputCodeHead(code)){
        int len,value;
        while((len=inputLen(3))!=0){
            while((value=inputLen(len))!=(1<<len-1)){
                putchar(code[len][value]);
            }
        }
        putchar('\n');
    }
    
    return 0;
}
