#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    double x,y;
    Point(){x=y=0;}
    Point(double _x,double _y):x(_x),y(_y){}

    bool operator==(const Point& p)const{return x==p.x && y==p.y;}
    bool operator!=(const Point& p)const{return x!=p.x || y!=p.y;}
    bool operator<(const Point& p)const{return x==p.x?y<p.y:x<p.x;}

    double det(const Point &P0,const Point& P1)const {return (P1.x - P0.x)*(y - P0.y) - (x - P0.x)*(P1.y - P0.y);}
    bool isColinear(const Point &P0,const Point& P1)const{return (det(P0,P1)==0);}
    bool isOnLeft(const Point &P0,const Point& P1)const{return (det(P0,P1)>0);}
    bool isOnRight(const Point &P0,const Point& P1)const {return (det(P0,P1)<0);}
};
double _distance(Point& a,Point& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void convexHull(set<Point>& points,vector<Point>& convexH){
    bool ya;
    Point left = *points.begin(),right = *points.rbegin();
    vector<Point> upper,lower,lowerHull,upperHull;
    set<Point>::iterator it = points.begin();
    for( ++it;*it != right;++it){
        if(it->isOnLeft(left,right)){
            upper.push_back(*it);
        }else if(it->isOnRight(left,right)){
            lower.push_back(*it);
        }
    }
    lowerHull.push_back(left);
    lower.push_back(right);
    for(int i = 0;i<lower.size();++i){
        lowerHull.push_back(lower[i]);
        ya = false;
        while(lowerHull.size()>=3 && !ya){
            if(lowerHull[lowerHull.size()-2].isOnLeft(lowerHull[lowerHull.size()-3],lowerHull[lowerHull.size()-1])){
                lowerHull[lowerHull.size()-2] = lowerHull[lowerHull.size()-1];
                lowerHull.pop_back();
            }else{
                ya = true;
            }
        }
    }
    upperHull.push_back(left);
    upper.push_back(right);
    for(int i = 0;i<upper.size();++i){
        upperHull.push_back(upper[i]);
        ya = false;
        while(upperHull.size()>=3 && !ya){
            if(upperHull[upperHull.size()-2].isOnRight(upperHull[upperHull.size()-3],upperHull[upperHull.size()-1])){
                upperHull[upperHull.size()-2] = upperHull[upperHull.size()-1];
                upperHull.pop_back();
            }else{
                ya = true;
            }
        }
    }
    for(int i = 0;i<lowerHull.size()-1;++i){
        convexH.push_back(lowerHull[i]);
    }
    for(int i = upperHull.size()-1;i>=1;--i){
        convexH.push_back(upperHull[i]);
    }
}

int main(){
    int nPoints,reg = 1;
    double x,y,perimeter;
    Point aux;
    while(scanf("%d",&nPoints) && nPoints){
        perimeter = 0;
        set<Point> points;
        for(int i = 0;i<nPoints;++i){
            scanf("%lf%lf",&x,&y);
            points.insert(Point(x,y));
        }
        vector<Point> convexH;
        convexHull(points,convexH);
        printf("Region #%d:\n",reg++);
        printf("(%.1lf,%.1lf)",convexH.begin()->x,convexH.begin()->y);
        aux = *convexH.begin();
        for(int i = convexH.size()-1;i>=0;--i){
            perimeter+= _distance(aux,convexH[i]);
            aux = convexH[i];
            printf("-(%.1lf,%.1lf)",convexH[i].x,convexH[i].y);
        }
        printf("\nPerimeter length = %.2lf\n\n",perimeter);
    }
    return 0;
}
