#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n,aux;
    int vec[5] = {1,5,10,25,50};
    int mat[5][7500];
    for(int i = 0;i<7490;++i){
        mat[0][i] = 1;
    }
    for(int i = 0;i<5;++i){
        mat[i][0] = 1;
    }
    for(int i = 1;i<5;++i){
        for(int j = 1;j<7490;++j){
            aux = j/vec[i];
            mat[i][j] = mat[i-1][j];
            for(int k = 1;k<=aux;++k){
                if(j-(k*vec[i])>=0){
                    mat[i][j]+=mat[i-1][j-k*vec[i]];
                }
            }
        }
    }
    while(scanf("%d",&n)==1){
        printf("%d\n",mat[4][n]);
    }
    return 0;
}
