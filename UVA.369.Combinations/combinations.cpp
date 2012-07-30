#include <cstdio>
#include <cstring>

#define LL long long
int main(){
    LL mat[105][105];
    memset(mat,0,sizeof(mat));
    for(int i = 0;i<105;++i){
        mat[i][0] = 1;
    }
    for(int i = 1;i<105;++i){
        for(int j = 1;j<=i;++j){
            mat[i][j] = mat[i-1][j-1]+mat[i-1][j];
        }
    }
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n+m)){
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,mat[n][m]);
    }
    return 0;
}

