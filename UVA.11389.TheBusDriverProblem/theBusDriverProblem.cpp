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
    int n,d,r;
    bool first = true;
    vector<int> mor,aft;
    while(scanf("%d %d %d",&n,&d,&r)==3 && (n+d+r)){
        mor.assign(n,0);
        aft.assign(n,0);
        for(int i = 0;i<n;++i){
            scanf("%d",&mor[i]);
        }
        for(int i = 0;i<n;++i){
            scanf("%d",&aft[i]);
        }
        sort(mor.begin(),mor.end());
        sort(aft.rbegin(),aft.rend());
        UL cont = 0;
        for(int i = 0;i<n;++i){
            int res = ((mor[i]+aft[i])-d);
            if(res > 0)cont+=res;
        }
        cont*=r;
        /*if(!first)puts("");
        else first = false;*/
        printf("%llu\n",cont);
    }
    return 0;
}



