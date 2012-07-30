#include <cstdio>
#include <map>
#include <vector>
#include <set>

#define abs(X) (X<0?(-X):(X))

using namespace std;

struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool operator<(const Point& p)const{
        return x==p.x?y<p.y:x<p.x;
    }
    bool operator==(const Point& p)const{
        return x==p.x && y==p.y;
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
        int GCD = gcd(gcd(abs(A),abs(B)),abs(C));
        if(GCD){
            A/=GCD;
            B/=GCD;
            C/=GCD;
        }
    }
    Line(int x1,int y1,int x2,int y2){
        A = y1-y2;
        B = x2-x1;
        C = ((-A)*x1)-(B*y1);
        int GCD = gcd(gcd(abs(A),abs(B)),abs(C));
        if(GCD){
            A/=GCD;
            B/=GCD;
            C/=GCD;
        }
    }
    bool operator==(const Line& l)const{
        return (A==l.A && B==l.B && C==l.C);
    }
    bool operator<(const Line& line)const{
        if(A==line.A){
            return B==line.B?C<line.C:B<line.B;
        }
        return A<line.A;
    }
};
int main(){
    Point p;
    set<Point> ms;

    while(scanf("%d %d",&p.x,&p.y)==2){
        if(p.x==0 && p.y==0){
            if(ms.empty())break;
            else{
                //Procesar
                vector<Point> points(ms.begin(),ms.end());
                ms.clear();
                set<Line> lines;
                bool ff = true;
                for(int i = 0;i<points.size()-2;++i){
                    for(int j = i+1;j<points.size()-1;++j){
                        if(!(points[j] == points[i])){
                            Line line(points[i],points[j]);
                            if(lines.find(line) == lines.end()){
                                bool first = true;
                                for(int k = j+1;k<points.size();++k){
                                    Line line2(points[j],points[k]);
                                    if(line == line2){
                                        if(ff){
                                            puts("The following lines were found:");
                                            ff = false;
                                        }
                                        if(first){
                                            printf("(%4d,%4d)(%4d,%4d)",points[i].x,points[i].y,points[j].x,points[j].y);
                                            lines.insert(line);
                                            first = false;
                                        }
                                        printf("(%4d,%4d)",points[k].x,points[k].y);
                                    }
                                }
                                if(!first){
                                    puts("");
                                }
                            }
                        }
                    }
                }
                //Procesar
                if(ff){
                    puts("No lines were found");
                }
            }
        }else{
            ms.insert(p);
        }
    }
    return 0;
}
