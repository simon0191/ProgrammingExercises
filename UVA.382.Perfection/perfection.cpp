#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
const int ROOT60 = sqrt(60000)+1;
int main(){
    int n,sq,sum,cont;
    puts("PERFECTION OUTPUT");
    while(scanf("%d",&n)==1 && n){
        cont = sum = 0;
        sq = n/2    ;
        for(int i = 1;i<=sq;++i){
            if(n%i == 0){
                sum+=i;
                ++cont;
            }
        }
        printf("%5d  ",n);
        if(sum == n){
            puts("PERFECT");
        }
        else if(sum>n){
            puts("ABUNDANT");
        }
        else{
            puts("DEFICIENT");
        }
    }
    puts("END OF OUTPUT");
    return 0;
}
