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

int main(){
    int NN = 10;
    srand(time(NULL));
    printf("%d\n",NN);
    for(int i = 0;i<NN;++i){
        int n = rand()%8+1;
        printf("%d\n",n);
        for(int j = 0;j<n;++j){
            for(int k = 0;k<n;++k){
                int act = -(rand()%1000);
                if(rand()%3){
                    act*=-1;
                }
                printf("%d ",act);
            }
            printf("\n");
        }
    }
	return 0;
}


