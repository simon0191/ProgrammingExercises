#include <limits>
#include <set>
#include <cstdio>
#include <vector>
#include <cmath>
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
    bool operator==(const Line& line)const{
        double det = A*line.B-line.A*B;
        double det2 = A*line.C-line.A*C;
        double det3 = C*line.B-line.C*B;
        return fabs(det)<EPS && fabs(det2)<EPS && fabs(det3)<EPS;
    }
};

struct Point{
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
int main(){
    int cases,nPoints,ans;
    Point p;
    scanf("%d",&cases);
    for(int c = 1;c<=cases;++c){
        printf("Data set #%d contains ",c);
        scanf("%d",&nPoints);
        set<Point> points;
        vector<Line> lines;
        vector<set<Point> > cont;
        ans = 0;
        while(nPoints--){
            scanf("%lf %lf",&p.x,&p.y);
            points.insert(p);
        }
        if(points.size()>1){
            vector<Point> pointsV(points.begin(),points.end());
            for(int i = 0;i<pointsV.size();++i){
                for(int j = i+1;j<pointsV.size();++j){
                    Line line(pointsV[i].x,pointsV[i].y,pointsV[j].x,pointsV[j].y);
                    bool found = false;
                    for(int k = 0;k<lines.size() && !found;++k){
                        if(lines[k] == line){
                            found = true;
                            cont[k].insert(pointsV[i]);
                            cont[k].insert(pointsV[j]);
                            if(ans<cont[k].size()){
                                ans = cont[k].size();
                            }
                        }
                    }
                    if(!found){
                        cont.push_back(set<Point>());
                        cont.rbegin()->insert(pointsV[i]);
                        cont.rbegin()->insert(pointsV[j]);
                        lines.push_back(line);
                        if(ans < 2){
                            ans = 2;
                        }
                    }
                }
            }
            printf("%d gnus, out of which a maximum of %d are aligned.\n",points.size(),ans);
        }else{
            printf("a single gnu.\n");
        }
    }
    return 0;
}
