class Solution {
private:
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if (start > end){
            res.push_back(nullptr);
        }
        for (int i = start; i <= end ; ++i) {
            vector<TreeNode*> left = helper(start,i-1);
            vector<TreeNode*> right = helper(i+1,end);

            for (auto l : left){
                for (auto r : right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0){
            return res;
        }
        res = helper(1,n);
        return res;
    }
};
