#include <cstdio>

int main(){
    int n,sum,nums[55],div,ans,set = 0;
    while(scanf("%d",&n) && n){
        sum = ans = 0;
        for(int i = 0;i<n;++i){
            scanf("%d",nums+i);
            sum+=nums[i];
        }
        div = sum/n;
        for(int i = 0;i<n;++i){
            if(nums[i]<div){
                ans+=(div-nums[i]);
            }
        }
        //if(set)puts("");
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",++set,ans);
    }
    return 0;
}
