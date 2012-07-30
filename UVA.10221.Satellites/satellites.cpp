#include <cstdio>
#include <cstring>
#include <cmath>

//#define PI
//59265358979323846
const double PI = 2*acos(0);
double dArc(double rad,double grad){
    return rad*grad;
}
double dChord(double rad,double grad){
    return sqrt(rad*rad*2-2*rad*rad*cos(grad));
}
int main(){
    char str[5];
    double rad,grad,arc,chord;
    while(scanf("%lf %lf %s",&rad,&grad,str) == 3){
        if(!strcmp(str,"min")){
            grad = (grad*PI)/(180.0*60.0);
        }
        else{
            grad = grad*PI/180.0;
        }
        if(grad > PI){
            grad = 2.0*PI-grad;
        }
        rad+=6440;
        arc = dArc(rad,grad);
        chord = dChord(rad,grad);
        printf("%.6lf %.6lf\n",arc,chord);
    }
    return 0;
}

