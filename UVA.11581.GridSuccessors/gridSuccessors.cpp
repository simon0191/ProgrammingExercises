#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

int f(char mat[][6],char res[][6],int lev = 0){
    bool flag = false;
    for(int i = 1;i<=3;++i){
        for(int j = 1;j<=3;++j){
            res[i][j] = ((mat[i][j+1]+mat[i][j-1]+mat[i+1][j]+mat[i-1][j])%2);
            if(mat[i][j])flag = true;
        }
    }
    if(!flag)return lev-1;
    return f(res,mat,lev+1);
}
int main(){
    int cases;
    char mat[6][6];
    char res[6][6];
	scanf("%d",&cases);
	while(cases--){
	    memset(mat,0,sizeof(mat));
	    memset(res,0,sizeof(res));
	    bool flag = false;
	    for(int i = 1;i<=3;++i){
            scanf("%s",mat[i]+1);
            for(int j=1;j<=3;++j){
                mat[i][j] = ((mat[i][j]=='1')?1:0);
                if(mat[i][j])flag = true;
                //printf("%d .. ",mat[i][j]);
            }
	    }
	    if(flag){
	        printf("%d\n",f(mat,res) );
	    }
	    else{
	        puts("-1");
	    }
	}
	return 0;
}



