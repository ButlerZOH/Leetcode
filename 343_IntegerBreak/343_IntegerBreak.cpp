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
    int breakInteger(int n){
        if (n == 1){
            return 1;
        }
        if (memo[n] != -1){
            return memo[n];
        }
        int res = -1;
        for (int i = 1; i <= n-1; i++) {
            //因为breakInteger(n-i)不可能一定等于 n-i,breakInteger(n-i)是计算后的最值
            res = max3(res, i*(n-i), i * breakInteger(n - i));
        }
        memo[n]=res;
        return res;
    }

public:
    int integerBreak(int n) {
        assert(n>=2);
        memo = vector<int>(n+1, -1);
        return breakInteger(n);
    }
};

int main(){
    Solution a;
    int res = a.integerBreak(10);
    cout<<res<<endl;
    return 0;
}
