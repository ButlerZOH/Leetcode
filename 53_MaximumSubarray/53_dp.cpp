class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if(nums.empty()){
			return 0;
		} 
		vector<int>memo(nums.size(),0);
		int maxValue = nums[0];
		memo[0] = nums[0];
		for(int i=1; i<nums.size();i++){
			memo[i] = max(nums[i], memo[i-1]+nums[i]);
			maxValue = max(memo[i], maxValue);
		}
		return maxValue;
    }
};
