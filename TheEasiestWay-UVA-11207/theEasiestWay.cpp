#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int cases,ans;
    float w,h,maxx;
    while(scanf("%d",&cases) && cases){
        maxx = 0.0;
        ans = 1;
        for(int i = 1;i<=cases;++i){
            scanf("%f %f",&w,&h);
            if(w>h)w/=2.0;
            else h/=2.0;
            if(w>h)w/=2.0;
            else h/=2.0;

            if((w = min(w,h)) > maxx){
                maxx = w;
                ans = i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
