//dp 
//淦回溯竟然超时了 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	int len = nums.size();
		vector<int>points(len+2,0);
		points[0]=points[len+1]=1;
		for(int i=1; i<=len; i++){
			points[i] = nums[i-1];
		}
		int dp[len+2][len+2];
		memset(dp,0,sizeof(dp));
		for(int i=len; i>=0; i--){
			for(int j=i+1; j<len+2; j++){
				for(int k = i+1; k<j; k++){
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j] + points[i]*points[k]*points[j]);
				}
			}
		}
		return dp[0][len+1];
    }
};
