#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPalindrome(string &str){
    int aux = str.size()%2?str.size()/2+1:str.size()/2;
    int last = str.size()-1;
    for(int i = 0;i<aux;++i){
        if(str[i]!=str[last-i])return false;
    }
    return true;
}
void sum(string &str,string &str2,string &resp){
    stringstream ss,s2;
    ss<<str<<" "<<str2;
    unsigned long long a,b;
    ss>>a>>b;
    //cout<<a<<"#"<<b<<endl;
    s2<<a+b;
    s2>>resp;
}
int main(){
    int cases,cont;
    string str,str2;
    cin>>cases;
    while(cases--){
          cin>>str;
          cont = 0;
          while(!isPalindrome(str)){
              str2 = string(str.rbegin(),str.rend());
              sum(str,str2,str);
              ++cont;
          }
          cout<<cont<<" "<<str<<endl;
    }
    return 0;
}

