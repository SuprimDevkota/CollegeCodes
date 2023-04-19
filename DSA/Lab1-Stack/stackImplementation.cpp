#include <iostream>
#define SIZE 5
using namespace std;

template<typename T>
class Stack
{
    private:
        T stack[SIZE];
        int top;
    
    public:
        Stack()
        {
            top = -1;
        }

        void push(T item)
        {
            if(top >= SIZE - 1){
                throw("\nStack Overflow");
            }

            else{
                top = top + 1;
                stack[top] = item;
            }
        }

        T pop()
        {
            if(top == -1){
                throw("\nStack Underflow");
            }

            else{
                return stack[top--];
            }
        }

        void Display()
        {
            int cnt = top;
            while(cnt >= 0)
            {
                cout << stack[cnt] << " ";
                cnt--;
            }

            cout << endl;
        }

};

int main()
{
    Stack<int> st;
    int a, cnt = 0;

    try
    {
        for(int i = 0; i < SIZE; ++i)
        {
            cout << "Enter an element to push to stack: ";
            cin >> a;
            st.push(a);
        }
    }

    catch(const char* err){
        cout << err;
    }
    
    cout << "The elements in stack are: ";

    st.Display();

    cout << "\nNow popping the elements one by one...\n";

    try
    {
       while(SIZE - cnt){
        cout << st.pop() << " ";
        cnt++;
       }
    }

    catch(const char* err){
        cout << err;
    }

    return 0;

}