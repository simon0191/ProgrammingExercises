#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include <cctype>
using namespace std;




void proc(int mat[][32],int p[],int w[],int n){
    memset(mat,0,sizeof(mat));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=31;++j){
            mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            if(j - w[i] >= 0){
                mat[i][j] = max(mat[i][j],mat[i-1][j-w[i]]+p[i]);
            }
        }
    }
}
int main(){
    int cases,nObj,nPers,aux;
    scanf("%d",&cases);
    int mat[1001][32];
    int p[1005];
    int w[1005];
    while(cases--){
        scanf("%d",&nObj);
        for(int i = 1;i<=nObj;++i){
            scanf("%d %d",p+i,w+i);
        }
        proc(mat,p,w,nObj);
        scanf("%d",&nPers);
        //printf("-->%d\n",nPers);
        int cont = 0;
        for(int i =0 ;i<nPers;++i){
            scanf("%d",&aux);
            cont+=mat[nObj][aux];
        }
        printf("%d\n",cont);
    }

    return 0;
}
