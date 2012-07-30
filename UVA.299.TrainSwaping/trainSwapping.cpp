#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    int cases,size,swaps;
    int trains[55];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&size);
        for(int i = 0;i<size;++i){
            scanf("%d",trains+i);
        }
        swaps = 0;
        for(int i = 1;i<size;++i){
            for(int j = 0;j<size-i;++j){
                if(trains[j]>trains[j+1]){
                    ++swaps;
                    swap(trains[j],trains[j+1]);
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",swaps);
    }
    return 0;
}
