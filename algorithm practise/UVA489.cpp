#include<cstdio>
#include<cstring>

using namespace std;
const int MAX=100;
int win,lose,chance;
char word[MAX],guessw[MAX];
void guess(char ch){
    int findflag=0,spaceflag=1;
    for (size_t i = 0; i < strlen(word); i++){
        if(ch==word[i]){
            word[i]=' ';
            findflag=1;
        }else if(word[i]==' '){
            continue;
        }else{
            spaceflag=0;
        }
    }
    if(!findflag){
        chance--;
    }
    if(spaceflag){
        win=1;
    }
    if(chance==0){
        lose=1;
    }
    
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int n=0;
    while((scanf("%d%s%s",&n,word,guessw)==3)&&n!=-1){
        win=lose=0;
        chance=7;
        for(int i = 0; i < strlen(guessw); i++){
            guess(guessw[i]);
            if(win||lose){
                break;
            }
        }
        printf("Round %d\n",n);
        if(win){
            printf("You win.\n");
        }else if (lose){
            printf("You lose.\n");
        }else if (!win&&!lose){
            printf("You chickened out.\n",chance);
        }else{
            printf("error!\n");
        }
    }
    return 0;
}
