class Solution {
private:
    bool checking(vector<int>& nums, int n){
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= n){
                index++;
            }
        }
        if (index == n){
            return true;
        }
        return false;
    }
public:
    int specialArray(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i <= len; ++i) {
            if (checking(nums,i)){
                return i;
            }
        }
        return -1;
    }
};