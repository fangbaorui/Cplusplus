//���ݶ����������ַ�����
//https://leetcode-cn.com/problems/construct-string-from-binary-tree/
//������Ϊ�գ��ж��Ƿ�Ҫ�ӿ�����
//1.������������ڣ���Ҫ�ӣ�  2.��������������ڣ�����Ҫ��
//����ұ�Ϊ�գ�ֱ��ʡ�Ե�������
class Solution {
public:
    void _stree2str(TreeNode* root, string& str)
    {
        if (root)
        {
            //����ת�ַ���
            //ƴ�ӵ�ǰ�ڵ������,����ת��Ϊ�ַ���
            stringstream ss;
            ss << root->val;
            str += ss.str();

            //����������
            if (root->left)
            {
                str += '(';
                _stree2str(root->left, str);
                str += ')';
            }
            else
            {
                //�ж��������Ƿ����
                if (root->right)
                    str += "()";
                else
                    return;
            }
            //����������
            if (root->right)
            {
                str += '(';
                _stree2str(root->right, str);
                str += ')';
            }
        }
    }
    string tree2str(TreeNode* root) {
        //ǰ�����
        string str;
        _stree2str(root, str);
        return str;
    }
};



//�������ķֲ����1��https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> mat;
        //���д��ÿһ����Ҫ������Ԫ��
        queue<TreeNode*> que;
        //���ȸ������д�ŵ�һ��Ľڵ�
        if (root)
            que.push(root);
        while (!que.empty())
        {
            //���Ȼ�ȡÿһ�εĽڵ����
            int rowSize = que.size();
            vector<int> row;
            //ͬһ������ݷ���ͬһ��
            while (rowSize--)
            {
                TreeNode* cur = que.front();
                que.pop();
                row.push_back(cur->val);

                //������һ��ڵ�
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            //����һ�е�����
            mat.push_back(row);
        }
        return mat;
    }
};



//�������ķֲ����2��https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> mat;
        //���д��ÿһ����Ҫ������Ԫ��
        queue<TreeNode*> que;
        //���ȸ������д�ŵ�һ��Ľڵ�
        if (root)
            que.push(root);
        while (!que.empty())
        {
            //���Ȼ�ȡÿһ�εĽڵ����
            int rowSize = que.size();
            vector<int> row;
            //ͬһ������ݷ���ͬһ��
            while (rowSize--)
            {
                TreeNode* cur = que.front();
                que.pop();
                row.push_back(cur->val);

                //������һ��ڵ�
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            //����һ�е�����
            mat.push_back(row);
        }
        reverse(mat.begin(), mat.end());
        return mat;
    }
};



//�����������
//����һ��������, �ҵ�����������ָ���ڵ������������ȣ�
//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    //ǰ���������·��
    bool getPath(TreeNode* root, TreeNode* cur, stack<TreeNode*>& st)
    {
        if (root == nullptr)
            return false;
        st.push(root);
        //�жϵ�ǰ�ڵ��ǲ���Ҫ���ҵĵ�
        if (root == cur)
            return true;
        //�����ǰ�ڵ㲻����Ҫ���ҵĽڵ㣬�鿴����
        if (getPath(root->left, cur, st))
            return true;
        if (getPath(root->right, cur, st))
            return true;
        //��ǰ��root������Ҫ���ҵ�·����
        st.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path1;
        stack<TreeNode*> path2;
        //·������
        getPath(root, p, path1);
        getPath(root, q, path2);
        //·���ü�
        while (path1.size() != path2.size())
        {
            if (path1.size() > path2.size())
                path1.pop();
            else
                path2.pop();
        }
        //�����������
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



//������������ת��������˫������
//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//�������ӣ�������������������һ��
//������������
//1.root->left=prev   //prevָ��������С�ڸ��ڵ��ֵ
//2.prev != nullptr; prev->right = root
//3.prev = root   //prve���µ�root
//����������
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




//���ݶ�������ǰ���������������ԭ�ö�������
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
        int& preIdx, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return nullptr;
        //������ǰ�ڵ�
        TreeNode* cur = new TreeNode(preorder[preIdx]);
        //������������������
        int curIdx = startIdx;
        for (; curIdx <= endIdx; ++curIdx)
        {
            if (inorder[curIdx] == preorder[preIdx])
                break;
        }
        //����������[startIdx, curIdx-1]
        if (startIdx < curIdx)
            cur->left = _buildTree(preorder, inorder, ++preIdx, startIdx, curIdx - 1);
        else
            cur->left = nullptr;
        //����������[curIdx+1,endIdx]
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



//���ݶ�����������ͺ�����������ԭ�ö�������
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder,
        int& postIdx, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return nullptr;
        //������ǰ�ڵ�
        TreeNode* cur = new TreeNode(postorder[postIdx]);
        //������������������
        int curIdx = startIdx;
        for (; curIdx <= endIdx; ++curIdx)
        {
            if (inorder[curIdx] == postorder[postIdx])
                break;
        }
        //����������[curIdx+1,endIdx]
        if (curIdx < endIdx)
            cur->right = _buildTree(postorder, inorder, --postIdx, curIdx + 1, endIdx);
        else
            cur->right = nullptr;
        //����������[startIdx, curIdx-1]
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



//��������ǰ��������ǵݹ����ʵ�֣�https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vec;
        while (cur || !st.empty())
        {
            //������curΪ���������·��
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



//������������� ���ǵݹ����ʵ�֣�https ://leetcode-cn.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vec;
        while (cur || !st.empty())
        {
            //������curΪ���������·��
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            vec.push_back(cur->val);
            //����������
            cur = cur->right;
        }
        return vec;
    }
};


//�������ĺ������ ���ǵݹ����ʵ�֣�https ://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
            //��ȡջ��Ԫ��
            TreeNode* top = st.top();
            //�жϵ�ǰ�ڵ��Ƿ���Ա���
            if (top->right == nullptr || top->right == prev)
            {
                vec.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                //����������
                cur = top->right;
            }
        }
        return vec;
    }
};


















