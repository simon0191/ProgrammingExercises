#include <iostream>
using namespace std;
int mat[105][105];
int lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    for(int i = 0; i <=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0 || j==0)
                mat[i][j] = 0;
            else
            if(s1[i-1] == s2[j-1]){
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
    int d = 1,K;
    string str2,str1;
    while(getline(cin,str1) && str1!="#"){
        getline(cin,str2);
        K = lcs(str1,str2);
        cout<<"Case #"<<d++<<": you can visit at most "<<K<<" cities."<<endl;
    }
    return 0;
}
