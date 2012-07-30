#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int cases,nn,maxx,n;
    scanf("%d",&cases);
    for(int i = 1;i<=cases;++i){
        maxx = 0;
        scanf("%d",&nn);
        while(nn--){
            scanf("%d",&n);
            maxx = max(maxx,n);
        }
        printf("Case %d: %d\n",i,maxx);
    }
    return 0;
}
