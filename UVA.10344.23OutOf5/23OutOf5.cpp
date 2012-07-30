#include <cstdio>
#include <algorithm>
#include <climits>

#define PLUS 0
#define PROD 1
#define MINUS 2
using namespace std;
bool f(int arr[5],int sign,int resp,int pos){
    switch(sign){
        case PLUS:resp+=arr[pos];break;
        case PROD:resp*=arr[pos];break;
        case MINUS:resp-=arr[pos];break;
    }
    if(pos == 4){
        //printf("pos4: %d\n",resp);
        return (resp == 23);
    }
    for(int i = 0;i<3;++i){
        if(f(arr,i,resp,pos+1)){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[5];
    int aux;
    while(1){
        aux = 0;
        for(int i = 0;i<5;++i){
            scanf("%d",arr+i);
            aux+=arr[i];
        }
        if(!aux)break;
        bool band = false;
        sort(arr,arr+5);
        do{
            for(int i = 0;i<3 && !band;++i){
                if(f(  arr,i,arr[0],1 )){
                    band = true;
                }
            }
        }while(next_permutation(arr,arr+5) && !band);
        if(band){
            puts("Possible");
        }
        else{
            puts("Impossible");
        }
    }
    return 0;
}

