//
// Created by hp on 2020/10/24.
//c++ version

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(auto coin:coins){
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};

int main(){
    Solution a;
    vector<int> test ={1,2,5};
    int res = a.change(5,test);
    cout<<res<<endl;
}