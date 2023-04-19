#include <iostream>
#include <stack>
#include <string>
using namespace std;


int evalPostfix(string s)
{
    stack<int> st;

    for(int i = 0; i < s.length(); ++i)
    {
        if((s[i] >= 'a'  && s[i] <='z') || (s[i] >='A' && s[i] <= 'Z'))
        {
            cout << "Expression contains letters" << endl;
            return 1;
        }
    }
    
    for(int i = 0; i < s.length(); ++i)
    {

        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }

        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            switch(s[i])
            {
                case '+':
                    st.push(a + b);
                    break;
                
                case '-':
                    st.push(a - b);
                    break;
                
                case '*':
                    st.push(a * b);
                    break;
                
                case '/':
                    st.push(a / b);
                    break;

                default:
                    cout << "Invalid operator" << endl;
                    return 1;
                    break;
            }
        }
    }

    int res = st.top();
    st.pop();
    return res;
}

int main()
{
    string s;
    cout << "Enter the postfix operation: ";
    cin >> s;
    cout << "The value of the expression is: " << evalPostfix(s) << endl;
    return 0;
}