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

int cardinality(int n){
    int cont = 0;
    while(n){
        if(n&1)++cont;
        n>>=1;
    }
    return cont;
}
int main(){
    int nNodes,nCon;
    char s[100];
    char buff[100];

    unsigned int wakeUp;

    int slept[30];

	while(scanf("%d %d",&nNodes,&nCon) == 2){
        wakeUp = 0;
        memset(slept,0,sizeof(slept));
        scanf("%s",s);

        for(int i = 0;i<nCon;++i){
            scanf("%s",buff);
            slept[buff[0]-'A']|= (1<<(buff[1]-'A'));
            slept[buff[1]-'A']|= (1<<(buff[0]-'A'));
        }
        for(int i =0;i<3;++i){
            slept[s[i]-'A'] = 0;
            wakeUp|=(1<<(s[i]-'A'));
        }
        //printf("Card wa: %d\n",cardinality(wakeUp));
        int years = 0;
        int despiertas = 3;
        for(; (despiertas<nNodes) ;++years){
            int newNodes = 0;
            for(int i = 0;i<AZ_SIZE;++i){
                int m = wakeUp&slept[i];
                //printf("Card %d: %d\n",m,cardinality(m));
                if(cardinality(m) >= 3){
                    ++despiertas;
                    slept[i] = 0;
                    newNodes|=(1<<i);
                }
            }
            if(!newNodes)break;
            wakeUp|=newNodes;
        }

        if(despiertas >= nNodes){
            printf("WAKE UP IN, %d, YEARS\n",years);
        }
        else{
            puts("THIS BRAIN NEVER WAKES UP");
        }
	}
	return 0;
}


