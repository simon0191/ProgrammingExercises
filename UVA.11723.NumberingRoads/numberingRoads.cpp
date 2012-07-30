#include <cstdio>

int main(){
    int r,n,ans,c = 1;
    while(scanf("%d %d",&r,&n)==2 && (r+n)){
        printf("Case %d: ",c++);
        ans = r/n;
        if(ans<= 26){
            if((r%n) == 0){
                --ans;
            }
            printf("%d\n",ans);
        }
        else{
            puts("impossible");
        }
    }
    return 0;
}
