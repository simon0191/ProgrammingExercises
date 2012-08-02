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
#include <stack>
#include <vector>

#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9
const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

int main(){
    int cases,ans,r,c,m,n,pos;
    int freqs[AZ_SIZE];
    char _char;
    cin>>cases;
	for(int cc = 1;cc<=cases;++cc){
	    memset(freqs,0,sizeof freqs);
	    int cMax = 0;
	    int maxFreq = 0;
	    cin>>r>>c>>m>>n;
	    int chars = r*c;
        for(int i = 0;i<chars;++i){
            cin>>_char;
            freqs[(pos = _char-'A')]++;
            maxFreq = max(freqs[pos],maxFreq);
        }
        ans = 0;
        for(int i = 0;i<AZ_SIZE;++i){
            if(freqs[i]!=maxFreq){
                ans+=n*freqs[i];
            }
            else{
                ans+=m*freqs[i];
            }
        }
	    printf("Case %d: %d\n",cc,ans);
	}
	return 0;
}


