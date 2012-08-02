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
    int cases,r,c,n,med;
    int s[50010];
    int a[50010];
	scanf("%d",&cases);
	while(cases--){
	    scanf("%d%d%d",&r,&c,&n);
	    med = n/2;
	    for(int i = 0;i<n;++i){
	        scanf("%d%d",s+i,a+i);
	    }
	    if(n%2 == 0){
            --med;
	    }
	    sort(a,a+n);
	    sort(s,s+n);
	    printf("(Street: %d, Avenue: %d)\n",s[med],a[med]);
	}
	return 0;
}


