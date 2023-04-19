#include <iostream>
using namespace std;

class queue_node
{
    public:
        int data;
        queue_node* next;

        queue_node(int val)
        {
            data = val;
            next = NULL;
        }
};

void enqueue(queue_node* &front, queue_node* &rear, int val)
{
    queue_node* new_node = new queue_node(val);
    if(front == NULL && rear == NULL)
    {
        front = rear = new_node;
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

void dequeue(queue_node* &front)
{
    if(front == NULL)
    {
        cout << "Queue is empty";
    }
    queue_node* todelete = front;
    front = front->next;
    delete todelete;
}

void display(queue_node* &front)
{
    queue_node* tmp = front;

    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

int main()
{
    queue_node* front = NULL;
    queue_node* rear = NULL;

    enqueue(front, rear, 1);
    enqueue(front, rear, 2);
    enqueue(front, rear, 3);

    display(front);

    dequeue(front);
    dequeue(front);

    display(front);
}