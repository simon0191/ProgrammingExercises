#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;

void floyd(int mat[][21]){
    int n = 20;
    for(int k=1; k<=n; k++)
           for(int i=1; i<=n; i++)
               for(int j=1; j<=n; j++)
                   if(i!=k && j!=k && mat[i][k]!=-1 && mat[k][j]!=-1)
                   {
                   	int total = mat[i][k] + mat[k][j];
                   	if(mat[i][j]==-1 || mat[i][j]>total)
                       	mat[i][j]=total;
                   }
}
int main(){
    int nCon,aux,cases;
    int graph[21][21];
    int cas = 1,o,d;
    while(true){

        memset(graph,-1,sizeof(graph));
        graph[20][20] = 0;
        for(int i = 1;i<=19;++i){
            graph[i][i] = 0;
            if(scanf("%d",&nCon)==1){
                if(i==1){
                    printf("Test Set #%d\n",cas++);
                }
                for(int j = 1;j<=nCon;++j){
                    scanf("%d",&aux);
                    graph[i][aux] = 1;
                    graph[aux][i] = 1;
                }
            }
            else{
                return 0;
            }
        }
        floyd(graph);
        scanf("%d",&cases);
        for(int j = 0;j<cases;++j){
            scanf("%d%d",&o,&d);
            printf("%2d to %2d: %d\n",o,d,graph[o][d]);
        }
        puts("");
    }
   return 0;
}
