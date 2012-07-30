#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <stack>
#include <cctype>
#include <limits>

#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

using namespace std;

UL f(UL n){
    return (n*(n+1)/2)+1;
}
int main(){
    int n;
	while(scanf("%d",&n) && n>=0){
        printf("%llu\n",f(n));
	}
	return 0;
}
