//c++ version
class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n == 0)return 0;
        vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(n+1,0));
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l+len-1 < n; ++l) {
                int r = l+len-1;
                dp[l][r] = dp[l+1][r]+1;
                for(int k = l+1; k<=r; k++){
                    if(s[l]==s[k])
                        dp[l][r]=min(dp[l][r], dp[l][k-1] + dp[k+1][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};