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
	int cases,n,d,dis;
	char t[5];
	int dist[1000];
	scanf("%d",&cases);
	for(int c = 1;c<=cases;++c){
	    scanf("%d %d",&n,&d);
	    int size = 0;
	    dist[size++] = 0;

	    for(int i = 1;i<=n;++i){
	        scanf("%s",t);
	        dis = atoi(t+2);
            dist[size++] = dis;
	        if(t[0]=='B'){
	            dist[size++] = dis;
	        }
	    }
	    dist[size++] = d;
	    int maxx = 0;
	    for(int i = 2;i<size;++i){
            maxx = max(maxx,dist[i]-dist[i-2]);
	    }
	    printf("Case %d: %d\n",c,maxx);
	}
	return 0;
}



