#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
vector<int> memo;
class Solution {
private:
    //��n���зָ���ٷָ�������֣������Ի�����ĳ˻�
    int max3(int a, int b, int c){
        return max(a, max(b,c));
    }
public:
    int integerBreak(int n) {
        assert(n>=2);
        vector<int> memo(n+1, -1);
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            //���memo[i]
            for (int j = 1; j <= i-1; j++) {
                //i = j + i-j;
                memo[i] = max3(memo[i], j*(i-j), j*memo[i-j]);
            }
        }
        return memo[n];
    }
};
