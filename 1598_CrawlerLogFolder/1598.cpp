class Solution {
public:
    int minOperations(vector<string>& logs) {
        int index = 0;
        if (logs.size() == 0){
            return 0;
        }
        for (int i = 0; i < logs.size(); ++i) {
        	//如果移动到父文件夹并且当前不在父文件夹下就路径-1 
        	// logs[i] == "../"和 index>0这两个条件不能写在一起，不然else的情况会多，就有bug 
            if(logs[i] == "../"){
                if(index>0) {
                    index--;
                }
            //当前路径保持不变 
            } else if(logs[i] == "./"){
                index+=0;
            }
            //进入到子文件+1 
            else{
                index++;
            }
        }
        return index;
    }
};
