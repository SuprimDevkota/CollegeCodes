/* Implement queue using Queue */

#include <iostream>

using namespace std;

template <class T>
class Queue
{
public:
    struct Node
    {
        T value;
        int next;
    };

    Node *nodes;
    int avail, head, tail;

public:
    Queue(int capacity)
    {
        nodes = new Node[capacity];
        avail = 0;
        head = tail = -1;

        for (int i = 0; i < capacity - 1; ++i)
        {
            nodes[i].next = i + 1;
        }
        nodes[capacity - 1].next = -1;
    }

    bool empty()
    {
        return head == -1;
    }

    /* Insert a new node with `value` at the end of the Queue
    Time: O(1)
    Space: O(1) */
    void enqueue(T value)
    {
        if (avail == -1)
        {
            cout << "Queue is full!\n";
            return;
        }

        int new_node = avail;
        avail = nodes[avail].next;

        nodes[new_node].value = value;
        nodes[new_node].next = -1;

        if (tail == -1)
        {
            head = tail = new_node;
        }
        else
        {
            nodes[tail].next = new_node;
            tail = new_node;
        }
    }

    /* Delete the first node and return its value
    Time: O(1)
    Space: O(1) */
    T dequeue()
    {
        if (head == -1)
        {
            cout << "Empty Queue!\n";
            return -1;
        }

        T value = nodes[head].value;
        int to_del = head;
        head = nodes[head].next;

        nodes[to_del].next = avail;
        avail = to_del;

        if (head == -1)
        {
            /* Empty Queue */
            tail = -1;
        }

        return value;
    }
};

int main()
{
    Queue<int> q(3);

    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(5);

    cout << "Insering an element to completely filled queue...\n";
    q.enqueue(3);

    cout << "Removing elements...\n";
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
