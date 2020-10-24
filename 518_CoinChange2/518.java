//java version
package com.zhang.dp;
public class Solution_518 {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1];
        dp[0] = 1;
        for (int coin:coins)
            for (int i = coin; i <= amount; i++)
                dp[i] +=dp[i-coin];
        return dp[amount];
    }

    public static void main(String[] args) {
        Solution_518 solution_518 = new Solution_518();
        int[] amount = {1,2,5};
        int res = solution_518.change(5, amount);
        System.out.println(res);
    }
}