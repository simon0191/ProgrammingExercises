#include <cstdio>

int main(){
    int cases,n,i,cont;
    double arr[1001],avg;
    for(scanf("%d",&cases);cases--;){
        scanf("%d",&n);
        avg = 0.0;
        cont = 0;
        for(int i = 0;i<n;++i){
            scanf("%lf",arr+i);
            avg+=arr[i];
        }
        avg/=(double)n;
        for(int i = 0;i<n;++i){
            if(arr[i]>avg){
                ++cont;
            }
        }
        printf("%.3lf%c\n",((double)cont)*100.0/((double)n),'%');
    }
    return 0;
}
