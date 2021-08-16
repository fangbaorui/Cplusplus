//根据二叉树创建字符串：
//https://leetcode-cn.com/problems/construct-string-from-binary-tree/
//如果左边为空：判断是否要加空括号
//1.如果右子树存在，需要加，  2.如果右子树不存在，不需要加
//如果右边为空：直接省略掉空括号
class Solution {
public:
    void _stree2str(TreeNode* root, string& str)
    {
        if (root)
        {
            //整数转字符串
            //拼接当前节点的数据,整数转化为字符串
            stringstream ss;
            ss << root->val;
            str += ss.str();

            //处理左子树
            if (root->left)
            {
                str += '(';
                _stree2str(root->left, str);
                str += ')';
            }
            else
            {
                //判断右子树是否存在
                if (root->right)
                    str += "()";
                else
                    return;
            }
            //处理右子树
            if (root->right)
            {
                str += '(';
                _stree2str(root->right, str);
                str += ')';
            }
        }
    }
    string tree2str(TreeNode* root) {
        //前序遍历
        string str;
        _stree2str(root, str);
        return str;
    }
};



//二叉树的分层遍历1：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> mat;
        //队列存放每一层需要遍历的元素
        queue<TreeNode*> que;
        //首先给队列中存放第一层的节点
        if (root)
            que.push(root);
        while (!que.empty())
        {
            //首先获取每一次的节点个数
            int rowSize = que.size();
            vector<int> row;
            //同一层的数据放在同一行
            while (rowSize--)
            {
                TreeNode* cur = que.front();
                que.pop();
                row.push_back(cur->val);

                //存入下一层节点
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            //保存一行的数据
            mat.push_back(row);
        }
        return mat;
    }
};



//二叉树的分层遍历2：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> mat;
        //队列存放每一层需要遍历的元素
        queue<TreeNode*> que;
        //首先给队列中存放第一层的节点
        if (root)
            que.push(root);
        while (!que.empty())
        {
            //首先获取每一次的节点个数
            int rowSize = que.size();
            vector<int> row;
            //同一层的数据放在同一行
            while (rowSize--)
            {
                TreeNode* cur = que.front();
                que.pop();
                row.push_back(cur->val);

                //存入下一层节点
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            //保存一行的数据
            mat.push_back(row);
        }
        reverse(mat.begin(), mat.end());
        return mat;
    }
};



//最近公共祖先
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先：
//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    //前序遍历保存路径
    bool getPath(TreeNode* root, TreeNode* cur, stack<TreeNode*>& st)
    {
        if (root == nullptr)
            return false;
        st.push(root);
        //判断当前节点是不是要查找的点
        if (root == cur)
            return true;
        //如果当前节点不是需要查找的节点，查看子树
        if (getPath(root->left, cur, st))
            return true;
        if (getPath(root->right, cur, st))
            return true;
        //当前的root不在需要查找的路径上
        st.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path1;
        stack<TreeNode*> path2;
        //路径查找
        getPath(root, p, path1);
        getPath(root, q, path2);
        //路径裁剪
        while (path1.size() != path2.size())
        {
            if (path1.size() > path2.size())
                path1.pop();
            else
                path2.pop();
        }
        //查找最近祖先
        while (!path1.empty())
        {
            if (path1.top() == path2.top())
                return path1.top();
            else {
                path1.pop();
                path2.pop();
            }
        }
        return path1.top();
    }
};



//二叉树搜索树转换成排序双向链表：
//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//中序链接，处理左子树和右子树一样
//处理左子树：
//1.root->left=prev   //prev指的是正好小于根节点的值
//2.prev != nullptr; prev->right = root
//3.prev = root   //prve更新到root
//处理右子树
class Solution {
public:
    void _Convert(TreeNode* root, TreeNode*& prev)
    {
        if (root)
        {
            _Convert(root->left, prev);
            root->left = prev;
            if (prev)
                prev->right = root;
            prev = root;
            _Convert(root->right, prev);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);
        TreeNode* cur = pRootOfTree;
        while (cur && cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
};




//根据二叉树的前序和中序遍历结果还原该二叉树：
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
        int& preIdx, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return nullptr;
        //创建当前节点
        TreeNode* cur = new TreeNode(preorder[preIdx]);
        //查找左右子树的区间
        int curIdx = startIdx;
        for (; curIdx <= endIdx; ++curIdx)
        {
            if (inorder[curIdx] == preorder[preIdx])
                break;
        }
        //左子树区间[startIdx, curIdx-1]
        if (startIdx < curIdx)
            cur->left = _buildTree(preorder, inorder, ++preIdx, startIdx, curIdx - 1);
        else
            cur->left = nullptr;
        //右子树区间[curIdx+1,endIdx]
        if (curIdx < endIdx)
            cur->right = _buildTree(preorder, inorder, ++preIdx, curIdx + 1, endIdx);
        else
            cur->right = nullptr;
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return _buildTree(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};



//根据二叉树的中序和后序遍历结果还原该二叉树：
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder,
        int& postIdx, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return nullptr;
        //创建当前节点
        TreeNode* cur = new TreeNode(postorder[postIdx]);
        //查找左右子树的区间
        int curIdx = startIdx;
        for (; curIdx <= endIdx; ++curIdx)
        {
            if (inorder[curIdx] == postorder[postIdx])
                break;
        }
        //右子树区间[curIdx+1,endIdx]
        if (curIdx < endIdx)
            cur->right = _buildTree(postorder, inorder, --postIdx, curIdx + 1, endIdx);
        else
            cur->right = nullptr;
        //左子树区间[startIdx, curIdx-1]
        if (startIdx < curIdx)
            cur->left = _buildTree(postorder, inorder, --postIdx, startIdx, curIdx - 1);
        else
            cur->left = nullptr;

        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        return _buildTree(postorder, inorder, postIdx, 0, inorder.size() - 1);
    }
};



//二叉树的前序遍历，非递归迭代实现：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vec;
        while (cur || !st.empty())
        {
            //访问以cur为根的最左边路径
            while (cur)
            {
                vec.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return vec;
    }
};



//二叉树中序遍历 ，非递归迭代实现：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vec;
        while (cur || !st.empty())
        {
            //访问以cur为根的最左边路径
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            vec.push_back(cur->val);
            //访问右子树
            cur = cur->right;
        }
        return vec;
    }
};


//二叉树的后序遍历 ，非递归迭代实现：https ://leetcode-cn.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        TreeNode* cur = root;
        TreeNode* prev;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            //获取栈顶元素
            TreeNode* top = st.top();
            //判断当前节点是否可以遍历
            if (top->right == nullptr || top->right == prev)
            {
                vec.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                //访问右子树
                cur = top->right;
            }
        }
        return vec;
    }
};


















