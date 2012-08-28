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

int sum[20100];
int origin[20100];
int size[20100];

int cases,nstops;

bool maxSum(int& x,int& y){
    int maxSum = sum[0];
    int maxSize = 1;
    int lowOrigin = 0;
    origin[0] = 0;
    size[0] = 1;
    for(int i =1;i<nstops;++i){
        if((sum[i-1] >= 0) && (sum[i]+sum[i-1] >= sum[i])){
            sum[i]+=sum[i-1];
            size[i]=size[i-1]+1;
            origin[i] = origin[i-1];
        }
        else{
            origin[i] = i;
            size[i] = 1;
        }
        if(sum[i] > maxSum){
            maxSum = sum[i];
            maxSize = size[i];
            lowOrigin = origin[i];
        }
        else if((sum[i] == maxSum) && (size[i] > maxSize)){
            maxSize = size[i];
            lowOrigin = origin[i];
        }
    }
    x = lowOrigin+1;
    y = lowOrigin+maxSize+1;
    return (maxSum > 0);
}
int main(){
	scanf("%d",&cases);
	for(int c = 1;c<=cases;++c){
	    scanf("%d",&nstops);
	    --nstops;
	    for(int i =0;i<nstops;++i){
	        scanf("%d",sum+i);
	    }
	    int x,y = 0;
	    if(maxSum(x,y)){
	        printf("The nicest part of route %d is between stops %d and %d\n",c,x,y);
	    }
	    else{
	        printf("Route %d has no nice parts\n",c);
	    }

	}
	return 0;
}



