#include <iostream>
#include <cstdio>
using namespace std;

struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool operator<(const Point& p)const{
        return x==p.x?y<p.y:x<p.x;
    }
};
int gcd(int a,int b){
    if(b){
        return gcd(b,a%b);
    }else{
        return a;
    }
}
struct Line{
    int A,B,C;
    Line(Point p1,Point p2){
        A = p1.y-p2.y;
        B = p2.x-p1.x;
        C = ((-A)*p1.x)-(B*p1.y);
        int GCD = gcd(gcd(A,B),C);
        A/=GCD;
        B/=GCD;
        C/=GCD;
    }
    Line(int x1,int y1,int x2,int y2){
        A = y1-y2;
        B = x2-x1;
        C = ((-A)*x1)-(B*y1);
        int GCD = gcd(gcd(A,B),C);
        A/=GCD;
        B/=GCD;
        C/=GCD;
    }
    bool operator==(const Line& l)const{
        return A==l.A && B==l.B && C==l.C;
    }
};

int main(){
    int cases,det;
    double X,Y;
    int x[4],y[4];
    puts("INTERSECTING LINES OUTPUT");
    scanf("%d",&cases);
    while(cases--){
        for(int i = 0;i<4;++i){
            scanf("%d%d",x+i,y+i);
        }
        Line l1(x[0],y[0],x[1],y[1]);
        Line l2(x[2],y[2],x[3],y[3]);
        det = l1.A*l2.B-l2.A*l1.B;
        if(l1==l2){
            puts("LINE");
        }else if(det==0){
            puts("NONE");
        }else{
            X = double(l1.B*l2.C-l1.C*l2.B)/double(det);
            Y = double(l1.C*l2.A-l1.A*l2.C)/double(det);
            printf("POINT %.2lf %.2lf\n",X,Y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}
