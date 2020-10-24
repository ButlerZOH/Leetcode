//һֱ�ң������С��0�ģ��ͷ�ת����֤С��Ҫ��С�ʹ��Ҫ���
//���磺[-3,4,-5]=60,
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int maxValue=1,minValue = 1, maxres = INT_MIN;
        for(int i=0; i<nums.size();i++){

            if(nums[i]<0){
                int a = maxValue;
                maxValue = minValue;
                minValue = a;
            }

            maxValue=max(nums[i], maxValue*nums[i]);
            minValue = min(nums[i],minValue*nums[i]);
            maxres = max(maxres,maxValue);
        }
        return maxres;
    }
};
int main() {
    Solution a;
    vector<int> test ={2,3,-2,4};
    int res = a.maxProduct(test);
    cout<<res<<endl;
}
