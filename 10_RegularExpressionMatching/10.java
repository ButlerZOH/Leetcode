package com.zhang.dp;

public class Solution_10 {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();
        s = " "+s;
        p = " "+p;

        boolean[][] dp = new boolean[n+1][m+1];

        for (int i=0 ;i<=n; i++){
            for (int j=0; j<=m; j++){
                if (i == 0 && j == 0)dp[i][j] = true;
                else {
                    if (j+1<=m && p.charAt(j+1) == '*') continue;
                    if (p.charAt(j) != '*'){
                        if (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j))
                            if (i>0 && j>0)
                                dp[i][j] = dp[i-1][j-1];

                    }
                    else {
                        if (j>=2)dp[i][j] = dp[i][j-2];
                        if (i>0 && j>0){
                            if (p.charAt(j-1) == '.' || s.charAt(i) == p.charAt(j-1))
                                if (dp[i-1][j])
                                    dp[i][j]=true;
                        }
                    }
                }
            }
        }
        return dp[n][m];

    }
}

