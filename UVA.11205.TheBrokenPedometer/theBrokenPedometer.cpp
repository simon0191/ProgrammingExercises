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
int card(int n){
    int cont = 0;
    while(n){
        if(n&1)++cont;
        n>>=1;
    }
    return cont;
}
int main(){
    int cases,nleds,n;
    int nums[110],aux;
    scanf("%d",&cases);
	while(cases--){
	    scanf("%d %d",&nleds,&n);
	    memset(nums,0,sizeof(nums));
	    for(int i = 0;i<n;++i){
	        for(int j = 0;j<nleds;++j){
                scanf("%d",&aux);
                nums[i]<<=1;
                if(aux)nums[i]|=1;
	        }
	    }
	    int lim = (1<<nleds);
	    bool ok = true;
	    int minn = nleds;
	    for(int i = 0;i<lim;++i){
	        ok = true;
	        set<int> sete;
	        for(int j = 0;j<n && ok;++j){
	            if(sete.find(i&nums[j])==sete.end()){
	                sete.insert(i&nums[j]);
	            }
	            else{
	                ok = false;
	            }
	        }
	        if(ok){
	            minn = min(minn,card(i));
	        }
	    }
        printf("%d\n",minn);
	}
	return 0;
}



