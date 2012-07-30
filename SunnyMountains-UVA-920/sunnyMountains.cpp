#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <iostream>
#define EPS 1e-9



class _Point{
    public:
    double x,y;
    _Point(){}
    _Point(double _x,double _y):x(_x),y(_y){}
    bool operator<(const _Point& p)const{
        if(x!=p.x)
            return x<p.x;
        return y<p.y;
    }
};
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
double _distance(_Point& p1,_Point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
using namespace std;
int main(){
    int cases,nPoints;
    double x,y,ans,act;
    scanf("%d",&cases);
    while(cases--){
        ans = 0;
        set<_Point> points;
        scanf("%d",&nPoints);
        for(int i = 0;i<nPoints;++i){
            scanf("%lf %lf",&x,&y);
            points.insert(_Point(x,y));
        }
        vector<_Point> pointsV(points.begin(),points.end());
        act = nPoints-1;
        for(int i = nPoints-2;i>=0;--i){
            if(pointsV[i].y > pointsV[act].y){
                if(pointsV[i+1].y >= pointsV[act].y){
                    ans+=_distance(pointsV[i],pointsV[i+1]);
                }else{
                    Line l1(pointsV[act].x,pointsV[act].y,pointsV[act].x-10,pointsV[act].y);
                    Line l2(pointsV[i].x,pointsV[i].y,pointsV[i+1].x,pointsV[i+1].y);
                    l1.intersectingPoint(l2,x,y);
                    _Point p(x,y);
                    ans+=_distance(pointsV[i],p);
                }
                act = i;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
