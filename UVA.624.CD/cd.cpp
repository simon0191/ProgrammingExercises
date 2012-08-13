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
	int duration,n;
	int songs[25];
	while(scanf("%d %d",&duration,&n)==2){
	    int minDif = duration;
	    int ans = 0;
	    int sum = 0;
	    for(int i =0;i<n;++i){
	        scanf("%d",songs+i);
	    }
	    int len = (1<<n);
	    for(int i = 0;i<len;++i){
	        int subSum = 0;
	        int card = 0;
	        for(int j = 0;j<n;++j){
	            if(i&(1<<j)){
	                card++;
	                subSum+=songs[j];
	            }
	        }
	        if((subSum<= duration) && ((duration-subSum)<minDif ) ){
	            ans = i;
	            minDif = duration-subSum;
	            sum = subSum;
	        }
	    }
	    for(int i = 0;i<n;++i){
	        if(ans&(1<<i)){
	            printf("%d ",songs[i]);
	        }
	    }
	    printf("sum:%d\n",sum);
	}
	return 0;
}



