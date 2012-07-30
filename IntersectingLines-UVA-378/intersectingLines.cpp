#include <cstdio>

bool intersectsLine(int x[],int y[]){
    double m1,m2,b1,b2;
    bool m1i= false,m2i=false;
    if(x[1]==x[0]){
        m1i = true;
        m1 = 0;
    }else{
        m1 = double(y[1]-y[0])/double(x[1]-x[0]);
    }
    if(x[2]==x[3]){
        m2 = 0;
        m2i = true;
    }else{
        m2 = double(y[3]-y[2])/double(x[3]-x[2]);
    }
    if(m1== m2 && m1i == m2i){
        if(m1i && x[0]==x[2]){
            return true;
        }
        else if(m1i){
            return false;
        }
        else{
            b1 = double(y[0])-(m1*double(x[0]));
            b2 = double(y[2])-(m2*double(x[2]));
            return b1 == b2;
        }

    }else{
        return true;
    }
    return 0;
}

int main(){
    int cases,x[4],y[4];
    scanf("%d",&cases);
    printf("INTERSECTING LINES OUTPUT\n");
    while(cases--){
        for(int i = 0;i<4;++i){
            scanf("%d%d",x+i,y+i);
        }
        double m1,m2,b1,b2;
        bool m1i= false,m2i=false;
        if(x[1]==x[0]){
            m1i = true;
            m1 = 0;
        }else{
            m1 = double(y[1]-y[0])/double(x[1]-x[0]);
        }
        if(x[2]==x[3]){
            m2 = 0;
            m2i = true;
        }else{
            m2 = double(y[3]-y[2])/double(x[3]-x[2]);
        }

        if(intersectsLine(x,y)){
            if(m1 == m2){
                printf("LINE\n");
            }
            else{
                if(m1i){
                    b2 = double(y[2])-(m2*double(x[2]));
                    double yf = m2*x[2]+b2;
                    printf("POINT %.2lf %.2lf\n",x[0],yf);
                }else if(m2i){
                    b1 = double(y[0])-(m1*double(x[0]));
                    double yf = m1*x[0]+b1;
                    printf("POINT %.2lf %.2lf\n",x[2],yf);
                }
                else{
                    b1 = double(y[0])-(m1*double(x[0]));
                    b2 = double(y[2])-(m2*double(x[2]));
                    double xf = (b2-b1)/(m1-m2);
                    double yf = (m1*xf+b1);
                    printf("POINT %.2lf %.2lf\n",xf,yf);
                }
            }
        }
        else{
            if(m1i && m2i && x[0]==x[2]){
                printf("LINE\n");
            }else if(m1==m2 && m1i==m2i && m1i == false){
                b1 = double(y[0])-(m1*double(x[0]));
                b2 = double(y[2])-(m2*double(x[2]));
                if(b1 == b2){
                    printf("LINE\n");
                }else{
                    printf("NONE\n");
                }
            }else{
                printf("NONE\n");
            }
        }

    }
    printf("END OF OUTPUT\n");
    return 0;
}
