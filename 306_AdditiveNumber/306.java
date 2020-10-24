package com.zhang.recall2;

//输入: "112358"
//输出: true
//解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

class Solution_306 {
    public boolean isAdditiveNumber(String num) {
        return TrackBack(num,num.length(),0,0,0,0);
    }
    private boolean TrackBack(String s, int len, int idx, long sum, long pre, int k){
        if (idx == len){
            return k>2;
        }

        for (int i=idx; i<len; i++){

            long cur = getCur(s,idx,i);
            if (cur<0){
                continue;
            }

            if (k>=2 && cur != sum){
                continue;
            }

            if(TrackBack(s,len,i+1,cur+pre,cur,k+1)){
                return true;
            }
        }
        return false;

    }

    private long getCur(String num, int l, int r){
        if (l<r && num.charAt(l) == '0'){
            return -1;
        }

        long res = 0;
        while (l<=r){
            res = res*10 + num.charAt(l++)-'0';
        }

        return res;
    }

    public static void main(String[] args) {
        Solution_306 solution_306 = new Solution_306();
        String s = "199100199";
        boolean res = solution_306.isAdditiveNumber(s);
        System.out.println(res);
    }
}