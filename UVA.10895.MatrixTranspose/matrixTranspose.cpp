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

int main(){
    int r,c,n,aux;
    int cols[1010];
	while(scanf("%d %d",&r,&c)==2){
	    vector<vector<pair<int,int> > > graph(c+1);
	    for(int i = 1;i<=r;++i){
	        scanf("%d",&n);
	        for(int j=0;j<n;++j){
	            scanf("%d",cols+j);
	        }
	        for(int j=0;j<n;++j){
	            scanf("%d",&aux);
	            graph[cols[j]].push_back(pair<int,int>(i,aux));
	        }
	    }
	    printf("%d %d\n",c,r);
	    for(int i = 1;i<=c;++i){
	        printf("%d",(int)graph[i].size());
	        for(int j = 0;j<graph[i].size();++j){
	            printf(" %d",graph[i][j].first);
	        }
	        puts("");
	        for(int j = 0;j<graph[i].size();++j){
	            if(j)printf(" ");
	            printf("%d",graph[i][j].second);
	        }
	        puts("");
	    }
	}
	return 0;
}



