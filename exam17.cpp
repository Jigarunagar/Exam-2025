#include <iostream>
#include <stack>
using namespace std;

#define n 100
class number
{
    int *arr;
    int top;

public:
    number()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    number st;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout << "top value:" << st.Top() << "empty value :" << st.empty();
}

///////////////////////////////////////////////

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValid(s))
    {
        cout << "Valid Parentheses\n";
    }
    else
    {
        cout << "Invalid Parentheses\n";
    }
    return 0;
}
