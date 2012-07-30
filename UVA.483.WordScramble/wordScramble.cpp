#include <cstdio>
#include <stack>
using namespace std;

int main(){
    char buff[1024];
    int ini,fin;
    while(gets(buff)){
        stack<char> st;
        for(int i = 0;buff[i];++i){
            if(buff[i]==' '){
                while(!st.empty()){
                    printf("%c",st.top());
                    st.pop();
                }
                printf(" ");
            }
            else{
                st.push(buff[i]);
            }
        }
        while(!st.empty()){
            printf("%c",st.top());
            st.pop();
        }
        puts("");
    }
    return 0;
}
