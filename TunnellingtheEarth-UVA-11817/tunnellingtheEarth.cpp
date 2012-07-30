#include <cstdio>
#include <cmath>
#define RR 6371009.0
const double PI = acos(-1);
const double XX = PI/180.0;
double _pow(double X){
    return X*X;
}
struct Vector3{
    double theta,phi,x,y,z;
    Vector3(){theta=phi=0.0;}
    Vector3(double _phi,double _theta){
        this->theta = _theta*XX;
        this->phi = _phi*XX;
        x = cos(this->theta)*sin(this->phi)*RR;
        y = sin(this->theta)*sin(this->phi)*RR;
        z = cos(this->phi)*RR;
    }
};
double _distance(Vector3& a,Vector3& b){
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    double dz = a.z-b.z;
    return sqrt((dx*dx)+(dy*dy)+(dz*dz));
}
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = _pow(sin(dlat/2)) + cos(lat1) * cos(lat2) * _pow(sin(dlon/2));
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return c;
}
int main(){
    int cases;
    double t1,t2,p1,p2,ang,rect,dist;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lf %lf %lf %lf",&t1,&p1,&t2,&p2);
        Vector3 a(t1,p1);
        Vector3 b(t2,p2);
        t1*=XX;
        t2*=XX;
        p1*=XX;
        p2*=XX;        
        ang = spherical_distance(t1,p1,t2,p2);
        dist = ang*RR;
        rect = RR*sqrt(2 - 2*cos(ang)); 
        //rect = _distance(a,b);
        printf("%.0lf\n",dist-rect);
    }
    return 0;
}
