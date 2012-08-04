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

UL hash(set<int>& sete){
    set<int>::iterator it;
    UL resp = 0;
    int c = 31;
    UL pow = 1;
    for(it = sete.begin();it!=sete.end();++it){
        resp+=((*it)*pow);
        pow*=c;
    }
    return resp;
}
void debug(set<int> sete){
    set<int>::iterator it;
    puts("\n-----------");
    for(it = sete.begin();it!=sete.end();++it){
        printf("%d - ",*it);
    }
    puts("\n-----------");
}
int main(){
    int n,aux,maxFreq;
    map<UL,int>::iterator it;
	while(scanf("%d",&n)==1 && n){
	    map<UL,int> freq;
	    maxFreq = -1;
	    for(int i = 0;i<n;++i){
	        set<int> sete;
	        for(int j = 0;j<5;++j){
	            scanf("%d",&aux);
	            sete.insert(aux);
	        }
	        maxFreq = max(maxFreq,++freq[hash(sete)]);
	    }
	    int cont = 0;
	    for(it = freq.begin();it!=freq.end();++it){
	        if((it->second) == maxFreq){
	            cont+=it->second;
	        }
	    }
	    printf("%d\n",cont);
	}
	return 0;
}



