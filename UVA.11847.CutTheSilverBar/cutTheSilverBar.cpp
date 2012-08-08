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
	int n;
	int arr[20];
	for(int i = 0;i<20;++i){
	    arr[i] = 1<<i;
	}
	while(scanf("%d",&n) && n){
	    int* j = upper_bound(arr,arr+20,n);
	    int pos = int(j-arr);
	    printf("%d\n",pos-1);//int(i-v.begin()));
	}
	return 0;
}



