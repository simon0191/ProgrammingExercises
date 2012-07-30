#include<iostream>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>
#include <cctype>
using namespace std;

int f(string s){
    if(isdigit(s[0])){
        return s[0]-'0'-1;
    }
    switch (s[0]){
        case 'A':return 0;
        case 'T':return 9;
        case 'J':return 10;
        case 'Q':return 11;
        case 'K':return 12;
    }
}
void proc(vector<queue<string> >& vec){
    int col = 12,cont = 0;
    string act;
    do{
        ++cont;
        act = vec[col].front();
        vec[col].pop();

        col = f(act);
        if(vec[col].empty()){
            break;
        }
    }while(true);
    if(cont<10)printf("0");
    printf("%d,%s\n",cont,act.c_str());
}

int main(){
    char c;
    char buff[3];
    while(scanf("%s",buff) && buff[0]!='#'){
        vector< queue<string> > vec(13);
        vec[12].push(buff);
        for(int i = 0;i<4;++i){
            for(int j = 0;j<13;++j){
                if(i==0 && j == 0)continue;
                scanf("%s",buff);
                vec[12-j].push(buff);
            }
        }
        proc(vec);
    }
    return 0;
}

