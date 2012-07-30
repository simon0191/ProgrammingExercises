#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    unsigned long long n,sq;
    while(scanf("%llu",&n)==1 && n){
        sq = sqrt(n);
        if(  (sq*sq == n) ){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    return 0;
}
