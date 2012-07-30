#include <cstdio>
#include <cmath>
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
};
double _distance(Point& a,Point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
    int n;
    Point gopher,dog,p;
    double gDist,dDist;
    bool escape;
    while(scanf("%d %lf %lf %lf %lf",&n,&gopher.x,&gopher.y,&dog.x,&dog.y) == 5){
        escape = false;
        for(int i = 0;i<n;++i){
            scanf("%lf %lf",&p.x,&p.y);
            if(!escape){
                gDist = _distance(p,gopher);
                dDist = _distance(p,dog);
                if((gDist*2)<=dDist){
                    escape = true;
                    printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",p.x,p.y);
                }
            }
        }
        if(!escape){
            puts("The gopher cannot escape.");
        }
    }
    return 0;
}
