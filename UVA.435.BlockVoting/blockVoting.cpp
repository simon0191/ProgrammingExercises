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
    int cases,n,sum,subSum;
    int parties[30];
    int cont[30];
    scanf("%d",&cases);
    for(int c=0;c<cases;++c){
        memset(cont,0,sizeof(cont));
        sum = 0;
        scanf("%d",&n);
        for(int i = 0;i<n;++i){
            scanf("%d",parties+i);
            sum+=parties[i];
        }
        int len = (1<<(n));
        int mid = (sum>>1);
        for(int i = 0;i<len;++i){
            subSum = 0;
            for(int j = 0;j<n;++j){
                if((i&(1<<j))){
                    subSum+=parties[j];
                }
            }
            if((subSum > mid)){
                for(int j = 0;j<n;++j){
                    if((i&(1<<j)) && ((subSum-parties[j]) <= mid)  ){
                        ++cont[j];
                    }
                }
            }
        }
        int xx = (1<<(n-1));
        for(int i = 1;i<=n;++i){
            printf("party %d has power index %d\n",i,cont[i-1]);
        }
        puts("");
    }
    return 0;
}


