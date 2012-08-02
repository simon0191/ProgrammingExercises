#include <cstdio>
#include <cstdlib>
#include <cmath>
#define EPS 1e-9
#define PI 3.141592653589793
struct Line{
    double A,B,C;
    Line(double x1,double y1,double x2,double y2){
        A = y1-y2;
        B = x2-x1;
        C = ((-A)*x1)-(B*y1);
    }
    bool intersectingPoint(const Line& l,double& X,double& Y){
        double det = A*l.B-l.A*B;
        if(fabs(det)<EPS){
            return false;
        }
        X = double(B*l.C-C*l.B)/double(det);
        Y = double(C*l.A-A*l.C)/double(det);
        return true;
    }
};
int main(){
    double x1,x2,x3,y1,y2,y3,auxx,auxy,rx,ry,radius,coefx,coefy,coefc;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6){
        Line l1(x1,y1,x2,y2);
        Line l2(x2,y2,x3,y3);

        auxx = (x1-x2)/2+x2;
        auxy = (y1-y2)/2+y2;
        //Line perpendicular to l1 and containing the middle point of l1
        Line p1(auxx,auxy,auxx+l1.A,auxy+l1.B);

        auxx = (x3-x2)/2+x2;
        auxy = (y3-y2)/2+y2;
        //Line perpendicular to l2 and containing the middle point of l2
        Line p2(auxx,auxy,auxx+l2.A,auxy+l2.B);

        p1.intersectingPoint(p2,rx,ry);
        radius = sqrt((rx-x1)*(rx-x1)+(ry-y1)*(ry-y1));
        double circunference = 2.0*PI*radius;
        printf("%.2lf\n",circunference);
/*
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",(rx<0?'+':'-'),fabs(rx),(ry<0?'+':'-'),fabs(ry),radius);
        coefx = rx*(-2);
        coefy = ry*(-2);
        coefc = rx*rx+ry*ry-radius*radius;
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",(coefx<0?'-':'+'),fabs(coefx),(coefy<0?'-':'+'),fabs(coefy),(coefc<0?'-':'+'),fabs(coefc));
        */
    }
    return 0;
}
