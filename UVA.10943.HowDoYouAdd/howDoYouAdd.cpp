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
    int mat[105][105];
    for(int i = 0;i<105;++i){
        for(int j = 0;j<105;++j){
            if( j<=1){
                mat[i][j] = j;
            }
            else if(i){
                mat[i][j] = (mat[i-1][j]+mat[i][j-1])%1000000;
            }
            else{
                mat[i][j] = 1;
            }
        }
    }

	int n,k;
    while(scanf("%d %d",&n,&k)==2 && (n+k)){
        printf("%d\n",mat[n][k]);
    }
	return 0;
}



