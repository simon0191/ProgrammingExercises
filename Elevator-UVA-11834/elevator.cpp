#include <cstdio>
#include <cmath>
#define UL unsigned long int

UL _distance(UL x1,UL y1,UL x2,UL y2){
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    UL l,c,r1,r2,dist,maxx;
    while(scanf("%lu %lu %lu %lu",&l,&c,&r1,&r2) && (l!=0 || c!=0 || r1!= 0 || r2 != 0)){
        //printf("%lu %lu %lu %lu\n",l,c,r1,r2);
        if((r2*2 <=l && r2*2 <=c) && (r1*2 <=l && r1*2 <=c)&& (_distance(r1,r1,l-r2,c-r2)>= (r1+r2)*(r1+r2) || _distance(r1,r1,c-r2,l-r2)>= (r1+r2)*(r1+r2))){
            puts("S");
        }else{
            puts("N");
        }
    }
    return 0;
}

