#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
struct SS{
    int hamburguesas;
    int residuo;
    SS(){}
    SS(int h,int r):residuo(r),hamburguesas(h){}
};
int main(){
    int m,n,t,respx,respy,res,aux;
    SS mat[2][10001];
    while(scanf("%d%d%d",&m,&n,&t)==3){
        if(m<n)swap(m,n);
        memset(mat,0,sizeof(mat));
        for(int i = 1;i<=t;++i){
            mat[0][i] = SS(i/m,i%m);
        }
        for(int i=1;i<=t;++i){
            aux = i-n;
            if(aux >= 0){
                if(mat[0][i].residuo < mat[1][aux].residuo){
                    mat[1][i] = mat[0][i];
                }else if(mat[0][i].residuo > mat[1][aux].residuo){
                    mat[1][i] = mat[1][aux];
                    mat[1][i].hamburguesas++;
                }else if(mat[0][i].hamburguesas > mat[1][aux].hamburguesas+1){
                    mat[1][aux] = mat[0][i];
                }else{
                    mat[1][i] = mat[1][aux];
                    mat[1][i].hamburguesas++;
                }
            }else{
                mat[1][i] = mat[0][i];
            }
        }
        printf("%d",mat[1][t].hamburguesas);
        if(mat[1][t].residuo > 0){
            printf(" %d",mat[1][t].residuo);
        }
        printf("\n");
    }
    return 0;
}
