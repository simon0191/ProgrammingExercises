#include <cstdio>
#include <climits>
#include <queue>
#include <set>
using namespace std;
int main(){
    int m,n,pos,resp,pos_resp;
    int mat[15][105],costs[15][105],path[15][105];
    while(scanf("%d%d",&m,&n)==2){
        resp = INT_MAX;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                scanf("%d",mat[i]+j);
            }
            costs[i][n-1] = mat[i][n-1];
        }
        for(int j = n-2;j>=0;--j){
            for(int i = 0;i<m;++i){
                costs[i][j] = INT_MAX;
                set<int> sete;
                for(int k = 1;k>=-1;--k){
                    pos = i+k;
                    if(pos < 0){
                        pos = m-1;
                    }
                    pos%=m;
                    sete.insert(pos);
                }
                set<int>::iterator it;
                for(it=sete.begin();it!=sete.end();++it){
                    if(costs[i][j]>costs[*it][j+1]+mat[i][j]){
                        costs[i][j] = costs[*it][j+1]+mat[i][j];
                        path[i][j] = *it;
                    }
                }
            }
        }
        for(int i = 0;i<m;++i){
            if(costs[i][0]<resp){
                resp = costs[i][0];
                pos_resp = i;
            }
        }
        //printf("%d ",pos_resp);
        int aux = pos_resp;
        for(int j=0;j<n-1;j++){
            printf("%d ",aux+1);
            aux = path[aux][j];
        }
        printf("%d\n%d\n",aux+1,resp);
    }
    return 0;
}
