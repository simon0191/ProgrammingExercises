#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cctype>
#include <limits>

#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

using namespace std;

int main(){
	char n[100005];
	char m[100005];
	int digits[10];
	char maxx = '0';
	memset(digits,0,sizeof(digits));
	scanf("%s %s",n,m);

	for(int i = 0;m[i];++i){
        maxx = max(m[i],maxx);
        ++digits[m[i]-'0'];
	}
	for(int i = 0;n[i] && maxx > '0';++i){
	    if(n[i] < maxx){
	        n[i] = maxx;
	        --digits[maxx-'0'];
	        while(digits[maxx-'0'] == 0){
	            --maxx;
	        }
	    }
	}
	//for(it = 0;n[it]=='0';++it);
	printf("%s\n",n);
	return 0;
}

