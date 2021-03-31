#define _CRT_SECURE_NO_WARNINGS

//����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
//����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //������
        vector<vector<int>> mat(numRows);
        //������
        for (int i = 0; i < numRows; i++)
        {
            mat[i].resize(i + 1);
        }
        for (int i = 0; i < numRows; i++)
        {
            //��һ�к����һ�ж�Ϊ1
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