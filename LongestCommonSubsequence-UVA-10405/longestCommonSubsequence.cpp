#include <cstdio>
#include <iostream>
using namespace std;
char s1[1024],s2[1024];
int mat[10024][10024];
int lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    for(int i = 0; i <=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0 || j==0)
                mat[i][j] = 0;
            else if(s1[i-1] == s2[j-1]){
                mat[i][j] = mat[i-1][j-1]+1;
            }
            else{
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
            }
        }
    }
    return mat[m][n];
}
int main(){

    while(gets(s1) && gets(s2)){
        printf("%d\n",lcs(s1,s2));
    }
}
