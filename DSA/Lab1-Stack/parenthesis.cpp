#include <stack>
#include <string>
#include <iostream>
using namespace std;

char reverseBracket(char c)
{
    if(c == '('){
        return ')';
    }

    else if(c == '{'){
        return '}';
    }

    else if(c == '['){
        return ']';
    }

}

int paranthesisChecker(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            char brac = st.top();
            st.pop();
            if(reverseBracket(brac) != s[i]){
                return 0;
            }
        }
    }

    if(!st.empty() && (st.top() == '(' || st.top() == '{' || st.top() == '['))
    {
        return 0;
    }

    return 1;
}

int main()
{
    string expr;
    cout << "Enter the expression with brackets: " <<endl;
    cin >> expr;

    switch(paranthesisChecker(expr))
    {
        case 1:
            cout << "The brackets are balanced" << endl;
            break;

        case 0:
            cout << "The brackets are not balanced" << endl;
            break;

        default:
            break;
    }

    return 0;
}