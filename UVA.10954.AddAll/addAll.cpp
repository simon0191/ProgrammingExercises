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
	int n,aux;
	while(scanf("%d",&n)==1 && n){
	    priority_queue<int> q;
	    for(int i = 0;i<n;++i){
	        scanf("%d",&aux);
	        q.push(-aux);
	    }
	    int cont = 0;
	    while(!q.empty()){
	        aux=q.top();q.pop();
	        aux+=q.top();q.pop();
	        cont-=aux;
	        if(q.empty())break;
	        q.push(aux);
	    }
	    printf("%d\n",cont);
	}
	return 0;
}



