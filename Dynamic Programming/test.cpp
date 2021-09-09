#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//第1题 Fibonacci
//法一：
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        int f1 = 1;
        int f2 = 1;
        int f3 = 2;
        for (int i = 3; i <= n; i++)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;

    }
};
//法二：
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
//法三：
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> arr(n + 1, 0);
        arr[0] = 0;
        arr[1] = 1;
        if (n <= 1)
            return arr[n];
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};



//第2题 变态青蛙跳台阶
//法一：
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0)
            return 0;
        return 1 << (number - 1);
    }
};
//法二：
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0)
            return 0;
        int ret = 1;
        for (int i = 2; i <= number; i++)
        {
            ret *= 2;
        }
        return ret;
    }
};


//第3题 最大连续子数组和
//法一：
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int count = array[0];
        int maxarr = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            count = max(count + array[i], array[i]);
            maxarr = max(count, maxarr);
        }
        return maxarr;
    }
};
//法二：
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = array[0];
        int count = 0;
        int min = array[0];
        for (int i = 0; i < array.size(); i++)
        {
            count += array[i];
            if (count <= 0)
                count = 0;
            if (count > ret)
                ret = count;
            if (array[i] > min)
                min = array[i];
        }
        if (min < 0)
            return min;
        return ret;
    }
};


//第4题 字符串分割
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<bool> can_break(s.size() + 1, false);
        can_break[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                //前j个为真，第j+1个的索引为j，
                if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    can_break[i] = true;
                    break;
                }
            }
        }
        return can_break[s.size()];
    }
};


//第5题 三角矩阵(Triangle)
//法一：
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty())
            return 0;
        vector<vector<int>> min_sum(triangle);
        int row = triangle.size();
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    min_sum[i][j] = min_sum[i - 1][j] + triangle[i][j];
                else if (j == i)
                    min_sum[i][j] = min_sum[i - 1][j - 1] + triangle[i][j];
                else
                    min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]) + triangle[i][j];
            }
        }
        //从最后一行找到最小值
        int ret = min_sum[row - 1][0];
        for (int j = 1; j < row; j++)
        {
            ret = min(min_sum[row - 1][j], ret);
        }
        return ret;
    }
};
//法二：
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty())
            return 0;
        vector<vector<int>> min_sum(triangle);
        int row = triangle.size();
        //row-1是最后一行不用计算
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return min_sum[0][0];
    }
};


//第6题 路径总数
class Solution {
public:
    int uniquePaths(int m, int n) {
        // write code here
        if (m < 1 || n < 1)
            return 0;
        vector<vector<int>> map(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[m - 1][n - 1];
    }
};


//第7题 路径总数
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        // write code here
        if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> map(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
                break;
            else
                map[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j])
                break;
            else
                map[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    map[i][j] = 0;
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[m - 1][n - 1];
    }
};


//第8题 最小路径和
//法一：
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        // write code here
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> map(m, vector<int>(n, 0));
        map[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            map[i][0] = map[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            map[0][j] = map[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                map[i][j] = min(map[i][j - 1], map[i - 1][j]) + grid[i][j];
            }
        }
        return map[m - 1][n - 1];
    }
};
//法二：
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty())
            return 0;
        vector<vector<int>> ret(grid);
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 1; i < row; i++)
        {
            ret[i][0] += ret[i - 1][0];
        }
        for (int j = 1; j < col; j++)
        {
            ret[0][j] += ret[0][j - 1];
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                ret[i][j] += min(ret[i - 1][j], ret[i][j - 1]);
            }
        }
        return ret[row - 1][col - 1];
    }
};


//第9题 背包问题
class Solution {
public:
    int backPackII(int m, vector<int>& A, vector<int>& V) {
        int n = A.size();
        if (n == 0 || m == 0)
            return 0;
        vector<int> arr(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (A[i] <= j)
                {
                    arr[j] = max(arr[j], arr[j - A[i]] + V[i]);
                }
            }
        }
        return arr[m];
    }
};