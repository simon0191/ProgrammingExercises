#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

#define Coord pair<int,int>
#define BORDER -1

using namespace std;

Coord neighbors[6] = {Coord(-1,-1),Coord(-1 ,0),Coord(0,-1),Coord(0,1),Coord(1,0),Coord(1,1)};

bool bt(int x,int y,char mat[][205],int N){
    if(y == N)return true;
    mat[x][y] = BORDER;
    for(int j=0;j<6;++j){
        if(mat[x+neighbors[j].first][y+neighbors[j].second] != BORDER &&
           mat[x+neighbors[j].first][y+neighbors[j].second] == 'w' &&
           bt(x+neighbors[j].first,y+neighbors[j].second,mat,N)){
               return true;
        }
    }
    return false;
}

int main(){
    char mat[205][205];
    int n,nGame = 1;
    bool wWin;

    memset(mat,BORDER,sizeof(mat));
    while(scanf("%d",&n) && n){
        wWin = false;
        for(int i = 1;i<=n;++i){
            scanf("%s",mat[i]+1);
            mat[i][n+1] = BORDER;
            mat[n+1][i] = BORDER;
        }
        mat[n+1][n+1] = BORDER;

        for(int i = 1;i<=n && !wWin;++i){
            if(mat[i][1] == 'w' && bt(i,1,mat,n)){
                wWin = true;
            }
        }
        if(wWin){
            printf("%d W\n",nGame++);
        }else{
            printf("%d B\n",nGame++);
        }

    }
    return 0;
}
