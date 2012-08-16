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

bool sim(vector<int>& v,int cap,int nC){
    int act = cap;
    int cont = 0;
    for(int i = 0;i<v.size();++i){
        if(cont>=nC)return false;
        if(act>=v[i]){
            act-=v[i];
        }
        else{
            act=cap-v[i];
            ++cont;
        }
    }
    if(cont>=nC)return false;
    return true;
}
int bs(vector<int>& v,int nC,int l,int r){
    if(l == r)return l;
    int mid = (l+r)/2;
    if(sim(v,mid,nC)){
        return bs(v,nC,l,mid);
    }
    return bs(v,nC,mid+1,r);
}
int main(){
    int size,nV,nC,maxx;
    vector<int> v;
    bool first = true;
	while(scanf("%d %d",&nV,&nC)==2){
	    maxx= 0;
	    v.assign(nV,0);
	    for(int i = 0;i<nV;++i){
	        scanf("%d",&v[i]);
	        maxx = max(v[i],maxx);
	    }
	    printf("%d\n",bs(v,nC,maxx,1000000000));
	}
	return 0;
}



