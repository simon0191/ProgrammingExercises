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
    int n,act[1010],aux;
    bool first = true;
    while(scanf("%d",&n) && n){
        int size = 0;
        bool zero = false;
        for(int i = 0;i<n;++i){
            scanf("%d",&aux);
            if(aux > 0)act[size++] = aux;
            if(!aux)zero = true;
        }
        /*if(!first)puts("");
        else first = false;*/
        for(int i = 0;i<size;++i){
            if(i)printf(" ");
            printf("%d",act[i]);
        }
        if(!size && zero)printf("0");
        puts("");

    }
    return 0;
}



