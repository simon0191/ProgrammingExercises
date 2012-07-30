#include <iostream>
using namespace std;
template <unsigned long long Nbuilds, int Pos> struct Triangle;
template<>
struct Triangle<1,1> {
    static const unsigned long long val = 1;
};
template <unsigned long long Nbuilds>
struct Triangle<Nbuilds,0> {
    static const unsigned long long val = 0;
};
struct Triangle<0,Pos> {
    static const unsigned long long val = 0;
};
template <unsigned long long Nbuilds,int Pos>
struct Triangle<Nbuilds,Pos> {
    static const unsigned long long val = Pos + Triangle<(Nbuilds-1),Pos>::val;
};



int main(){
    cout<<Triangle<6,2>::val<<endl;
    return 0;
}
