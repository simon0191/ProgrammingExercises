#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#define LD double
#define UL unsigned long long
#define RR 6378.0
const LD PI = 3.141592653589793;
const double XX = PI/180.0;
using namespace std;

struct Vector3{
    LD theta,phi;
    Vector3(){theta=phi=0.0;}
    Vector3(LD theta,LD phi){
        this->theta = theta*XX;
        this->phi = phi*XX;
    }
};
double _pow(double X){
    return X*X;
}
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {

double dlon = lon2 - lon1;
double dlat = lat2 - lat1;
double a = _pow(sin(dlat/2)) + cos(lat1) * cos(lat2) * _pow(sin(dlon/2));
double c = 2 * atan2(sqrt(a), sqrt(1-a));
double d = (RR * c)+0.5;

return d;
}
int main(){
    int n,m,q,a,b,cont=0,aux;
    char buff[22],buff2[22];
    int mat[105][105];
    Vector3 pos[105];
    LD theta,phi;
    while(scanf("%d %d %d",&m,&n,&q)==3 && (n||m||q)){
        map<string,int> cities;
        memset(mat,-1,sizeof(mat));
        for(int i = 0;i<m;++i){
            mat[i][i] = 0;
            scanf("%s %lf %lf",buff,&theta,&phi);
            cities[buff] = i;
            pos[i] = Vector3(theta,phi);
        }
        for(int i = 0;i<n;++i){
            scanf("%s %s",buff,buff2);
            a = cities[buff];
            b = cities[buff2];
            mat[a][b] = (int)spherical_distance(pos[a].theta,pos[a].phi,pos[b].theta,pos[b].phi);
        }
        for(int k = 0; k < m; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    if(mat[i][k] > 0 && mat[k][j]>0){
                        aux = mat[i][k] + mat[k][j];
                        if(mat[i][j] < 0 || mat[i][j] > aux){
                            mat[i][j] = aux;
                        }
                    }
                }
            }
        }
        if(cont)puts("");
        printf("Case #%d\n",++cont);
        for(int i = 0;i<q;++i){
            scanf("%s %s",buff,buff2);
            aux = mat[cities[buff]][cities[buff2]];
            if(aux > 0)printf("%d km\n",aux);
            else puts("no route exists");
        }
        
    }
    return 0;
}
