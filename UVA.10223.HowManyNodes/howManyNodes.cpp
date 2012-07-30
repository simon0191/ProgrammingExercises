#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>

#define LL long long
#define NN 105
using namespace std;

LL mat[NN][NN];

LL f(int n){
    return (1.0/double(n+1))*(mat[2*n][n]);
}
int main(){
    memset(mat,0,sizeof(mat));
    for(int i = 0;i<NN;++i){
        mat[i][0] = 1;
    }
    for(int i = 1;i<NN;++i){
        for(int j = 1;j<=i;++j){
            mat[i][j] = mat[i-1][j-1]+mat[i-1][j];
        }
    }
    vector<LL> trees;
    trees.push_back(0);
    for(int i = 0;trees[i]<=4294967295;++i){
        trees.push_back(f(i));
    }
    printf("%d\n",trees.size());
    int n,left,right,mid;
    while(scanf("%d",&n)==1){
        left = 0;
        right = trees.size()-1;
        while(trees[mid]!=n){
            mid = (left+right)/2;
            if(trees[mid]<n){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        printf("%d\n",mid-1);
    }
    return 0;
}

