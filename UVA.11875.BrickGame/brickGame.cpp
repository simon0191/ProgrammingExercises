#include <cstdio>

int main(){
    int cases,aux,n;
    scanf("%d",&cases);
    for(int c = 1;c<=cases;++c){
        scanf("%d",&n);
        for(int i = 0;i<n;++i){
            scanf("%d",&aux);
            if(i==(n/2)){
                printf("Case %d: %d\n",c,aux);
            }
        }
    }
    return 0;
}
