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

bool f(priority_queue<int>& q){
    if(q.empty())return false;
    do{
        int act = q.top();
        q.pop();
        if(q.size() >= act){
            vector<int> v;
            for(int i = 0;i<act;++i){
                if(q.top() > 1)v.push_back(q.top()-1);
                q.pop();
            }
            for(int i = 0;i<v.size();++i){
                q.push(v[i]);
            }
        }
        else{
            return false;
        }
    }while(!q.empty());
    return true;
}

int main(){
	int n,sum,sum2,noNull;
    int aux;
    bool possible;
	while(scanf("%d",&n)==1 && n){
	    noNull = sum = 0;
	    possible = true;
	    bool allZero = true;
	    priority_queue<int> q;
	    for(int i = 0;i<n;++i){
	        scanf("%d",&aux);
	        if(aux<0)possible = false;
	        if(aux) allZero = false;
	        if(aux>0)q.push(aux);
	    }
        if(allZero || (possible && (possible = f(q)))){
            puts("Possible");
        }
        else{
            puts("Not possible");
        }
	}
	return 0;
}



