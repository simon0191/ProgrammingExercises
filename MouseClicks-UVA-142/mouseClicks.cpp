#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>
#define D(X) (double)(X)
using namespace std;
struct Point{
    int x,y;
    double dist;
    bool visible;
    Point(){x=y=0;dist=0.0;visible = true;}
    Point(int _x,int _y):x(_x),y(_y){}
};
struct Region{
    Point tl;
    Point br;
    Region(){}
    Region(int x0,int y0,int x1,int y1):tl(x0,y0),br(x1,y1){}
    bool contains(Point p){
        return (p.x>=tl.x && p.x<=br.x && p.y>=tl.y && p.y<=br.y );
    }
};
double _distance(Point p0,Point p1){
    return (D(p0.x-p1.x)*D(p0.x-p1.x) + D(p0.y-p1.y)*D(p0.y-p1.y));
}
int main(){
    char c;
    int nRegions = 0,nIcons = 0,x0,y0,x1,y1;
    Point icons[55],click;
    Region regions[30];
    bool region,first = true;
    double dist;
    while(scanf("%c",&c) && c!='#'){
        switch (c){
            case 'M':{
                if(first){
                    first = false;
                    for(int i = 0;i<nIcons;++i){
                        icons[i].visible = true;
                        for(int j = 0;j<nRegions && icons[i].visible;++j){
                            if(regions[j].contains(icons[i])){
                                icons[i].visible = false;
                            }
                        }
                    }
                }
                scanf("%d%d",&click.x,&click.y);
                region = false;
                for(int i = nRegions-1;i>=0 && !region;--i){
                    if(regions[i].contains(click)){
                        printf("%c",i+'A');
                        region = true;
                    }
                }
                if(!region){
                    dist = numeric_limits<double>::max();
                    for(int i = 0;i<nIcons;++i){
                        if(icons[i].visible){
                            icons[i].dist = _distance(icons[i],click);
                            dist = min(dist,icons[i].dist);
                        }
                    }
                    for(int i = 0;i<nIcons;++i){
                        if(icons[i].dist == dist){
                            printf("%3d",i+1);
                        }
                    }
                }
                printf("\n");
            }break;
            case 'I':{
                scanf("%d%d",&x0,&y0);
                icons[nIcons++] = Point(x0,y0);
            }break;
            case 'R':{
                scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
                regions[nRegions++] = Region(x0,y0,x1,y1);
            }break;
        }
    }
    return 0;
}
