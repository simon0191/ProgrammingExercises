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

void f(bool& paila,vector<bool>& isA,stack<int>& A,stack<int>& B,int act){
    if(!paila){
        if(isA[act]){
            while(!A.empty() && A.top() !=act){
                B.push(A.top());
                isA[A.top()] = false;
                A.pop();
            }
            if(!A.empty() && (A.top() == act)){
                isA[A.top()] = false;
                A.pop();
            }
            else{
                paila = true;
            }
        }
        else{
            if(!B.empty() && (B.top() == act)){
                B.pop();
            }
            else{
                paila = true;
            }
        }
    }
}

int main(){
    int n,act;
	while(scanf("%d",&n)==1 && n){
	    while(scanf("%d",&act) && act){
            stack<int> A;
            stack<int> B;
            vector<bool> isA(n+1,true);
            bool paila = false;
            for(int i = n;i>0;--i){
                A.push(i);
            }
            f(paila,isA,A,B,act);
            for(int i = 1;i<n;++i){
                scanf("%d",&act);
                f(paila,isA,A,B,act);
            }
            if(paila){
                puts("No");
            }
            else{
                puts("Yes");
            }
	    }
	    puts("");
	}
	return 0;
}


