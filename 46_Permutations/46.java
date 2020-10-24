class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        int[] visited = new int[nums.length];
        backTrace(res,nums,new ArrayList<Integer>(),visited);
        return res;
    }
    public void backTrace(List<List<Integer>> res,int[] nums, ArrayList<Integer> temp,int[] visited){
        if(temp.size()==nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }

        for(int i=0;i<nums.length;i++){
            if(visited[i]==1) continue;
            visited[i]=1;
            temp.add(nums[i]);
            backTrace(res,nums,temp,visited);
            visited[i]=0;
            temp.remove(temp.size()-1);
        }
    }
}
