//
// Created by hp on 2020/10/7.
// 利用缓存行，把第i行的数据从0加到j的和，存到新数组的第i行j列，这里预留了一列为0(我是第0列)
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
//    vector<vector<int>> dp_col;
    vector<vector<int>> dp_row;
    NumMatrix(vector<vector<int>>& matrix) {
//        dp_col = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size(),0));
        if (matrix.empty())return;
        dp_row = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size()+1,0));
        for (int i = 0; i < matrix.size(); ++i) {
            dp_row[i][1] = matrix[i][0];
            for (int j = 2; j <= matrix[0].size(); ++j) {
                dp_row[i][j] = dp_row[i][j-1] + matrix[i][j-1];
            }
        }

//        for (int i = 0; i < matrix[0].size(); ++i) {
//            dp_col[1][i] = matrix[0][i];
//            for (int j = 2; j <= matrix.size(); ++j) {
//                dp_col[j][i] = dp_col[j-1][i]+matrix[j-1][i];
//            }
//        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum =0;
        for (int i = row1; i <= row2; ++i) {
            sum += (dp_row[i][col2+1]-dp_row[i][col1]);
        }
//        for (int i = col1; i <= col2 ; ++i) {
//            sum +=(dp_col[row2+1][i] - dp_col[row1][i]);
//        }

        return sum;
    }
};

int main(){
    vector<vector<int>>matrix={{3, 0, 1, 4, 2},
                               {5, 6, 3, 2, 1},
                               {1, 2, 0, 1, 5},
                               {4, 1, 0, 1, 7},
                               {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2,1,4,3);
    cout<<param_1<<endl;
}
