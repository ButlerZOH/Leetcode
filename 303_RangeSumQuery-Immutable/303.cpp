//
// Created by hp on 2020/10/4.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp.reserve(nums.size()+2);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i+1] = dp[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

int main(){
    vector<int> test={-2, 0, 3, -5, 2, -1};
    NumArray* a = new NumArray(test);
    int param_1 = a->sumRange(2,5);
    cout<<param_1<<endl;
}
