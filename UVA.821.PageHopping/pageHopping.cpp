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
            //mat[i][i] = 0;
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
int cont;
int mm[110];
int mapp(int n){
    if(mm[n]<0){
        mm[n] = cont++;
    }
    return mm[n];
}
int main(){
    string line;
    int o,d,c=1;
    int mat[110][110];
    int _map[110];
	while(getline(cin,line)){
	    cont = 0;
	    if(line == "0 0")return 0;

	    MEM(mat,-1);
	    MEM(mm,-1);

	    stringstream ss(line);
	    while(ss>>o>>d){
            if(!o && (o==d)){
                break;
            }
            mat[mapp(o)][mapp(d)] = 1;
	    }
	    fw(mat,cont);
	    UL total = 0;
	    for(int i = 0;i<cont;++i){
	        for(int j = 0;j<cont;++j){
	            if((i!=j) && mat[i][j]!=-1){
                    total+=mat[i][j];
	            }
	        }
	    }
	    double resp = double(total)/double(cont*(cont-1));
	    printf("Case %d: average length between pages = %.3lf clicks\n",c++,resp);
	}
	return 0;
}



