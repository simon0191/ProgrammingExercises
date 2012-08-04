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
    int n,q,aux,pos;

	while(scanf("%d %d",&n,&q)==2){
	    map<int,vector<int> > nums;
	    for(int i = 1;i<=n;++i){
	        scanf("%d",&aux);
	        nums[aux].push_back(i);
	    }
	    for(int i = 0;i<q;++i){
	        scanf("%d %d",&pos,&aux);
	        if(pos <= nums[aux].size()){
	            printf("%d\n",nums[aux][pos-1]);
	        }
	        else{
	            printf("0\n");
	        }
	    }
	}
	return 0;
}



