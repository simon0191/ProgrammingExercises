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
	int n,aux,maxAge;
	int ages[110];
	while(scanf("%d",&n) && n){
	    maxAge = 0;
	    memset(ages,0,sizeof(ages));
	    for(int i = 0;i<n;++i){
	        scanf("%d",&aux);
	        maxAge = max(maxAge,aux);
	        ++ages[aux];
	    }
	    bool first = true;
	    for(int i = 0;i<=maxAge;++i){
	        if(ages[i]){
                while(ages[i]--){
                    if(!first){
                        printf(" ");
                    }
                    else{
                        first = false;
                    }
                    printf("%d",i);
                }
	        }
	    }
	    puts("");
	}
	return 0;
}


