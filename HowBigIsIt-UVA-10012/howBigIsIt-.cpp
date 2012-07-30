#include <cstdio>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
double _distance(double a,double b){
    return sqrt((a+b)*(a+b)-(a-b)*(a-b));
}
int main(){
    double circles[9],dist,ans,x[9],maxR;
    int cases,nCircles;
    scanf("%d",&cases);
    while(cases--){
        ans = numeric_limits<double>::max();
        scanf("%d",&nCircles);
        for(int i = 0;i<nCircles;++i){
            scanf("%lf",circles+i);
        }
        sort(circles,circles+nCircles);
        do{
            x[0] = circles[0];
            maxR = x[0]+circles[0];
            for(int i = 1;i<nCircles;++i){
                x[i] = circles[i];
                for(int j = 0;j<i;++j){
                    x[i] = max(x[i],_distance(circles[i],circles[j])+x[j]);
                }
                maxR = max(maxR,x[i]+circles[i]);
            }
            ans = min(ans,maxR);
        }while(next_permutation(circles,circles+nCircles));
        printf("%.3lf\n",ans);
    }
    return 0;
}
