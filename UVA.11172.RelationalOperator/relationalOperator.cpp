#include <cstdio>

int main(){
    int cases;
    long long a,b;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lld%lld",&a,&b);
        if(a==b){
            puts("=");
        }
        else if(a<b){
            puts("<");
        }
        else{
            puts(">");
        }
    }
    return 0;
}
