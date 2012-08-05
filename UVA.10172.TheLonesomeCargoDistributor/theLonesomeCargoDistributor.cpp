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
    int cases,t,n,s,q,size,aux;
	scanf("%d",&cases);
	while(cases--){
	    t = 0;
	    scanf("%d %d %d",&n,&s,&q);
	    vector<queue<int> > qs(n);
	    for(int i = 0;i<n;++i){
	        scanf("%d",&size);
	        for(int j=0;j<size;++j){
	            scanf("%d",&aux);
	            qs[i].push(aux-1);
	        }
	    }
	    stack<int> st;
	    bool flag = true;
	    while(flag){
	        for(int i = 0;i<n;++i,t+=2){
	            while(!st.empty() && ( (qs[i].size() < q) || (st.top()==i) )){
	                if(st.top() == i)st.pop();
	                else{
                        qs[i].push(st.top());
                        st.pop();
	                }
	                ++t;
	            }
	            while(!qs[i].empty() && (st.size() < s)){
	                st.push(qs[i].front());
	                qs[i].pop();
	                ++t;
	            }
	            if(st.empty()){
                    flag = false;
                    for(int j = 0;j<n;++j){
                        if(!qs[j].empty()){
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag)break;
	        }

	    }
	    printf("%d\n",t);
	}
	return 0;
}



