//2DHieroglyphsDecoder-UVA-10851
#include <cstdio>
#include <cstring>
#include <cctype>

int B2[] = {1,2,4,8,16,32,64,128};
int func(char c){
    int resp = 0;
    for(int i = 0;i<8;++i){
        resp<<=1;
        resp+=( (c/B2[i])%2?1:0);
    }
    return resp;
}
int main(){
    char map[1000];
    for(int i = 0;i<200;++i){
        if(isprint(i)){
            map[func(i)] = i;
        }
    }
    int cases,cont;
    char buff[10][85];
    scanf("%d",&cases);
    while(cases--){
        for(int i = 0;i<10;++i){
            scanf("%s",buff[i]);
        }
        for(int j = 1;buff[0][j+1];++j){
            cont = 0;
            for(int i = 1;i<9;++i){
                cont<<=1;
                cont+=( (buff[i][j]=='\\')?1:0 );
            }
            printf("%c",map[cont]);
        }
        puts("");
    }
    return 0;
}
