#include <iostream>
#include <algorithm>
using namespace std;
bool func(char a,char b){
    char aa = toupper(a),bb=toupper(b);
    if(aa == bb){
        return a<b;
    }
    return aa < bb;
}
int main(){
    int n;
    string str;
    cin>>n;
    bool first = true;
    while(n--){
        cin>>str;
        sort(str.begin(),str.end(),func);
        do{
            cout<<str<<endl;
        }while(next_permutation(str.begin(),str.end(),func));
    }
    return 0;
}
