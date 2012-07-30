#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>


const double PI = acos(-1);
const double COS45 = fabs(cos(PI/4.0));

int main(){
    char buff[1000000],*pch,*cord,str[1000000];
    double x,y,aux,dist;
    char auxc;
    int map = 1;
    while(gets(buff) && buff[0]!='E'){
        x=y=0.0;
        pch = strtok (buff,",.");
        while(pch != NULL){
            //printf("Num: 6,Coord: %s\n",pch);
            for(int i = 0;pch[i];++i){
                if(isalpha(pch[i])){
                    auxc = pch[i];
                    pch[i] = 0;
                    aux = atoi(pch);
                    pch[i] = auxc;
                    pch+=i;
                    cord = pch;
                    break;
                }
            }
            if(!strcmp(cord,"N")){
                y+=aux;
            }
            else if(!strcmp(cord,"S")){
                y-=aux;
            }
            else if(!strcmp(cord,"E")){
                x+=aux;
            }
            else if(!strcmp(cord,"W")){
                x-=aux;
            }
            else if(!strcmp(cord,"NE")){
                x+=COS45*aux;
                y+=COS45*aux;
            }
            else if(!strcmp(cord,"NW")){
                x-=COS45*aux;
                y+=COS45*aux;
            }
            else if(!strcmp(cord,"SE")){
                x+=COS45*aux;
                y-=COS45*aux;
            }
            else if(!strcmp(cord,"SW")){
                x-=COS45*aux;
                y-=COS45*aux;
            }
            pch = strtok (NULL,",.");
        }
        dist = sqrt(x*x+y*y);
        printf("Map #%d\n",map++);
        printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
        printf("The distance to the treasure is %.3lf.\n\n",dist);
    }
    return 0;
}
