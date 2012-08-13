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
    int f,r;
    double fs[15],rs[15];
    double prod[125];
    while(scanf("%d",&f)==1 && f){
        scanf("%d",&r);
        for(int i = 0;i<f;++i){
            scanf("%lf",fs+i);
        }
        for(int i = 0;i<r;++i){
            scanf("%lf",rs+i);
        }
        int p = 0;
        for(int i = 0;i<r;++i){
            for(int j = 0;j<f;++j){
                prod[p++] = rs[i]/fs[j];
            }
        }
        sort(prod,prod+p);
        double maxx = 0,aux;
        for(int i = 1;i<p;++i){
            aux = prod[i]/prod[i-1];
            maxx = max(aux,maxx);
        }
        printf("%.2lf\n",maxx);
    }
	return 0;
}


