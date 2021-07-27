#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int minimumSubsetSumDiff(vector<int>& nums, int k){

    int **t = new int*[nums.size()+1];
    for(int i = 0; i<nums.size()+1;i++){
        t[i] = new int[k+1];
    }
   
    t[0][0] = 1;
    for(int i = 1; i<nums.size()+1;i++){
        t[i][0] = 1;
    }
    for(int j = 1; j<k+1;j++){
        t[0][j] = 0;
    }

   for(int i = 1;i<nums.size()+1;i++){
       for(int j = 1 ;j<k+1;j++){
           if(nums[i-1] <= j){
            t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
           }
           else if(nums[i-1] > j){
                t[i][j] = t[i-1][j];
           }
       }
   }

   int mx = INT_MIN;

   for (int i = 0; i < (k/2);i++){
       if(t[nums.size()][i] > 0){
           mx = max(mx,i);
       }

   }
   
   return k-2*mx;
}

int main()
{
  vector<int> nums = {1,2,7};
  
  int sum = 0;
  for(int i = 0; i<nums.size();i++){
      sum+= nums[i];
  }

  cout<<minimumSubsetSumDiff(nums,sum)<<endl;

}


