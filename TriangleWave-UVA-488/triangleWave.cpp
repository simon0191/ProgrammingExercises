#include <cstdio>

int main(){
    int cases,amplitude,frequency;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d%d",&amplitude,&frequency);
        for(int i = 0;i<frequency;++i){
            for(int j=1;j<amplitude;++j){
                for(int k = 0;k<j;++k){
                    printf("%d",j);
                }
                puts("");
            }
            for(int j = 0;j<amplitude;++j){
                printf("%d",amplitude);
            }
            puts("");
            for(int j=amplitude-1;j>0;--j){
                for(int k = 0;k<j;++k){
                    printf("%d",j);
                }
                //if(!(cases==0 && (frequency-1)==i && j == 1))
                puts("");
            }
            if(!(cases==0 && (frequency-1)==i))puts("");
        }
    }
    return 0;
}
