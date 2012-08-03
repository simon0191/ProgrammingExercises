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

LL countInversions(vector<LL>& s){
    if(s.size() <= 1) return 0;
    int mid = (s.size()/2);
    LL ans = 0;
    vector<LL> left(s.begin(),s.begin()+mid);
    vector<LL> right(s.begin()+mid,s.end());
    ans+=countInversions(left);
    ans+=countInversions(right);
    int l,r;
    l = r = 0;
    bool onLeft = true;
    for(int i = 0;i<s.size();++i){
        if(r < right.size() && (left[l]>right[r] || l >= left.size())){
            s[i] = right[r++];
            ans+=(mid-l);
        }
        else {
            s[i] = left[l++];
        }
    }
    return ans;
}

int main(){
    int n;
	while(scanf("%d",&n)==1){
        vector<LL> s(n);
        LL aux;
        for(int i = 0;i<n;++i){
            scanf("%lld",&s[i]);
        }
        printf("%lld\n",countInversions(s));
	}
	return 0;
}


