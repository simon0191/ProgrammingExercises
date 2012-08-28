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

using namespace std;

int lisPath[2010];
int ldsPath[2010];
int arr[2010];

void debug(int lds[],int lis[],int size){
    puts("-----------------");
    for(int i = size-1;i>=0;--i){
        printf("%2d|",arr[i]);
    }
    puts("\n-----------------");
    for(int i = size-1;i>=0;--i){
        printf("%2d|",lds[i]);
    }
    puts("");
    for(int i = size-1;i>=0;--i){
        printf("%2d|",ldsPath[i]);
    }
    puts("\n---------------------");
    for(int i = size-1;i>=0;--i){
        printf("%2d|",lis[i]);
    }
    puts("");
    for(int i = size-1;i>=0;--i){
        printf("%2d|",lisPath[i]);
    }
    puts("\n-----------------");
}

int calc(int lds[],int lis[],int size){
    int maxx = 0;
    for(int i= 0;i<size;++i){
        lds[i] = lis[i] = 1;
        lisPath[i] = ldsPath[i] = i;
        for(int j = 0;j<i;++j){
            if((arr[j] > arr[i]) && ( lds[j]+1 > lds[i] )){
                lds[i] = lds[j]+1;
                //ldsPath[i] = j;
            }
            if((arr[j] < arr[i]) && ( lis[j]+1 > lis[i] ) ){
                lis[i] = lis[j]+1;
                //lisPath[i] = j;
            }
        }
        maxx = max(lis[i]+lds[i]-1,maxx);
    }
    //debug(lds,lis,size);
    return maxx;
}
int main() {
    int lis[2010];
    int lds[2010];
    int cases,n,size;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&size);
        for(int i = 0;i<size;++i){
            scanf("%d",arr+size-1-i);
        }
        printf("%d\n",calc(lds,lis,size));
    }

	return 0;
}
