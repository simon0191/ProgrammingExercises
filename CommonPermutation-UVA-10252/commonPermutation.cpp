#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int NN = 'z'-'a'+1;
int main(){
    char s1[1024],s2[1024];
    int marks[NN],marks2[NN],aux;
    while(gets(s1) && gets(s2)){
        memset(marks,0,sizeof(marks));
        memset(marks2,0,sizeof(marks2));
        for(int i=0;s1[i];++i){
            marks[s1[i]-'a']++;
        }
        for(int i=0;s2[i];++i){
            marks2[s2[i]-'a']++;
        }
        for(int i = 0;i<NN;++i){
            aux = min(marks[i],marks2[i]);
            for(int j = 0;j<aux;++j)printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}
