#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//void test()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	cout << st.size() << endl;
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}




//设计一个支持 push ，pop ，//top 操作，并能在常数时间内检索到最小元素的栈。
//push(x) —— 将元素 x 推入栈中。
//pop() —— 删除栈顶的元素。
//top() —— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。

//class MinStack {
//public:
//    /** initialize your data structure here. */
//    MinStack() {
//
//    }
//
//    void push(int val) {
//        st.push(val);
//        if (minst.empty() || val <= minst.top())
//            minst.push(val);
//    }
//
//    void pop() {
//        if (st.top() == minst.top())
//            minst.pop();
//        st.pop();
//    }
//
//    int top() {
//        return st.top();
//    }
//
//    int getMin() {
//        return minst.top();
//    }
//private:
//    stack<int> st;
//    stack<int> minst;
//};




//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能
//为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，
//但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//        stack<int> st;
//        int pushIdx = 0;
//        int popIdx = 0;
//        //入栈
//        while (pushIdx < pushV.size())
//        {
//            st.push(pushV[pushIdx++]);
//            //判断栈顶元素和出栈元素是否相同
//            while (!st.empty() && st.top() == popV[popIdx])
//            {
//                st.pop();
//                popIdx++;
//            }
//        }
//        //判断栈是否为空
//        return st.empty();
//    }
//};




//根据 逆波兰表示法，求表达式的值。
//有效的算符包括  + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//leetcode-cn.com/problems/evaluate-reverse-polish-notation
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        for (const auto& str : tokens)
//        {
//            if (str == "+" || str == "-"
//                || str == "/" || str == "*")
//            {
//                //运算
//                //从栈中取出两个操作数
//                int right = st.top();
//                st.pop();
//                int left = st.top();
//                st.pop();
//                if (str == "+")
//                    st.push(left + right);
//                else if (str == "-")
//                    st.push(left - right);
//                else if (str == "*")
//                    st.push(left * right);
//                if (str == "/")
//                    st.push(left / right);
//            }
//            else
//                st.push(stoi(str));  //操作数入栈
//        }
//        return st.top();
//    }
//};




////用vector实现一个栈
//template <class T>
//class Stack
//{
//public:
//	void push(const T& val)
//	{
//		st.push_back(val);
//	}
//
//	void pop()
//	{
//		st.pop_back();
//	}
//
//	T& top()
//	{
//		return st.back();
//	}
//
//	size_t size() const
//	{
//		return st.size();
//	}
//
//	bool empty() const
//	{
//		return st.empty();
//	}
//
//private:
//	vector<T> st;
//};
//
//
//
////用list实现一个栈
//template <class T>
//class Stack2
//{
//public:
//	void push(const T& val)
//	{
//		st.push_back(val);
//		//st.push_front(val);
//	}
//
//	void pop()
//	{
//		st.pop_back();
//		//st.pop_front();
//	}
//
//	T& top()
//	{
//		return st.back();
//		//return st.front();
//	}
//
//	size_t size() const
//	{
//		return st.size();
//	}
//
//	bool empty() const
//	{
//		return st.empty();
//	}
//private:
//	list<T> st;
//};
//
//void test()
//{
//	Stack2<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	cout << st.size() << endl;
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	cout << st.size() << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}



//用list模拟实现队列
template <class T>
class Queue
{
public:
	void push(const T& val)
	{
		q.push_back(val);
		//q.push_front(val);
	}

	void pop()
	{
		q.pop_front();
		//q.pop_back();
	}

	T& front()
	{
		return q.front();
		//retuen q.back();
	}

	size_t size() const
	{
		return q.size();
	}

	bool empty() const
	{
		return q.empty();
	}
private:
	list<T> q;
};

void test()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	cout << q.size() << endl;
}
int main()
{
	test();
	return 0;
}
