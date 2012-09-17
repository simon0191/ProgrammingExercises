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

int dx[] = {-1,0,1, 0};
int dy[] = { 0,1,0,-1};
char LAND;
int flood(char mat[][32],bool visited[][32],int fils,int cols,int x,int y){
    if( !(x>=0 && x<fils && y>=0 && y<cols) )return 0;
    if(mat[x][y]!=LAND || visited[x][y])return 0;
    visited[x][y] = true;
    int cont = 1;
    for(int i = 0;i<4;++i){
        cont+=( flood(mat,visited,fils,cols, x+dx[i],(y+cols+dy[i])%cols ) );
    }
    return cont;
}

int main(){
	int fils,cols,ox,oy;
	char mat[32][32];
	bool visited[32][32];
	while(scanf("%d %d",&fils,&cols)==2){
	    memset(visited,false,sizeof(visited));
	    for(int i = 0;i<fils;++i){
	        scanf("%s",mat[i]);
	    }
	    scanf("%d %d",&ox,&oy);
	    LAND = mat[ox][oy];
	    flood(mat,visited,fils,cols,ox,oy);
        int maxx = 0;
        for(int i = 0;i<fils;++i){
            for(int j = 0;j<cols;++j){
                maxx = max(flood(mat,visited,fils,cols,i,j),maxx);
            }
        }
        printf("%d\n",maxx);
	}
	return 0;
}



