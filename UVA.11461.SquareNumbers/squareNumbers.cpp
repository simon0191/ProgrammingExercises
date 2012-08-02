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
#define NN 100010
int main(){
	bitset<NN> isSquare;
	int lim = sqrt(NN)+1;
	for(int i = 0;i<lim;++i){
	    isSquare[i*i] = true;
	}
	int acum[NN];
	memset(acum,0,sizeof(acum));
	acum[0] = 1;
	for(int i = 1;i<NN;++i){
	    acum[i] = acum[i-1];
	    if(isSquare[i])++acum[i];
	}
	int a,b;
	while(scanf("%d%d",&a,&b) && (a+b)){
	    if(b<a)swap(b,a);
	    printf("%d\n",acum[b]-acum[a-1]);
	}
	return 0;
}


