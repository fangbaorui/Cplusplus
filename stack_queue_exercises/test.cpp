
//数组中第K个大的元素
//1. 利用priority_queue建立堆
//2. priority_queue默认为建立大堆
//3. 通过出堆，即可找出数据
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(), nums.end());
        // 将优先级队列中前k-1个元素删除掉
        for (int i = 0; i < k - 1; ++i)
        {
            p.pop();
        }
        return p.top();
    }
};


//用队列实现栈
//1. 不管底层用什么结构实现，永远保证数据先进后出的一个逻辑数据结构，即栈
//2. 借助队列实现栈，可以使用两个队列，也可以只是用一个队列，本解只借助一个队列即可
//3. 入栈，即把数据进行入队，为了保证栈的特性先进后出，因此需要在push方法中对入队之前的所有元素进行一次出队入队操作，
// 以保证所有数据达到先进后出的顺序
//4. 出栈，由于队列数据顺序已经调整，所以只需取队头元素即可
class MyStack
{
private:
    queue<int> q;
public:
    MyStack()
    {}
    void push(int x)
    {
        // 反转队列，将新元素插到队头
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




//用两个栈实现队列
//1. 不管底层用什么结构实现，永远保证数据先进先出的一个逻辑数据结构，即队列

//2. 创建栈st1和st2, 入队直接在栈st1进行入队操作，

//3. 出队时，若st2不空，直接出栈即是出队，若st2已为空，则把栈st1里面的所有数据导入st2

//4. 获取队头元素时，若st2不空，就去栈顶元素即为队头，若为空，则需要把栈st1里面的所有数据导入st2

//5. 判断队列是否为空，需要满足两个栈都为空时整个队列才为空
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