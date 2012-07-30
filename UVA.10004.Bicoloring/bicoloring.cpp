#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#define A -1
#define B -2
#define UNDEF 0
using namespace std;
bool mark(int mat[][201],int node,int sex,int sexs[],int nNodes,int cas){
    if(sexs[node] == UNDEF){
        sexs[node] = sex;
        sex = (sex==A?B:A);
        for(int i = 0;i<nNodes;++i){
            if(i!= node && mat[node][i]==cas){
                if(!mark(mat,i,sex,sexs,nNodes,cas)){
                    return false;
                }
            }
        }
    }
    else if(sexs[node] != sex){
        return false;
    }
    return true;
}
int main(){
    int nNodes,nEdges,a,b;
    int mat[201][201];
    int sexs[201];
    int cas = 0;
    memset(mat,0,sizeof(mat));
    while(scanf("%d",&nNodes) && nNodes){
        ++cas;
        scanf("%d",&nEdges);
        for(int i = 0;i<nEdges;++i){
            scanf("%d%d",&a,&b);
            mat[a][b] = mat[b][a] = cas;
        }
        int sex = A;
        bool band = true;
        memset(sexs,UNDEF,sizeof(sexs));
        for(int i = 0;i<nNodes && band;++i){
            if(sexs[i] != UNDEF){
                sex = sexs[i];
            }
            if(!mark(mat,i,sex,sexs,nNodes,cas)){
                band = false;
            }
        }
        if(band){
            puts("BICOLORABLE.");
        }
        else{
            puts("NOT BICOLORABLE.");
        }
    }
    return 0;
}
