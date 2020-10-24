package com.zhang.recall2;

import java.util.ArrayList;
import java.util.List;

public class Solution_131 {
    public List<List<String>> partition(String s) {
        int length = s.length();
        List<List<String>> res = new ArrayList<>();
        if (length == 0){
            return res;
        }
        backTrace(0,length,s,res,new ArrayList());

        return res;
    }
    private void backTrace(int start, int len,String str, List<List<String>> res, ArrayList stack){
        if (len == start) {
            res.add(new ArrayList<>(stack));
            return;
        }
        for (int i = start; i < len; i++) {

            if (!checking(str,start,i)){
                continue;
            }
            stack.add(str.substring(start,i+1));
            backTrace(i+1,len,str,res,stack);
            stack.remove(stack.size()-1);
        }

    }

    private boolean checking(String s1, int start, int end){
        while (start<end){
            if (s1.charAt(start) != s1.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;

    }

    public static void main(String[] args) {
        Solution_131 solution_131 = new Solution_131();
        List<List<String>> res = solution_131.partition("aab");
        System.out.println(res.toString());
    }
}