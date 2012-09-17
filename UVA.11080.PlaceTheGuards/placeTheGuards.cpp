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

void dfs(vector<vector<int> >& graph,int x,vector<int>& color,int actColor,bool& bicolorable,int& black,int &white){
    color[x] = actColor;
    if(actColor == BLACK)++black;
    else ++white;

    for( int i = 0;i<graph[x].size();++i ){
        if(color[graph[x][i]] == UNDEF){
            dfs(graph,graph[x][i],color, (actColor==WHITE)?BLACK:WHITE,bicolorable,black,white);
        }
        else if(color[graph[x][i]] == actColor){
            bicolorable = false;
            return;
        }
    }
}

int main(){
    int n,o,d,cases,ars;
    scanf("%d",&cases);
	while(cases--){
	    scanf("%d %d",&n,&ars);
	    vector<vector<int> >  graph(n);
	    for(int i = 0;i<ars;++i){
	        scanf("%d %d",&o,&d);
	        if(o!=d){
                graph[o].push_back(d);
                graph[d].push_back(o);
	        }
	    }

	    bool bicolorable = true;
	    int black = 0;
	    int white = 0;
	    int alone = 0;
	    int minn = 0;
	    vector<int> color(n,UNDEF);
	    for(int i = 0;i<n && bicolorable;++i){
	        if(graph[i].empty())++alone;
	        else if( color[i]==UNDEF ){
	            black = white = 0;
	            dfs(graph,i,color,WHITE,bicolorable,black,white);
	            minn += min(black,white);
	        }
	    }
	    if(bicolorable){
	        printf("%d\n",minn+alone);
	    }
	    else{
	        printf("-1\n");
	    }
	}
	return 0;
}



