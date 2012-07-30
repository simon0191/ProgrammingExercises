#include <cstdio>
#include <algorithm>
#include <map>

#define UL unsigned long long

using namespace std;

map<UL,UL> mapa;
UL f(UL n){
    if(n == 0)return 0;
    //printf("# %llu\n",n);
    UL aux;
    if((aux = mapa[n])){
        return aux;
    }
    UL n2 = f(n/2);
    UL n3 = f(n/3);
    UL n4 = f(n/4);

    aux = mapa[n] = max(n2 + n3 +n4,n);
    return aux;
}

int main(){

    mapa[0] = 0;
    mapa[1] = 1;
    mapa[2] = 2;
    mapa[12] = 13;
    UL n;
    while(scanf("%llu",&n)==1){
        printf("%llu\n",f(n));
    }
    return 0;
}
