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


void calc(int size,int hs[10001], int ws[10001],int lis[10001], int lds[10001],
          int& _lis,int& _lds){
    _lis = _lds = numeric_limits<int>::min();
    for(int i= 0;i<size;++i){
        lds[i] = lis[i] = ws[i];
        for(int j = 0;j<i;++j){
            if((hs[j] > hs[i]) && ( lds[j]+ws[i] > lds[i] )){
                lds[i] = lds[j]+ws[i];
                //ldsPath[i] = j;
            }
            if((hs[j] < hs[i]) && ( lis[j]+ws[i] > lis[i] ) ){
                lis[i] = lis[j]+ws[i];
                //lisPath[i] = j;
            }
        }
        _lis = max(lis[i],_lis);
        _lds = max(lds[i],_lds);
    }
    //debug(lds,lis,size);
}

int main(){
    int hs[10001];
    int ws[10001];
    int lis[10001];
    int lds[10001];
    int _lis,_lds;
    int cases,size;
	scanf("%d",&cases);
	for(int c = 1;c<=cases;++c){
	    scanf("%d",&size);
	    for(int i = 0;i<size;++i){
	        scanf("%d",hs+i);
	    }
	    for(int i = 0;i<size;++i){
	        scanf("%d",ws+i);
	    }
	    calc(size,hs,ws,lis,lds,_lis,_lds);
	    if( _lis>=_lds){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",c,_lis,_lds);
	    }
	    else{
	        printf("Case %d. Decreasing (%d). Increasing (%d).\n",c,_lds,_lis);
	    }
	}
	//
	return 0;
}



