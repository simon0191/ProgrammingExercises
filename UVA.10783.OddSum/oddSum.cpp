#include <cstdio>

int main(){
    int sum[101];
    sum[0] = 0;
    sum[1] = 1;
    for(int i = 3;i<101;i+=2){
        sum[i] = sum[i-1] = sum[i-2]+i;
    }
    int cases,a,b,cont = 1;
    for(scanf("%d",&cases);cases--;++cont){
        scanf("%d %d",&a,&b);
        if(!(a%2))++a;
        if(!(b%2))--b;
        printf("Case %d: %d\n",cont,sum[b]-sum[a]+a);
    }

    return 0;
}
