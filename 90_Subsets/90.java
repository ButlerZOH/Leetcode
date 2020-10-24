class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        res.add(new ArrayList<Integer>());
        backTrace(res,nums,0,new ArrayList<Integer>());
        return res;
    }

    public static void backTrace(List<List<Integer>> res, int[] nums, int start,ArrayList<Integer> temp){
        for(int i=start;i<nums.length;i++){
            if(i>start && nums[i]==nums[i-1])continue;这部分为剪枝部分
            temp.add(nums[i]);
            res.add(new ArrayList<>(temp));
            backTrace(res,nums,i+1,temp);
            temp.remove(temp.size()-1);
        }
    }
}
