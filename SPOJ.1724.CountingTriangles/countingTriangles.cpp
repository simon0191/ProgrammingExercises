#include <cstdio>
#define UL unsigned long long
#define N 1000001
UL u[N];
UL d[N];
int x1 = 3;
int x2 = 2;
UL f1 = 3;
UL f2 = 1;
int main(){
    u[0] = d[0] = d[1] = 0;u[1] = 1;
    for(int i = 2;i<N;++i){
        u[i]=u[i-1]+f1;
        f1+=(x1++);
        d[i] = d[i-2]+f2;
        f2+=(x2++);
    }
    int c,n;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        printf("%llu\n",u[n]+d[n]);
    }
    return 0;
}
