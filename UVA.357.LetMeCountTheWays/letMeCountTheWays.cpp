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
    const int NN = 30010;
    int vals[5] = {1,5,10,25,50};
    UL mat[5][NN];
    for(int i = 0;i<5;++i){
        for(int j = 0;j<NN;++j){
            if(j && i){
                mat[i][j] = mat[i-1][j];
                if((j-vals[i]) >=0){
                    mat[i][j]+=mat[i][j-vals[i]];
                }
            }
            else{
                mat[i][j] = 1;
            }
        }
    }
    mat[4][0] = 1;
	int n;
	UL ans;
	while(scanf("%d",&n)==1){
	    ans = mat[4][n];
	    if(ans != 1){
	        printf("There are %llu ways to produce %d cents change.\n",ans,n);
	    }
	    else{
	        printf("There is only 1 way to produce %d cents change.\n",n);
	    }

	}
	return 0;
}



