#include <cstdio>
#include <cstring>
const int N_LETTERS = 'z'-'a'+1;

int main(){
    int round,cont,strokes,act;
    char solution[1024],guesses[1024];
    bool marks[N_LETTERS],marks2[N_LETTERS];
    bool won,lose;
    while(scanf("%d",&round) && round!=-1){
        scanf("%s %s",solution,guesses);
        won = lose = false;
        cont = strokes = 0;
        memset(marks,false,sizeof(marks));
        memset(marks2,false,sizeof(marks2));
        for(int i = 0;solution[i];++i){
            act = solution[i]-'a';
            if(!marks[act]){
                marks[act] = true;
                ++cont;
            }
        }
        for(int i = 0;guesses[i] && !lose && !won;++i){
            act = guesses[i]-'a';
            if(marks[act] && !marks2[act]){
                cont--;
            }else if(!marks[act] && !marks2[act]){
                strokes++;
            }
            if(strokes == 7){
                lose = true;
            }else if(cont == 0){
                won = true;
            }
            marks2[act] = true;
        }
        printf("Round %d\n",round);
        if(won){
            puts("You win.");
        }else if(lose){
            puts("You lose.");
        }else{
            puts("You chickened out.");
        }
    }
    return 0;
}
