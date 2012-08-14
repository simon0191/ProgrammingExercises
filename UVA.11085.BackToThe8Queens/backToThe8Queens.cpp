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
#define NN 8

bool isSolution(const vector<int>& qs){
    for(int i = 1;i<=NN;++i){
        for(int j = i+1;j<=NN;++j){
            if( abs(qs[i-1]-qs[j-1]) == abs(i-j))return false;
        }
    }
    return true;
}
int dif(const vector<int>& qs,const vector<int>& sol){
    int cont = 0;
    for(int i = 0;i<NN;++i){
        if(qs[i]!=sol[i])++cont;
    }
    return cont;
}
int main(){
    vector<int> qs(NN);
	for(int i = 0;i<NN;++i)qs[i] = i+1;
	vector<vector<int> > sols;
	int cont  = 0;
	do{
	    if(isSolution(qs))sols.push_back(qs);
	}while(next_permutation(qs.begin(),qs.end()));
	//printf("%d\n",cont);
	int c = 1;
	while(true){
	    for(int i = 0;i<8;++i){
	        if(scanf("%d",&qs[i])!=1)return 0;
	    }
	    int minDif = 8;
	    for(int i = 0;i<sols.size();++i){
	        minDif = min(minDif,dif(qs,sols[i]));
	    }
	    printf("Case %d: %d\n",c++,minDif);
	}
	return 0;
}



