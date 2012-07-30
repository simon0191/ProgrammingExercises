#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    Point operator-(Point p){
        return Point(x-p.x,y-p.y);
    }
    Point operator+(Point p){
        return Point(x+p.x,y+p.y);
    }
    bool operator==(Point p){
        return p.x == x && p.y == y;
    }
};
int main(){
    Point p[4];
    Point p2[3];
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y) == 8){
        int r = 0,r2 = 0,r3 = 0;
        for(int i = 0;i<3;++i){
            for(int j = i+1;j<4;++j){
                if(p[i] == p[j]){
                    r = i;
                    r2 = j;
                    p2[2] = p[i];
                    for(int k = 0;k<4;++k){
                        if(k!= r && k != r2){
                            p2[0] = p[k];
                            r3 = k;
                            break;
                        }
                    }
                    for(int k = 0;k<4;++k){
                        if(k!= r && k != r2 && k!= r3){
                            p2[1] = p[k];
                            break;
                        }
                    }
                }
            }
        }
        Point res = p2[1]+(p2[0]-p2[2]);
        printf("%.3lf %.3lf\n",res.x,res.y);
    }
    return 0;
}
