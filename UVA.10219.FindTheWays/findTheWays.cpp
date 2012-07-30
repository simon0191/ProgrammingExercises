#include <cmath>
#include <cstdio>


#define LD long double
#define LL long long

int main(){
    LL n,m;
    LD ans;
    while(scanf("%lld %lld",&n,&m)==2){
        ans = 0.0;
        if(m>n-m){
            for(int i = m+1;i<=n;++i){
                ans+=log10(i);
            }
            n = n-m;
        }
        else{
            for(int i = n-m+1;i<=n;++i){
                ans+=log10(i);
            }
            n = m;
        }
        for(int i = 1;i<=n;++i){
            ans-=log10(i);
        }
        printf("%d\n",int(ans)+1);
    }
    return 0;
}
