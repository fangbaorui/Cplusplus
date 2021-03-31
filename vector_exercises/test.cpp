#define _CRT_SECURE_NO_WARNINGS

//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//在杨辉三角中，每个数是它左上方和右上方的数的和。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //创建行
        vector<vector<int>> mat(numRows);
        //创建列
        for (int i = 0; i < numRows; i++)
        {
            mat[i].resize(i + 1);
        }
        for (int i = 0; i < numRows; i++)
        {
            //第一列和最后一列都为1
            mat[i][0] = mat[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i - 1][j - 1];
            }
        }
        return mat;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for (auto e : nums)
        {
            value ^= e;
        }
        return value;
    }
};