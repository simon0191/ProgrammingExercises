#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

double h2g(double h){
    return h*360.0/12.0;
}
double m2g(double h){
    return h*360.0/60.0;
}
int main(){
    int h,m;
    double hg,mg,resp;
    while(scanf("%d:%d",&h,&m)==2 && (h+m)){
        hg = h2g(h);
        mg = m2g(m);
        hg+=(mg/12.0);
        resp = min(fabs(360.0-fabs(hg-mg)),fabs(hg-mg));
        printf("%.3lf\n",resp);
    }
    return 0;
}

