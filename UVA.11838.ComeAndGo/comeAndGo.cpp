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

int visited[2010];
int mark = 1;
void dfs(vector<vi>& graph,int &cont,int x){
    ++cont;
    visited[x] = mark;
    for(int i = 0;i<graph[x].size();++i){
        if(visited[graph[x][i]] != mark){
            dfs(graph,cont,graph[x][i]);
        }
    }
}
int main(){
    int n,arcs,o,d,p;
    memset(visited,0,sizeof visited);
    while(scanf("%d %d",&n,&arcs)==2 && (n+arcs)){
        vector<vi> graph(n);
        for(int i = 0;i<arcs;++i){
            scanf("%d %d %d",&o,&d,&p);
            graph[o-1].push_back(d-1);
            if(p==2){
                graph[d-1].push_back(o-1);
            }
        }
        bool possible = true;
        for(int i = 0;i<n && possible;++i){
            int cont = 0;
            dfs(graph,cont,i);
            possible = (cont==n);
            ++mark;
        }
        printf("%d\n",possible?1:0);

    }
	return 0;
}


