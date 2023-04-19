#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c)
{

    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || s[i] <= 'A' && s[i] >= 'Z')
        {
            res += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {

                if (prec(st.top()) == prec(s[i]) == 3)
                {
                    st.push(s[i]);
                }

                else
                {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

string reverse_infix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }

        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    return s;
}

string infix_to_prefix(string s)
{
    string revs = reverse_infix(s);
    stack<char> st;
    string res;

    for (int i = 0; i < revs.length(); ++i)
    {
        if ((revs[i] >= 'a' && revs[i] <= 'z') || (revs[i] >= 'A' && revs[i] <= 'Z'))
        {
            res += revs[i];
        }

        else if (revs[i] == '(')
        {
            st.push(revs[i]);
        }

        else if (revs[i] == ')')
        {
            while (!st.empty() && (st.top() != '('))
            {   
                res += st.top();
                st.pop();
            }
            st.pop();
        }

        else if(st.empty() || prec(revs[i])>= prec(st.top()) || st.top() =='('){
            st.push(revs[i]);
        }

        else{
            
           while(!st.empty() && (prec(revs[i])<prec(st.top())))
           {
                res += st.top();
                st.pop();
           }

           st.push(revs[i]);
        }

    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string expr;
    cout << "Enter the infix expression: ";
    cin >> expr;
    cout << "The postfix expression is: " << infix_to_postfix(expr) << endl;
    cout << "The prefix expression is: " << infix_to_prefix(expr) << endl;
    return 0;
}