#include <cstdio>
#include <set>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;
const int SIZE  = ('Z'-'A'+1);
struct SS{
    char c;
    int rep;
    bool operator<(const SS& ss)const{
        if(rep>ss.rep){
            return true;
        }
        return c<ss.c;
    }
};
int main(){
    int nLines;
    char buff[1024],*pt;
    int vec[SIZE];

    while(gets(buff)){
        memset(vec,0,sizeof(vec));
        nLines = atoi(buff);
        for(int i = 0;i<nLines;++i){
            gets(buff);
            //puts(buff);
            for(pt = buff;*pt;++pt){
                if(isalpha(*pt)){
                    ++vec[toupper(*pt)-'A'];
                }
            }
        }
        set<SS> sete;
        for(int i = 0;i<SIZE;++i){
            if(vec[i]){
                sete.insert(SS{i+'A',vec[i]});
            }
        }
        set<SS>::iterator it = sete.begin();
        for(;it!=sete.end();++it){
            printf("%c %d\n",it->c,it->rep);
        }
    }
    return 0;
}
