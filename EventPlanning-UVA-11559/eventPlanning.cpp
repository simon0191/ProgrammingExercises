#include <cstdio>
#include <limits>
using namespace std;
int main(){
    int nP,budget,nHotels,nW,cost,cupos,aux,minn;

    while(scanf("%d %d %d %d",&nP,&budget,&nHotels,&nW)==4){
        minn = numeric_limits<int>::max();
        for(int i = 0;i<nHotels;++i){
            scanf("%d",&cost);
            for(int j=0;j<nW;++j){
                scanf("%d",&cupos);
                if(cupos >= nP && (aux=nP*cost)<=budget && aux<minn){
                    minn = aux;
                }
            }
        }
        if(minn == numeric_limits<int>::max()){
            puts("stay home");
        }
        else{
            printf("%d\n",minn);
        }
    }
    return 0;
}
