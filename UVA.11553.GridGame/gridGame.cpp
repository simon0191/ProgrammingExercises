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

map<int,int> state;

int f(int mat[][8],int usedFil,int usedCol,int n,int fil);

int f2(int mat[][8],int usedFil,int usedCol,int n,int col){
    bool flag = false;
    usedCol|=(1<<col);
    int maxx = numeric_limits<int>::min();
    for(int i = 0;i<n;++i){
        if(!(usedFil&(1<<i))){
            flag = true;
            maxx = max(f(mat,usedFil,usedCol,n,i),maxx);
        }
    }
    usedCol&= (~(1<<col));
    return flag?maxx:0;
}
int f(int mat[][8],int usedFil,int usedCol,int n,int fil){
    int actState = ((usedCol<<10)|usedFil);
    map<int,int>::iterator it;
    if((it = state.find(actState))!=state.end())return it->second;
    bool flag = false;
    usedFil|=(1<<fil);
    int minn = numeric_limits<int>::max();
    for(int i = 0;i<n;++i){
        int act = 0;
        if(!(usedCol&(1<<i))){
            flag = true;
            minn = min( minn, f2(mat,usedFil,usedCol,n,i)+mat[fil][i]);
        }
    }
    usedFil&=(~(1<<fil));
    return (state[actState] = flag?minn:0);
}
int main(){
	int cases,n;
	int mat[8][8];
	int used[8];
	int usedFil,usedCol;
	scanf("%d",&cases);
	while(cases--){
	    state.clear();
	    usedFil = usedCol = 0;
	    scanf("%d",&n);
	    for(int i = 0;i<n;++i){
	        for(int j = 0;j<n;++j){
	            scanf("%d",mat[i]+j);
	        }
	    }
	    int maxx = numeric_limits<int>::min();
        for(int i = 0;i<n;++i){
            maxx = max(f(mat,usedFil,usedCol,n,i),maxx);
        }
        printf("%d\n",maxx);
	}
	return 0;
}




