#include <cstdio>
#include <cmath>

int main(){
    double x1,x2,x3,y1,y2,y3;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)==6){
        double t1x = x1+(x2-x1)/2;
        double t1y = y1+(y2-y1)/2;

        double t2x = x2+(x3-x2)/2;
        double t2y = y2+(y3-y2)/2;

        double wx,wy,mx,my;
        wx = y2-y1;
        wy = x1-x2;

        mx = y3-y2;
        my = x2-x3;

        double a,b;
        b = (t1x*wy-t2x*wy-(t1y*t2y)*wx)/(mx*wy-my*wx);
        a = (b*mx+t2x-t1x)/wx;
        double cx,cy;
        cx = b*mx+t2x;
        cy = b*my+t2y;
        double radius = sqrt((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1));
        printf("%lf %lf %lf\n",cx,cy,radius);
    }
    return 0;
}
