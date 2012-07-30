#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>

using namespace std;


int prof(int mat[][105],int node,int n,int vec[]){
    if(vec[node] == -1){
        int maxx = 0;
        for(int i = 1;i<=n;++i){
            int sum = 0;
            if(mat[node][i]){
                ++sum;
                sum += prof(mat,i,n,vec);
            }
            maxx = max(sum,maxx);
        }
        vec[node] = maxx;
    }
    return vec[node];
}

int main(){
    int n,nDep,aux,maxx,nMaxx,sum;
    int graph[105][105];
    int vec[105];

    int cas = 0;
    while(scanf("%d",&n)==1 && n){
        memset(graph,0,sizeof(graph));
        memset(vec,-1,sizeof(vec));
        maxx = 0;
        nMaxx = 1;
        for(int i = 1;i<=n;++i){
            scanf("%d",&nDep);
            for(int j = 0;j<nDep;++j){
                scanf("%d",&aux);
                graph[i][aux] = 1;
            }
        }
        for(int i = 1;i<=n;++i){
            //memset(vec,-1,sizeof(vec));
            aux = prof(graph,i,n,vec);
            if(aux > maxx){
                maxx = aux;
                nMaxx = i;
            }
        }
        printf("%d\n",nMaxx);
        ++cas;
    }
    return 0;
}

