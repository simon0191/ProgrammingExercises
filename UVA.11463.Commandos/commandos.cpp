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

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

#define MEM(X,Y) memset(X,Y,sizeof(X))
#define MEM0(X) MEM(X,0)

#define INF 1000000000

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;
void fw(int mat[][110],int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            mat[i][i] = 0;
            for(int j=0; j<n; j++){
                if(i!=k && j!=k && mat[i][k]!=-1 && mat[k][j]!=-1){
                    int total = mat[i][k] + mat[k][j];
                    if(mat[i][j]==-1 || mat[i][j]>total){
                        mat[i][j]=total;
                    }
               }
            }
        }
    }
}
void debug(int mat[][110],int n){
    return;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            printf("|%2d",mat[i][j]);
        }
        puts("");
    }
}
int main(){
    int mat[110][110];
	int cases,n,m,o,d;
	scanf("%d",&cases);
	for(int c = 1;c<=cases;++c){
	    MEM(mat,-1);
	    scanf("%d %d",&n,&m);
	    for(int i = 0;i<m;++i){
	        scanf("%d %d",&o,&d);
	        mat[o][d] = mat[d][o] = 1;
	    }
	    scanf("%d %d",&o,&d);
	    fw(mat,n);
	    debug(mat,n);
	    int maxx = 0;
	    for(int i = 0;i<n;++i){
	        maxx = max(maxx,mat[o][i]+mat[i][d]);
	    }
	    printf("Case %d: %d\n",c,maxx);
	}
	return 0;
}



