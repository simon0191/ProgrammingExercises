#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point{
    double x,y;
    Point(){x=y=0;}
    Point(double _x,double _y):x(_x),y(_y){}
    bool operator==(const Point& p)const{
        return x==p.x && y==p.y;
    }
    bool operator<(const Point& p)const{
        return x==p.x?y<p.y:x<p.x;
    }
    bool isOnLeft(const Point &p1,const Point& p2)const {
        double det;
        det = (p1.x-p2.x)*(y-p2.y)-(p1.y-p2.y)*(x-p2.x);
        return (det<=0);
    }
    bool isOnRight(const Point &p1,const Point& p2)const {
        double det;
        det = (p1.x-p2.x)*(y-p2.y)-(p1.y-p2.y)*(x-p2.x);
        return (det>0);
    }
};
void convexHull(set<Point>& points,vector<Point>& convexH){
    Point left = *points.begin(),right = *points.rbegin();
    set<Point>::iterator it = points.begin();
    vector<Point> upper,lower;
    for(++it;!(*it==right);++it){
        if(it->isOnLeft(left,right)){
            upper.push_back(*it);
        }else if(it->isOnRight(left,right)){
            lower.push_back(*it);
        }
    }
    convexH.push_back(left);
    for(int i = 0;i<lower.size();++i){
        convexH.push_back(lower[i]);
    }
    convexH.push_back(right);
    for(int i = upper.size()-1;i>=0;--i){
        convexH.push_back(upper[i]);
    }
}
int main(){
    int nPoints;
    double cx,cy,x,y,area;
    while(scanf("%d",&nPoints) && nPoints>=3){
        set<Point> points;
        cx = cy = area = 0;
        for(int i = 0;i<nPoints;++i){
            scanf("%lf %lf",&x,&y);
            points.insert(Point(x,y));
        }
        vector<Point> convexH;
        convexHull(points,convexH);
        convexH.push_back(convexH[0]);
        for(int i = 0;i<convexH.size()-1;++i){
            area+=(convexH[i].x*convexH[i+1].y-convexH[i+1].x*convexH[i].y);
            cx+=( (convexH[i].x+convexH[i+1].x)*(convexH[i].x*convexH[i+1].y-convexH[i+1].x*convexH[i].y) );
            cy+=( (convexH[i].y+convexH[i+1].y)*(convexH[i].x*convexH[i+1].y-convexH[i+1].x*convexH[i].y) );
        }
        area/=2.0;
        cx/=(6.0*area);
        cy/=(6.0*area);
        printf("%.3lf %.3lf\n",cx,cy);

    }
    return 0;
}
