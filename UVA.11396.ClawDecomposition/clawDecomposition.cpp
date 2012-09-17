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

#define UNDEF 0
#define WHITE 1
#define BLACK 2

void dfs(vector<vector<int> >& graph,int x,vector<int>& color,int actColor,bool& bicolorable){
    color[x] = actColor;
    for( int i = 0;i<graph[x].size();++i ){
        if(color[graph[x][i]] == UNDEF){
            dfs(graph,graph[x][i],color, (actColor==WHITE)?BLACK:WHITE,bicolorable );
        }
        else if(color[graph[x][i]] == actColor){
            bicolorable = false;
            return;
        }
    }
}

int main(){
    int n,o,d;
	while(scanf("%d",&n)==1 && n){
	    vector<vector<int> >  graph(n);
	    while(scanf("%d %d",&o,&d) && (o+d)){
	        graph[o-1].push_back(d-1);
	        graph[d-1].push_back(o-1);
	    }
	    bool bicolorable = true;
	    vector<int> color(n,UNDEF);
	    for(int i = 0;i<n && bicolorable;++i){
	        if( color[i]==UNDEF ){
	            dfs(graph,i,color,WHITE,bicolorable);
	        }
	    }
	    puts(bicolorable?"YES":"NO");
	}
	return 0;
}



