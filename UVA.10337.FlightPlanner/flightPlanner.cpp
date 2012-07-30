#include <vector>
#include <climits>
#include <cstring>
#include <queue>
#include <cstdio>

#define WALL 100
#define UP -1
#define DOWN 1
#define HOLD 0

using namespace std;

long costs[15][1005];

int dp(long graph[][1005],int cols){
    memset(costs,100,sizeof(costs));
    costs[10][1] = 0;
    for(int j = 2;j<=cols;++j){
        for(int i = 9;i>=1;--i){
            costs[i][j] = min(30-graph[i][j-1] + costs[i][j-1],
                              min(20-graph[i-1][j-1]+costs[i-1][j-1],
                                  60-graph[i+1][j-1]+costs[i+1][j-1]
                                  )
                              );
        }
    }
    return 20+costs[9][cols]-graph[9][cols];
}

int main(){
    int cases,cols,ans,aux;
    long mat[15][1005];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&cols);
        cols/=100;
        memset(mat,0,sizeof(mat));
        for(int i = 1;i<=10;++i){
            for(int j = 1;j<=cols;++j){
                scanf("%d",&aux);
                mat[i][j] = aux;
            }
        }
        printf("%d\n\n",dp(mat,cols));
    }
    return 0;
}

