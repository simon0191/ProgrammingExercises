#include <cmath>
#include <cstdio>

#define EPS 1e-7

int main(){
    int cases;
    double ans,d,v,u,aux;
    double fastestTime,shortestPath;
    bool cant;
    scanf("%d",&cases);
    for(int c = 1;c<=cases;++c){
        cant = false;
        scanf("%lf %lf %lf",&d,&v,&u);
        if(u == 0.0 || u <= v){
            cant = true;
        }
        else{
            fastestTime = fabs(d/u);

            aux = fabs(u*u-v*v);
            shortestPath = d/sqrt(aux);
            ans = fabs(fastestTime-shortestPath);
            if(ans == 0){
                cant = true;
            }
            else{
                printf("Case %d: %.3lf\n",c,ans);
            }
        }
        if(cant){
            printf("Case %d: can\'t determine\n",c);
        }
    }
    return 0;
}
