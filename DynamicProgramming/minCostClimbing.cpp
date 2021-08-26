#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>

//g++ -std=c++11 .cpp -o      

using namespace std;

int main()
{
  vector<int> nums = {1,2,7};
  
  int sum = 0;
  for(int i = 0; i<nums.size();i++){
      sum+= nums[i];
  }

}


