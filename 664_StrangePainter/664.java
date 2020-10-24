//java version
package com.zhang.dp;

public class Solution_664 {
    public int strangePrinter(String s) {
        int n = s.length();
        if(n == 0)return 0;
        int[][] dp = new int[n+1][n+1];
        for (int len = 1; len<=n; len++){
            for (int l = 0; l+len-1<n; l++){
                int r = l+len-1;
                dp[l][r] = dp[l+1][r]+1;
                for (int k = l+1; k<=r; k++){
                    if (s.charAt(k) == s.charAt(l))
                        dp[l][r] = Math.min(dp[l][r], dp[l][k-1] + dp[k+1][r]);
                }
            }
        }
        return dp[0][n-1];
    }

    public static void main(String[] args) {
        Solution_664 solution_664 = new Solution_664();

        int res = solution_664.strangePrinter("aba");
        System.out.println(res);
    }
}