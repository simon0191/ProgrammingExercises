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

bool bt(int p1[],int p2[],bool used[],const int pieces,int pos,int act,const int spaces,const int final){
    if(act == (spaces)){
        if( (p2[pos] == final) ){
            //printf("(%d,%d)",0,final);
            return true;
        }
        return false;
    }
    for(int i = 1;i<=pieces;++i){
        if(!used[i]){
            if(p2[pos] == p1[i]){
                used[i] = true;
                if( bt(p1,p2,used,pieces,i,act+1,spaces,final) ){
                    //printf("(%d,%d)",p2[i],p1[i]);
                    return true;
                }
                used[i] = false;
            }
            if(p2[pos] == p2[i]){
                used[i] = true;
                if( bt(p2,p1,used,pieces,i,act+1,spaces,final) ){
                    //printf("(%d,%d)",p1[i],p2[i]);
                    return true;
                }
                used[i] = false;
            }
        }
    }
    return false;
}

int main(){
	int spaces,pieces;
	int p1[20];
	int p2[20];
	bool used[20];
	while(scanf("%d",&spaces)==1 && spaces){
	    memset(used,false,sizeof(used));
//	    used[0] = used[spaces+1] = true;
	    scanf("%d",&pieces);
	    scanf("%d %d %d %d",p1,p2,p1+pieces+1,p2+pieces+1);
	    for(int i = 1;i<=pieces;++i){
	        scanf("%d %d",p1+i,p2+i);
	    }
	    printf("%s\n",( (bt( p1,p2,used,pieces,0,0,spaces,p1[pieces+1]) )?"YES":"NO" ));
    }
	return 0;
}



