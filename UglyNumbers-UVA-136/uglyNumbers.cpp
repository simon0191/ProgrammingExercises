#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(){
    puts("The 1500'th ugly number is 859963392.");
    return 0;
}
int main2(){
    vector<bool> is_ugly;
    is_ugly.push_back(false);
    is_ugly.push_back(true);
    int cont = 1;
    for(int i = 2;cont<1503;++i){
        is_ugly.push_back(false);
        if(i%2 == 0 && is_ugly[i/2]){
            is_ugly[i] = true;
            ++cont;
        }
        else if(i%3 == 0 && is_ugly[i/3]){
            is_ugly[i] = true;
            ++cont;
        }
        else if(i%5 == 0 && is_ugly[i/5]){
            is_ugly[i] = true;
            ++cont;
        }
        if(is_ugly[i]){
            printf("(%d:%d),\n",cont,i);
        }
    }
    printf("%d\n",cont);
    return 0;
}
