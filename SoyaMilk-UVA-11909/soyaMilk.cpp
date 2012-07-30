#include <cstdio>
#include <cstdio>
#include <cmath>
#define Vector2 Point
#define abs(X) ((X)<0?-(X):(X))
#define EPS 1e-8
#define DD double

const DD PI = acos(-1);

struct Point{
    DD x,y;
    Point(){x=y=0;}
    Point(DD _x,DD _y):x(_x),y(_y){}

    bool operator==(const Point& p)const{return x==p.x && y==p.y;}
    bool operator!=(const Point& p)const{return x!=p.x || y!=p.y;}
    bool operator<(const Point& p)const{return x==p.x?y<p.y:x<p.x;}

    DD det(const Point P)const {return (P.x*y) - (x*P.y);}
    DD det(const Point &P0,const Point& P1)const {return (P1.x - P0.x)*(y - P0.y) - (x - P0.x)*(P1.y - P0.y);}
    bool isColinear(const Point &P0,const Point& P1)const{return (det(P0,P1)==0);}
    bool isOnLeft(const Point &P0,const Point& P1)const{return (det(P0,P1)>0);}
    bool isOnRight(const Point &P0,const Point& P1)const {return (det(P0,P1)<0);}
    void rotate(DD angle){
        DD auxx,auxy;
        auxx = x*cos(angle)-y*sin(angle);
        auxy = x*sin(angle)+y*cos(angle);
        x = auxx;
        y = auxy;
    }
};
struct Line{
    DD A,B,C;
    Line(Point p1,Point p2){
        A = p1.y-p2.y;
        B = p2.x-p1.x;
        C = ((-A)*p1.x)-(B*p1.y);
    }
    bool operator==(const Line& l)const{
        return (A/l.A==B/l.B && A/l.A==C/l.C && B/l.B==C/l.C);
    }
    bool operator<(const Line& line)const{
        if(A==line.A){
            return B==line.B?C<line.C:B<line.B;
        }
        return A<line.A;
    }
    bool intersectingPoint(const Line& l,DD& X,DD& Y){
        DD det = A*l.B-l.A*B;
        if(fabs(det)==0.0){
            return false;
        }
        X = (B*l.C-C*l.B)/det;
        Y = (C*l.A-A*l.C)/det;
        return true;
    }
};

int main(){
    double l,w,h,theta,X,Y,area;
    while(scanf("%lf %lf %lf %lf",&l,&w,&h,&theta)==4){
        theta = (theta*PI)/180.0;
        Point upperLeft(0,h);
        upperLeft.rotate(theta);
        Line line1(upperLeft,Point(upperLeft.x+10,upperLeft.y));

        Point upperRight(l,h);
        upperRight.rotate(theta);

        Point bottomRight(l,0);
        bottomRight.rotate(theta);

        Line line2(bottomRight,upperRight);

        line1.intersectingPoint(line2,X,Y);


        if((X>=upperRight.x && X<=bottomRight.x) || (X<=upperRight.x && X>=bottomRight.x)){
            area = fabs(upperLeft.det(Point(X,Y))/2);
            area+= fabs(bottomRight.det(Point(X,Y))/2);
            printf("%.3lf mL\n",area*w);
        }else{
            Line line3(Point(0,0),bottomRight);
            line1.intersectingPoint(line3,X,Y);
            printf("%.3lf mL\n",fabs(upperLeft.det(Point(X,Y))/2.0)*w);
        }
    }
    return 0;
}
