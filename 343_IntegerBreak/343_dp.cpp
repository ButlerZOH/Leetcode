#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
vector<int> memo;
class Solution {
private:
    //将n进行分割（至少分割成两部分），可以获得最大的乘积
    int max3(int a, int b, int c){
        return max(a, max(b,c));
    }
public:
    int integerBreak(int n) {
        assert(n>=2);
        vector<int> memo(n+1, -1);
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            //求解memo[i]
            for (int j = 1; j <= i-1; j++) {
                //i = j + i-j;
                memo[i] = max3(memo[i], j*(i-j), j*memo[i-j]);
            }
        }
        return memo[n];
    }
};
