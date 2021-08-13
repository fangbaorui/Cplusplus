
//�����е�K�����Ԫ��
//1. ����priority_queue������
//2. priority_queueĬ��Ϊ�������
//3. ͨ�����ѣ������ҳ�����
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(), nums.end());
        // �����ȼ�������ǰk-1��Ԫ��ɾ����
        for (int i = 0; i < k - 1; ++i)
        {
            p.pop();
        }
        return p.top();
    }
};


//�ö���ʵ��ջ
//1. ���ܵײ���ʲô�ṹʵ�֣���Զ��֤�����Ƚ������һ���߼����ݽṹ����ջ
//2. ��������ʵ��ջ������ʹ���������У�Ҳ����ֻ����һ�����У�����ֻ����һ�����м���
//3. ��ջ���������ݽ�����ӣ�Ϊ�˱�֤ջ�������Ƚ�����������Ҫ��push�����ж����֮ǰ������Ԫ�ؽ���һ�γ�����Ӳ�����
// �Ա�֤�������ݴﵽ�Ƚ������˳��
//4. ��ջ�����ڶ�������˳���Ѿ�����������ֻ��ȡ��ͷԪ�ؼ���
class MyStack
{
private:
    queue<int> q;
public:
    MyStack()
    {}
    void push(int x)
    {
        // ��ת���У�����Ԫ�ز嵽��ͷ
        int size = q.size();
        q.push(x);
        while (size--)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    int pop()
    {
        int popEle = q.front();
        q.pop();
        return popEle;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};




//������ջʵ�ֶ���
//1. ���ܵײ���ʲô�ṹʵ�֣���Զ��֤�����Ƚ��ȳ���һ���߼����ݽṹ��������

//2. ����ջst1��st2, ���ֱ����ջst1������Ӳ�����

//3. ����ʱ����st2���գ�ֱ�ӳ�ջ���ǳ��ӣ���st2��Ϊ�գ����ջst1������������ݵ���st2

//4. ��ȡ��ͷԪ��ʱ����st2���գ���ȥջ��Ԫ�ؼ�Ϊ��ͷ����Ϊ�գ�����Ҫ��ջst1������������ݵ���st2

//5. �ж϶����Ƿ�Ϊ�գ���Ҫ��������ջ��Ϊ��ʱ�������в�Ϊ��
class MyQueue
{
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
    }
    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        int retval;
        if (!st2.empty())
        {
            retval = st2.top();
            st2.pop();
            return retval;
        }

        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        retval = st2.top();
        st2.pop();
        return retval;
    }

    int peek()
    {
        int retval;
        if (!st2.empty())
        {
            retval = st2.top();
            return retval;
        }

        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }


    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};