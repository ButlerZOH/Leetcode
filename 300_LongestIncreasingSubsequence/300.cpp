#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int n = nums.size();
        //dp[i] 表示以第i个结尾的最长上升子序列的长度
        vector<int> dp(n,1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int res = *max_element(dp.begin(),dp.end());
        return res;
    }
};
int main(){
    Solution a;
    vector<int> temp = {10,9,2,5,3,7,101,18};
    int res = a.lengthOfLIS(temp);
    cout<<res<<endl;
    return 0;
}
