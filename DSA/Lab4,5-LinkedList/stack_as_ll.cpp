#include <iostream>
using namespace std;

class Stack_node
{
public:
    int data;
    Stack_node *next;

    Stack_node(int val)
    {
        data = val;
        next = NULL;
    }
};

void push(Stack_node *&top, int val)
{
    Stack_node *new_node = new Stack_node(val);
    new_node->next = top;
    top = new_node;
}

void display(Stack_node *top)
{
    Stack_node *tmp = top;
    cout << tmp->data << "(top) ";
    tmp = tmp->next;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void pop(Stack_node *&top)
{
    if(top == NULL)
    {
        cout << "Stack empty";
        return;
    }
    Stack_node *todelete = top;
    top = top->next;
    delete todelete;
}

int main()
{
    Stack_node *top = NULL;
    push(top, 1);
    push(top, 2);
    push(top, 4);
    display(top);

    pop(top);
    display(top);
}