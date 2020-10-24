class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        backTrack(res,0,candidates,target,new ArrayList<Integer>());
        return res;
    }
    public void backTrack(List<List<Integer>> res,int start,int[] candidates, int target,ArrayList<Integer> temp) {
        if(target==0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=start;i<candidates.length &&(target-candidates[i]>=0);i++) {
            if(i>start&& candidates[i]==candidates[i-1]) continue;
            temp.add(candidates[i]);
            backTrack(res,i+1,candidates,target-candidates[i],temp);
            temp.remove(temp.size()-1);
        }
    }
}
