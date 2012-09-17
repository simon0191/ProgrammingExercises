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

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;


int mark = 1;

bool dfs(bool graph[][110],int act,int dest,int n,int visited[]){
    if(visited[act] == mark)return false;
    if(act == dest){
        return true;
    }
    visited[act] = mark;
    for(int i = 0;i<n;++i){
        if(graph[act][i] && visited[i]!=mark){
            if (dfs(graph,i,dest,n,visited)){
                return true;
            }
        }
    }
    return false;
}
int main(){
	bool graph[110][110];
	bool floyd[110][110];
	int visited[110];
    bool first = true;
	int cases,n,aux;
	char line[300];

	line[0] = '+';
	for(int i = 1;i<300;++i)line[i]='-';
    MEM0(visited);

	scanf("%d",&cases);
	for(int c =1;c<=cases;++c){
	    printf("Case %d:\n",c);
	    scanf("%d",&n);
	    line[n*2]='+';
	    line[n*2+1]=0;

	    for(int i = 0;i<n;++i){
	        for(int j = 0;j<n;++j){
	            scanf("%d",&aux);
	            graph[i][j] = (aux?true:false);
	            floyd[i][j] = (aux?true:false);
	        }
	        floyd[i][i] = true;
	    }

	    for(int k=0; k<n; k++)
           for(int i=0; i<n; i++)
               for(int j=0; j<n; j++)
                   if(floyd[i][k] && floyd[k][j]){
                       floyd[i][j]=true;
                   }

        bool a,b;

	    puts(line);
	    for(int i = 0;i<n;++i){
	        printf("|");
	        for(int j = 0;j<n;++j){
	            b = (floyd[0][i] && floyd[i][j]);
	            if(b){
	                visited[i] = mark;
                    a = ((i!=j) && dfs(graph,0,j,n,visited));
                    visited[i] = 0;
	            }
	            printf("%c|", ( b&&(!a) )?'Y':'N');
	            ++mark;
	        }
	        printf("\n");
	        puts(line);
	    }

	    line[n*2]='-';
	    line[n*2+1]='-';
	}
	return 0;
}



