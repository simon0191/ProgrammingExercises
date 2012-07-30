#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#define Vector2 Point
#define abs(X) ((X)<0?-(X):(X))
#define EPS 1e-8
#define DD long double
using namespace std;
const DD PI = acos(-1);

struct Point{
    DD x,y;
    Point(){x=y=0;}
    Point(DD _x,DD _y):x(_x),y(_y){}

    bool operator==(const Point& p)const{return x==p.x && y==p.y;}
    bool operator!=(const Point& p)const{return x!=p.x || y!=p.y;}
    bool operator<(const Point& p)const{return x==p.x?y<p.y:x<p.x;}

    DD det(const Point &P)const {return (P.x*y) - (x*P.y);}
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
    DD A,B,C,angleA,angleB,angleC,triangleArea,X,Y,exteriorArea,X2,Y2,interiorArea;
    Point p0(0,0);
    while(cin>>A>>B>>C){
        /*A*=10.0;
        B*=10.0;
        B*=10.0;
*/
        angleC = fabs(acos( (A*A+B*B-C*C)/(2*A*B) ));
        angleB = fabs(acos( (A*A+C*C-B*B)/(2*A*C) ));

        cout<<fixed;
        //cout<<"angleC: "<<setprecision(4)<<angleC<<endl;
        Point p1(A,0);
        Point p2(B,0);
        p2.rotate(fabs(angleC));
        //printf("%lf %lf\n",p2.x,p2.y);
        triangleArea = fabs(p1.det(p2)/2);
        //printf("%.4lf\n",triangleArea);

        Point p01(p1.x,p1.y);
        p01.rotate(PI/2);
        p01.x+=(p1.x/2);
        p01.y+=(p1.y/2);

        Point p02(p2.x,p2.y);
        p02.rotate(PI/2);
        p02.x+=(p2.x/2);
        p02.y+=(p2.y/2);

        Line pp1(p01,Point(p1.x/2,p1.y/2));
        Line pp2(p02,Point(p2.x/2,p2.y/2));

        pp1.intersectingPoint(pp2,X,Y);
        //printf("Circle: %.4lf %.4lf\n",double(X),double(Y));
        //cout<<"Circle: "<<setprecision(4)<<X<<" "<<Y<<endl;
        exteriorArea = (PI*(X*X+Y*Y))-triangleArea;
        printf("%.4lf ",(double)exteriorArea);
        //cout<<setprecision(4)<<exteriorArea<<" ";


        Point ppp1(p1.x,p1.y);
        ppp1.rotate(angleC/2);

        Point ppp2(-A,0);
        ppp2.rotate(-(angleB/2));
        ppp2.x+=p1.x;
        Line line1(p0,ppp1);
        Line line2(p1,ppp2);

        line1.intersectingPoint(line2,X,Y);
        Line _01(p0,p1);

        p1.rotate(PI/2);
        p1.x+=X;
        p1.y+=Y;
        Line line3(Point(X,Y),p1);

        line3.intersectingPoint(_01,X2,Y2);

        interiorArea = ((X-X2)*(X-X2)+(Y-Y2)*(Y-Y2))*PI;
        printf("%.4lf %.4lf\n",double(triangleArea-interiorArea),(double)interiorArea);
        //cout<<setprecision(4)<<(triangleArea-interiorArea)<<" "<<interiorArea<<endl;

    }
    return 0;
}

