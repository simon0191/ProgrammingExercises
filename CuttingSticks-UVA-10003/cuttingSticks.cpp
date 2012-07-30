#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <climits>

using namespace std;

int main(){
    int n,n_cortes,aux;

    while(cin>>n && n){
        set<int> cortes;
        cortes.insert(0);
        cortes.insert(n);
        cin>>n_cortes;
        for(int i = 0;i<n_cortes;++i){
            cin>>aux;
            cortes.insert(aux);
        }
        vector<int> vec(cortes.begin(),cortes.end());
        vector<int> aux_v(n_cortes+2,0);
        vector<vector<int> > mat(n_cortes+2,aux_v);
        for(int i = n_cortes;i>0;--i){
            for(int j = n_cortes+2-i,k=0; j<n_cortes+2;++j,++k){
                mat[k][j] = vec[j]-vec[k];
                int minn = INT_MAX;
                for(int l=k+1;l<j;++l){
                    minn = min(minn,mat[k][l]+mat[l][j]);
                }
                mat[k][j]+=minn;
            }
        }
        cout<<"The minimum cutting is "<<mat[0][n_cortes+1]<<"."<<endl;
    }
    return 0;
}
