#include <cstdio>
#include <algorithm>
#include <cmath>
#define D double
#define EPS 1e-7
using namespace std;
double f(D p,D q,D r,D s,D t,D u,D x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool bisec(D inf,D sup, D p,D q,D r,D s,D t,D u,D &X){
    D fInf = f(p,q,r,s,t,u,inf);
    D fSup = f(p,q,r,s,t,u,sup);
    if((fInf < 0.0 && fSup<0.0) || (fInf > 0.0 && fSup>0.0)){
        return false;
    }
    if(fInf > fSup){
        swap(inf,sup);
    }
    D med = (inf+sup)/2.0;
    D fMed = f(p,q,r,s,t,u,med);
    if(fabs(fMed)< EPS){
        X = med;
        return true;
    }
    if(fMed < 0.0){
        return bisec(med,sup,p,q,r,s,t,u,X);
    }
    else{
        return bisec(inf,med,p,q,r,s,t,u,X);
    }
}
int main(){
    double p,q,r,s,t,u,X;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6){
        if(bisec(0.0,1.0,p,q,r,s,t,u,X)){
            printf("%.4lf\n",X);
        }
        else{
            puts("No solution");
        }
    }
    return 0;
}
