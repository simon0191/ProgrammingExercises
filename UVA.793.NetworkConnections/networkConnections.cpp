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
vector<int> pset;
void init(int n){
    pset.assign(n,0);
    for(int i = 0;i<n;++i){
        pset[i] = i;
    }
}
int findSet(int i){
    return ((pset[i] == i)?i:(pset[i]=findSet(pset[i])));
}
int isSameSet(int a,int b){
    return findSet(a) == findSet(b);
}
void unionSet(int a,int b){
    pset[findSet(a)] = findSet(b);
}
int main(){
    int cases,fail,succ,n,a,b;
    char line[100];
    char aux[10];
    scanf("%d",&cases);
    for(int c=0;c<cases;++c){
        if(c)puts("");
        fail = succ = 0;
        scanf("%d",&n);
        init(n+1);
        gets(line);
        while(gets(line) && strcmp("",line)){
            sscanf(line,"%s %d %d",aux,&a,&b);
            if(aux[0] == 'c'){
                unionSet(a,b);
            }
            else{
                if(isSameSet(a,b)){
                    succ++;
                }
                else{
                    fail++;
                }
            }
        }
        printf("%d,%d\n",succ,fail);
    }
	return 0;
}



