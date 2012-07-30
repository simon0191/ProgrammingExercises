#include <cstdio>
#include <cmath>
#include <limits>
#include <vector>
#define EPS 1e-9
using namespace std;
struct Line{
    double A,B,C;
    Line(){
        A = B = C = 0;
    }
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

class Point{
    public:
    double x,y;
    Point(){
        x = y = 0;
    }
    Point(double _x,double _y):x(_x),y(_y){}
    bool operator<(const Point& p)const{
        if(x!=p.x)
            return x<p.x;
        return y<p.y;
    }
};

double _distance(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
    int nPoints;
    double minDist,X,Y,C,aux;
    Point m,p,ans;
    while(scanf("%lf %lf %d",&m.x,&m.y,&nPoints)==3){
        minDist = numeric_limits<double>::max();
        vector<Point> points;
        for(int i = 0;i<nPoints+1;++i){
            scanf("%lf %lf",&p.x,&p.y);
            if(minDist > (aux = _distance(p,m)) ){
                minDist = aux;
                ans = p;
            }
            points.push_back(p);
        }
        for(int i = 1;i<nPoints+1;++i){
            Line line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
            Line perp;
            perp.A = -line.B;
            perp.B = line.A;
            perp.C = ((-perp.A)*m.x)-(perp.B*m.y);
            perp.intersectingPoint(line,X,Y);
            if(!(X <=points[i-1].x && X <=points[i].x) && !(X >=points[i-1].x && X >=points[i].x)){
                if(minDist > (aux = _distance(Point(X,Y),m)) ){
                    minDist = aux;
                    ans.x = X;
                    ans.y = Y;
                }
            }
        }
        printf("%.4lf\n%.4lf\n",ans.x,ans.y);
    }
    return 0;
}

