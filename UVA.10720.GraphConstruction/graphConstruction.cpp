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
    int n,sum,sum2,noNull;
    bool first = true;
    vector<int> ds;
    bool flag;
	while(scanf("%d",&n)==1 && n){
	    ds.assign(n+1,0);
	    noNull = sum = 0;
	    flag = true;
	    for(int i = 1;i<=n;++i){
	        scanf("%d",&ds[i]);
	        if(ds[i]<0)flag = false;
	        sum+=ds[i];
	        if(ds[i])noNull++;
	    }
	    sort(ds.begin(),ds.end());
	    if(n==1 && ds[1]>0)flag = false;
        if(flag){
            if((sum % 2)||(sum > noNull*(noNull - 1))) flag = false;
            else{
                sum = 0;
                flag = true;
                for(int i = 1;i<=n;++i){
                    sum+=ds[i];
                    sum2 = i*(i-1);
                    for(int j = i+1;j<=n;++j){
                        sum2+=min(i,ds[j]);
                    }
                    if(sum > sum2){
                        flag = false;
                        break;
                    }
                }
            }
        }
	    /*if(!first)puts("");
	    else first = false;*/
	    printf("%s\n",( flag?"Possible":"Not possible" ));
	}
	return 0;
}



