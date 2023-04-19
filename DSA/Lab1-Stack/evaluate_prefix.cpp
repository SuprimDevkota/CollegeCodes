#include <iostream>
#include <stack>
using namespace std;


int evalPrefix(string s)
{
    stack<int> st;
    int res;

    for(int i = 0; i < s.length(); ++i)
    {
        if((s[i] >= 'a'  && s[i] <='z') || (s[i] >='A' && s[i] <= 'Z'))
        {
            cout << "Expression contains letters" << endl;
            return 1;
        }
    }

    for(int i = s.length() - 1; i >= 0; --i)
    {
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }

        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;

                case '-':
                    st.push(op1 - op2);
                    break;
                
                case '*':
                    st.push(op1 * op2);
                    break;

                case '/':
                    st.push(op1 / op2);
                    break;
                
                default:
                    break;
            }
        }

    }
    
    res = st.top();
    st.pop();
    return res;
}


int main()
{
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    cout << evalPrefix(expr);

}