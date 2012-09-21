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
void fw(int mat[][AZ_SIZE],int n){
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
void debug(int mat[][AZ_SIZE],int n){
    return;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            printf("|%2d",mat[i][j]);
        }
        puts("");
    }
}
int main(){
    int gy[AZ_SIZE][AZ_SIZE];
    int gm[AZ_SIZE][AZ_SIZE];
    char g[5],dir[5],o[5],d[5];
    int cost;
    int m;
    int ori,dest;
    while(scanf("%d",&m)==1 && m){
        MEM(gy,-1);
        MEM(gm,-1);
        for(int i = 0;i<m;++i){
            scanf("%1s %1s %1s %1s %d",g,dir,o,d,&cost);
            ori = o[0]-'A';
            dest = d[0]-'A';
            if(g[0]=='Y'){
                //gy;
                gy[ori][dest] = cost;
                if(dir[0]=='B'){
                    gy[dest][ori] = cost;
                }
            }
            else{
                //gm
                gm[ori][dest] = cost;
                if(dir[0]=='B'){
                    gm[dest][ori] = cost;
                }
            }
        }
        scanf("%1s %1s",o,d);
        fw(gy,AZ_SIZE);
        fw(gm,AZ_SIZE);
        map<int,vector<char> > mapa;
        for(int i = 0;i<AZ_SIZE;++i){
            if((gy[ o[0]-'A' ][i]!=-1) && (gm[ d[0]-'A' ][i]!=-1)){
                mapa[ gy[ o[0]-'A' ][i]+gm[ d[0]-'A' ][i] ].push_back(i+'A');
            }
        }
        if(mapa.empty()){
            puts("You will never meet.");
        }
        else{
            printf("%d",mapa.begin()->first);
            for(int i = 0;i<(mapa.begin()->second).size();++i){
                printf(" %c",(mapa.begin()->second)[i]);
            }
            puts("");
        }
    }

	return 0;
}


