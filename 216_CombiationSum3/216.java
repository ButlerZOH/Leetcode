class Solution {
public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        if (k <= 0 || n <= 0 || k >= n) {
            return res;
        }
        BackTrace(res,n,k,1,new ArrayList<Integer>());
        return res;
    }

    private void BackTrace(List<List<Integer>> res, int target, int k, int start, ArrayList<Integer> temp){

        if (target == 0 && temp.size() == k){
            res.add(new ArrayList<>(temp));
            return;
        }

        for (int i = start; i <=9 && target-i>=0; i++) {
            temp.add(i);
            BackTrace(res, target-i,k,i+1, temp);
            temp.remove(temp.size()-1);
        }
    }
}
//老套模板了
