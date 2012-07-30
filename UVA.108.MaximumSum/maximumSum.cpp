#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
int linear(int row[],int NN){

    int maxSum = row[0], maxStartIndex = 0, maxEndIndex=0;
		int currentMaxSum = 0;
		int currentStartIndex = 1;
		int currentEndIndex;
    for(currentEndIndex = 1;currentEndIndex < NN;++currentEndIndex){
        currentMaxSum = currentMaxSum + row[currentEndIndex];
        if(currentMaxSum > maxSum){
          	maxSum = currentMaxSum;
						maxStartIndex = currentStartIndex;
						maxEndIndex = currentEndIndex;
        }
        if(currentMaxSum < 0){
            currentMaxSum = 0;
            currentStartIndex = currentEndIndex + 1;
        }
		}
    return maxSum;
}
int linear2(int row[],int NN){
    int maxSum = row[0];
    int auxMaxSum = row[0];
    for(int i = 1;i<NN;++i){
        if(row[i]>0){
            auxMaxSum+=row[i];
        }
        else{
            maxSum = max(maxSum,auxMaxSum);
            auxMaxSum = row[i];
        }
    }
    return max(maxSum,auxMaxSum);
}
int main(){
    int NN;
    int mat[150][150];
    int array[150];
    while(scanf("%d",&NN)==1){
        for(int i = 0;i<NN;++i){
            for(int j = 0;j<NN;++j){
                scanf("%d",mat[i]+j);
            }
        }
        int maxSum = mat[0][0];

        for(int i = 0;i<NN;++i){
            for(int j = i;j<NN;++j){
                for(int k = 0;k<NN;++k){
                    if(j==i){
                        array[k] = mat[j][k];
                    }
                    else{
                        array[k] += mat[j][k];
                    }
                }
                maxSum = max(maxSum,max(linear(array,NN),linear2(array,NN)));
            }
        }
        printf("%d\n",maxSum);
    }
    return 0;
}
