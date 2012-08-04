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
    int n,c,num,aux;
	while(scanf("%d",&n)==1){
	    stack<int> s;
	    queue<int> q;
	    priority_queue<int> pq;
	    bool bs,bq,bpq;
	    bs = bq = bpq = true;
	    for(int i = 0;i<n;++i){
	        scanf("%d %d",&c,&num);
	        if(c == 1){
	            if(bs)s.push(num);
	            if(bq)q.push(num);
	            if(bpq)pq.push(num);
	        }
	        else{
	            if(!s.empty()){
                    aux = s.top();s.pop();
                    if(aux != num)bs = false;
	            }
	            else{
	                bs = false;
	            }
	            if(!q.empty()){
                    aux = q.front();q.pop();
                    if(aux != num)bq = false;
	            }
	            else{
	                bq = false;
	            }
	            if(!pq.empty()){
                    aux = pq.top();pq.pop();
                    if(aux != num)bpq = false;
	            }
	            else{
	                bpq = false;
	            }
	        }
	    }
	    if(bs || bq || bpq){
	        if(bs && (!bq && !bpq)){
	            puts("stack");
	        }
	        else if(bq && (!bs && !bpq)){
	            puts("queue");
	        }
	        else if(bpq && (!bs && !bq)){
	            puts("priority queue");
	        }
	        else{
	            puts("not sure");
	        }
	    }
	    else{
	        puts("impossible");
	    }
	}
	return 0;
}



