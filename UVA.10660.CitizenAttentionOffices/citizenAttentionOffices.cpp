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

int calcDist(int a,int b){
    int ax = a/5;
    int ay = a%5;
    int bx = b/5;
    int by = b%5;
    return abs(ax-bx)+abs(ay-by);
}
void calcDist(int dist[25][25]){
    for(int i = 0;i<25;++i){
        for(int j = 0;j<25;++j){
            dist[i][j] = calcDist(i,j);
        }
    }
}
void calcPosibles(vector<int>& posibles){
    int p;
    for(int k1 = 0;k1<25;k1++){
        for(int k2 = k1+1;k2<25;k2++){
            for(int k3 = k2+1;k3<25;k3++){
                for(int k4 = k3+1;k4<25;k4++){
                    for(int k5 = k4+1;k5<25;k5++){
                        p = 0;
                        p|=(1<<k1);
                        p|=(1<<k2);
                        p|=(1<<k3);
                        p|=(1<<k4);
                        p|=(1<<k5);
                        posibles.push_back(p);
                    }
                }
            }
        }
    }
}
int main(){
    int dist[25][25];
    vector<int> posibles;
    calcDist(dist);
    calcPosibles(posibles);
	int city[25];
	int cases,n,x,y;
	scanf("%d",&cases);
	while(cases--){
	    memset(city,0,sizeof(city));
	    scanf("%d",&n);
	    for(int i = 0;i<n;++i){
	        scanf("%d %d",&x,&y);
	        scanf("%d",city+(x*5+y));
	    }
	    int minnSum = numeric_limits<int>::max();
	    int mask = posibles[0];
        for(int i = 0;i<posibles.size();++i){
            int sum = 0;
            for(int j=0;j<25;++j){
                int minn = 0;
                if(city[j]){
                    minn = numeric_limits<int>::max();
                    for(int k = 0;k<25;++k){
                        if(posibles[i]&(1<<k))minn = min(dist[j][k]*city[j],minn);
                    }
                    sum+=minn;
                }
            }
            if(sum < minnSum){
                minnSum = sum;
                mask = posibles[i];
            }
        }
        bool first = true;
        for(int i = 0;i<25;++i){
            if(mask&(1<<i)){
                if(!first)printf(" ");
                else first = false;
                printf("%d",i);
            }
        }
        puts("");
	}
	return 0;
}



