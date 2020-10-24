//²¨·åÊÇfalse£¬²¨¹ÈÊÇtrue
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2){
            return n;
        }
        bool flag = false;
        int res = 1,j=1,start = 0;
        while (start<n-1){
            if (nums[start] != nums[start+1]){
                if (nums[start] > nums[start+1]){
                    flag = true;
                }
                res++;
                start++;
                j=start;
                break;
            }
            start++;
        }
        if (start == n-1)
            return res;
        for (int i = start+1; i < n; ++i) {
            if (nums[j] == nums[i])
                continue;
            if (flag && nums[j]<nums[i]){
                    res++;
                    flag = false;
            }
            else if(!flag && nums[j]>nums[i]){
                    res++;
                    flag = true;
            }
            j=i;
        }
        return res;
    }
};
