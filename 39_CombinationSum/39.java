class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        if(candidates.length==0)
            return res;
        backTrace(res,candidates,target,new ArrayList<Integer>(),0);
        return  res;
    }

    public void backTrace(List<List<Integer>> res,int[] candidates, int target,ArrayList<Integer> temp ,int start){
        if(target==0){
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=start;i<candidates.length &&target-candidates[i]>=0;i++){
            temp.add(candidates[i]);
            backTrace(res,candidates,target-candidates[i],temp,i);
            temp.remove(temp.size()-1);
        }

    }
}
