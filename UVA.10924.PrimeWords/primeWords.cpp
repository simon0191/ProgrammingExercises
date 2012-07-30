#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>

using namespace std;

int f(char c){
    if(isupper(c)){
        return c-'A'+27;
    }
    else{
        return c-'a'+1;
    }
}
int main(){
    char buff[1024];
    int isPrime[1062];
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = isPrime[2] = true;
    const int root = sqrt(1062)+1;
    for(int i = 2;i<=root;++i){
        if(isPrime[i]){
            for(int j = i*2;j<1062;j+=i){
                isPrime[j] = false;
            }
        }
    }
    while(scanf("%s",buff)==1){
        int sum = 0;
        for(int i = 0;buff[i];++i){
            sum+=f(buff[i]);
        }
        if(isPrime[sum]){
            puts("It is a prime word.");
        }
        else{
            puts("It is not a prime word.");
        }
    }
    return 0;
}

