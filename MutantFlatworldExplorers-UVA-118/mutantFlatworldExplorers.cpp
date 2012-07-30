#include <cstdio>
#include <cstring>
#include <cmath>
#define FREE 0
#define IGNORE 2
#define I(X) (int)(X)
const double HALF_PI  = acos(0.0);
const double PI  = 2*HALF_PI;

struct Vector2d{
    double x,y;
    Vector2d(){x=y=0;};
    Vector2d(double _x,double _y):x(_x),y(_y){}
    Vector2d rotate(double radians){
        double COS = cos(radians);
        double SIN = sin(radians);
        return Vector2d((COS*x-SIN*y),
                        (SIN*x+COS*y));
    }
};

int main(){
    int limX,limY,x,y,mat[60][60];
    memset(mat,FREE,sizeof(mat));
    char d,str[105];
    bool lost;
    Vector2d dir;
    scanf("%d%d",&limX,&limY);
    while(scanf("%d %d %c",&x,&y,&d)){
        scanf("%s",str);
        switch(d){
            case 'N':dir.x=0;dir.y=1;break;
            case 'S':dir.x=0;dir.y=-1;break;
            case 'E':dir.x=1;dir.y=0;break;
            case 'W':dir.x=-1;dir.y=0;break;
        }
        lost = false;
        for(int i = 0;str[i] && !lost;++i){
            switch(str[i]){
                case 'R':{
                    dir = dir.rotate(-HALF_PI);
                }break;
                case 'L':{
                    dir = dir.rotate(HALF_PI);
                }break;
                case 'F':{
                    if(mat[I(x)][I(y)] == IGNORE && (x+dir.x<0 || x+dir.x>limX ||  y+dir.y<0 || y+dir.y>limY)){
                    }
                    else if(x+dir.x<0 || x+dir.x>limX ||  y+dir.y<0 || y+dir.y>limY){
                        lost = true;
                        mat[I(x)][I(y)] = IGNORE;
                    }
                    else{
                        x+=dir.x;
                        y+=dir.y;
                    }
                }break;
            }
        }
        printf("%d %d",I(x),I(y));
        if(I(dir.x) == 0){
                if(I(dir.y) == 1){
                    d = 'N';
                }else{
                    d = 'S';
                }
            }else{
                if(I(dir.x) == 1){
                    d = 'E';
                }else{
                    d = 'W';
                }
            }
        printf(" %c",d);
        if(lost){
            printf(" LOST");
        }
        printf("\n");
    }
    return 0;
}
