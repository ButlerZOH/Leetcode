class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        backTrace(res,nums,new ArrayList<Integer>(),visited);
        return res;
    }

    public void backTrace(List<List<Integer>> res, int[] nums, ArrayList<Integer> temp,boolean[] visited){
        if(temp.size()==nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i]) continue;
            /**剪枝条件:1.i>0 防止越界
            2.!visited[i-1]是指前一个数刚刚被撤回时的时候，不可以在递归的*/
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            temp.add(nums[i]);
            visited[i]=true;
            backTrace(res,nums,temp,visited);
            visited[i]=false;
            temp.remove(temp.size()-1);
        }
    }
}
