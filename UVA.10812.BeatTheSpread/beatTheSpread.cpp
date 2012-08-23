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
    int cases,a,b;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&a,&b);
        int x = (a-b);
        if((x%2) || (x<0)){
            puts("impossible");
        }
        else{
            x/=2;
            int y = a-x;
            if(y>=0){
                printf("%d %d\n",max(x,y),min(x,y));
            }
            else{
                puts("impossible");
            }
        }
    }
	return 0;
}


