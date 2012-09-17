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

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;
int visited[100010];
int visited2[100010];
int inis[100010];
int mark1 = 1;
int mark2 = 1;

void dfs(vector<vi>& graph,int x){
    visited[x] = mark1;
    visited2[x] = mark2;

    for( int i = 0;i<graph[x].size();++i ){
        if(visited2[graph[x][i]] != mark2){
            dfs(graph,graph[x][i]);
            if(inis[graph[x][i]] == mark1){
                inis[graph[x][i]] = 0;
            }
        }
    }
}

int main(){
	int cases,n,arcs,o,d;

	memset(visited,0,sizeof(visited));
	memset(visited2,0,sizeof(visited2));
    memset(inis,0,sizeof(visited));

	scanf("%d",&cases);
	while(cases--){
	    scanf("%d %d",&n,&arcs);
	    vector<vi> graph(n);

	    for(int i = 0;i<arcs;++i){
	        scanf("%d %d",&o,&d);
	        graph[o-1].push_back(d-1);
	    }
	    for(int i = 0;i<n;++i){
	        if(visited[i] != mark1){
	            inis[i] = mark1;
	            dfs(graph,i);
	            ++mark2;
	        }
	    }
	    int cont = 0;
	    for(int i = 0;i<n;++i){
	        if(inis[i]==mark1)++cont;
	    }
	    printf("%d\n",cont);
	    ++mark1;
	}
	return 0;
}



