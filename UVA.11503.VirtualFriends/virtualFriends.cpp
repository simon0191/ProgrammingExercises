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
vector<int> size;

void init(int n){
    pset.assign(n,0);
    size.assign(n,1);
    for(int i = 0;i<n;++i){
        pset[i] = i;
    }
}
int findSet(int i){
    if(pset[i] == i)return i;
    return (pset[i] = findSet(pset[i]));

    //return ((pset[i] == i)?i:(pset[i]=f));
}
int isSameSet(int a,int b){
    return (findSet(a) == findSet(b));
}
void unionSet(int a,int b){
    int pa = findSet(a);
    int pb = findSet(b);
    if(pa == pb)return;
    if(size[pa] >= size[pb]){
        pset[b] = pa;
        size[pa]+=size[pb];
    }
    else{
        pset[a] = pb;
        size[pb]+=size[pa];
    }
}
void debug(int n){
    puts("---------------");
    for(int i = 0;i<n;++i){
        printf("%2d|",i);
    }
    puts("");
    for(int i = 0;i<n;++i){
        printf("%2d|",size[findSet(i)]);
    }
    puts("\n---------------");
}
int main(){
    int cases,f;
    char n1[30],n2[30];
	scanf("%d",&cases);
	map<string,int>::iterator it;
	for(int i = 0;i<cases;++i){
	    scanf("%d",&f);
	    init(2000010);
	    map<string,int> ids;
	    int cont = 0;
	    for(int j = 0;j<f;++j){
	        scanf("%s %s",n1,n2);
            if( (it = ids.find(n1))==ids.end() ){
                ids[n1] = cont++;
            }
            if( (it = ids.find(n2))==ids.end() ){
                ids[n2] = cont++;
            }
            unionSet(findSet(ids[n1]),findSet(ids[n2]));
            //debug(cont);
            printf("%d\n",size[findSet(ids[n1])]);
	    }
	}
	return 0;
}



