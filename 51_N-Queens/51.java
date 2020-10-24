class Solution {
public:
    vector<vector<string> > res;
    bool isvalid(int row,int col, vector<string> &path){
    int n=path.size();
    for(int i=0;i<n;i++){
        if(path[i][col]=='Q')
        return false;
    }
    for(int i=row-1,j=col-1;j>=0 &&i>=0;i--,j--){
        if(path[i][j]=='Q')
        return false;
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(path[i][j]=='Q')
        return false;
    }
    return true;
}
void backtrace(vector<string>& path,int row){
    if(row==path.size()){
        res.push_back(path);
        return;
    }
    int n=path[row].size();
    for(int col=0;col<n;col++){
        if(!isvalid(row,col,path)){
            continue;
        }
        path[row][col]='Q';
        backtrace(path,row+1);
        path[row][col]='.';
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n,string(n,'.'));
        backtrace(path,0);
        return res;
    }
};
