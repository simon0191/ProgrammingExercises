#include <iostream>
#include <cmath>
#include <map>
#define LD long double
#define UL unsigned long long
#define RR 6378
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
int spherical_distance(double lat1,double lon1,double lat2,double lon2) {

double dlon = lon2 - lon1;
double dlat = lat2 - lat1;
double a = _pow(sin(dlat/2)) + cos(lat1) * cos(lat2) * _pow(sin(dlon/2));
double c = 2 * atan2(sqrt(a), sqrt(1-a));
double d = RR * c;

return d+0.5;
}
int main(){
    map<string,Vector3> cities;
    map<string,Vector3>::iterator it,it2;
    string city,city2;
    LD theta,phi;
    while(cin>>city && city!="#"){
        cin>>theta>>phi;
        cities[city] = Vector3(theta,phi);
    }
    while(cin>>city>>city2 && city!="#" || city2!="#"){
        it = cities.find(city);
        it2 = cities.find(city2);
        if(it == cities.end() || it2 == cities.end()){
           cout<<city<<" - "<<city2<<endl<<"Unknown"<<endl;
        }
        else{       
            cout<<city<<" - "<<city2<<endl<<spherical_distance((it->second).theta,(it->second).phi,(it2->second).theta,(it2->second).phi)<<" km"<<endl;
//            cout<<city<<" - "<<city2<<endl<<_distance(it->second,it2->second)<<" km"<<endl;
        }
    }
    return 0;
}
