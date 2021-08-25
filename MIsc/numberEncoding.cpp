#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
  
//g++ -std=c++11 .cpp -o      

using namespace std;  

long calculateValue(long num){
    string numStr = to_string(num);
    char prev = '9';
    long ans = 0;
    for(int i = 0; i<numStr.size();i++){
        if(numStr[i] != prev){
            int base = numStr[i]-'0';
            int exponent = numStr.size() - i;
            ans+=base*pow(10,exponent);
            prev = numStr[i];
        }
    }
    return ans;
}

int solve(string &num, int n, int x,bool tight){
    if(x < 0) return 0;
    if(n == 1){
        if(x >= 0 && x <= 9 ){
            return 1;
        }
        return 0;
    }
    int ans = 0;
    int ub = tight ? num[(num.length()-n)] - '0' : 9;

    for(int dig = 0; dig <= ub; dig++){
        ans += solve(num,n-1,x-dig,(tight&(dig == ub)));
    }

    return ans;
}

int main(){

    string r = "15";
    //cout<<calculateValue(12233322211)<<endl;
    cout<<solve(r,r.length(),5,1)<<endl;
}