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

void proc(vector<int>& vec,int act,int g,int u,int d,int size){
    if(act == g)return;
    int auxU = vec[act]+1;
    if(act+u < size && vec[act+u] > auxU){
        vec[act+u] = vec[act]+1;
        proc(vec,act+u,g,u,d,size);
    }
    int auxD = vec[act]+1;
    if(act-d >= 0 && vec[act-d] > auxD){
        vec[act-d] = vec[act]+1;
        proc(vec,act-d,g,u,d,size);
    }

}
int main(){
    int f,s,g,u,d;
	while(scanf("%d%d%d%d%d",&f,&s,&g,&u,&d) && (f+s+g+u+d  )){
        vector<int> vec(f,numeric_limits<int>::max());
        vec[s-1] = 0;
        proc(vec,s-1,g-1,u,d,f);
        if(vec[g-1]!=numeric_limits<int>::max()){
            printf("%d\n",vec[g-1]);
        }
        else{
            puts("use the stairs");
        }
	}
	return 0;
}

