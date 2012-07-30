#include <cstdio>
#include <iostream>
#include <cstring>
#define IGNORE -1
using namespace std;
struct V2d{
    int x,y;
    V2d(){x=y=0;};
    V2d(int _x,int _y):x(_x),y(_y){}
};
int cTi(char c){
    switch (c){
        case 'N':return 0;
        case 'E':return 1;
        case 'S':return 2;
        case 'W':return 3;
    }
}
int main(){
    char ID[] = {'N','E','S','W'};
    V2d DIR[] = {V2d(0,1),V2d(1,0),V2d(0,-1),V2d(-1,0)};

    int limX,limY,x,y,mat[60][60],dir;
    char d,str[105];
    bool lost;

    memset(mat,0,sizeof(mat));
    cin>>limX>>limY;
    while(cin>>x>>y>>d>>str){
        dir = cTi(d);
        lost = false;
        for(int i = 0;str[i] && !lost;++i){
            switch (str[i]){
                case 'R':{
                    ++dir;
                    if(dir > 3)dir = 0;
                }break;
                case 'L':{
                    --dir;
                    if(dir < 0)dir = 3;
                }break;
                case 'F':{
                    if(mat[x][y] == IGNORE && (x+DIR[dir].x<0 || x+DIR[dir].x>limX ||  y+DIR[dir].y<0 || y+DIR[dir].y>limY)){
                    }
                    else if((x+DIR[dir].x<0 || x+DIR[dir].x>limX ||  y+DIR[dir].y<0 || y+DIR[dir].y>limY)){
                        lost = true;
                        mat[x][y] = IGNORE;
                    }
                    else{
                        x+=DIR[dir].x;
                        y+=DIR[dir].y;
                    }
                }break;
            }
        }
        printf("%d %d %c",x,y,ID[dir]);
        if(lost)printf(" LOST");
        printf("\n");
    }
    return 0;
}
