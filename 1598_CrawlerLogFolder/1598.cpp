class Solution {
public:
    int minOperations(vector<string>& logs) {
        int index = 0;
        if (logs.size() == 0){
            return 0;
        }
        for (int i = 0; i < logs.size(); ++i) {
        	//����ƶ������ļ��в��ҵ�ǰ���ڸ��ļ����¾�·��-1 
        	// logs[i] == "../"�� index>0��������������д��һ�𣬲�Ȼelse�������࣬����bug 
            if(logs[i] == "../"){
                if(index>0) {
                    index--;
                }
            //��ǰ·�����ֲ��� 
            } else if(logs[i] == "./"){
                index+=0;
            }
            //���뵽���ļ�+1 
            else{
                index++;
            }
        }
        return index;
    }
};
