#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n){
    int **t = new int*[n+1];
    for(int i = 0;i<n+1;i++){
        t[i] = new int[w+1];
    }
    
    for(int i = 0; i<n+1;i++){
        for(int j = 0; j<w+1;j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
            else if(wt[i-1] <= j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]  = t[i-1][j];
            }
        }
    }
    
    return t[n][w];
}
int main()
{
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int w = 7;
    int n = wt.size();
    cout<<knapsack(wt,val,w,n)<<endl;

    return 0;
}

