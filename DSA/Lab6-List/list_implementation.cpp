#include <iostream>

using namespace std;

template <class T>
class List
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
    List(int capacity)
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

    /* Insert a new node with `value` at the beginning of the list
    Time: O(1)
    Space: O(1) */
    void push_front(T value)
    {
        if (avail == -1)
        {
            cout << "List is full!\n";
            return;
        }

        int new_node = avail;
        avail = nodes[avail].next;

        nodes[new_node].value = value;
        nodes[new_node].next = head;
        head = new_node;

        if (tail == -1)
        {
            tail = new_node;
        }
    }

    /* Insert a new node with `value` at the end of the list
    Time: O(1)
    Space: O(1) */
    void push_back(T value)
    {
        if (avail == -1)
        {
            cout << "List is full!\n";
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
    T pop_front()
    {
        if (head == -1)
        {
            cout << "Empty list!\n";
            return -1;
        }

        T value = nodes[head].value;
        int to_del = head;
        head = nodes[head].next;

        nodes[to_del].next = avail;
        avail = to_del;

        if (head == -1)
        {
            /* Empty list */
            tail = -1;
        }

        return value;
    }

    /* Delete the last node and return its value
    Time: O(1)
    Space: O(1) */
    T pop_back()
    {
        if (head == -1)
        {
            cout << "Empty list!\n";
            return -1;
        }

        T value = nodes[tail].value;
        int to_del = tail;

        if (head == tail)
        {
            /* Only one node */
            head = tail = -1;
        }
        else
        {
            int curr = head;
            while (nodes[curr].next != tail)
            {
                curr = nodes[curr].next;
            }

            tail = curr;
            nodes[curr].next = -1;
        }

        nodes[to_del].next = avail;
        avail = to_del;

        return value;
    }

    void print()
    {
        if (head == -1)
        {
            cout << "Empty list!\n";
            return;
        }
        
        int curr = head;
        while (curr != -1)
        {
            cout << nodes[curr].value << "->";
            curr = nodes[curr].next;
        }

        cout << "null\n";
    }
};

int main()
{
    List<int> list(10);

    list.push_back(1);
    list.push_front(7);
    list.push_back(3);
    list.push_front(2);
    list.push_back(9);

    cout << "Before removing the elements:\n";
    list.print();

    cout << "\nRemoving elements...\n";
    cout << "First node's value: " << list.pop_front() << '\n';
    cout << "Last node's value: " << list.pop_back() << '\n';
    cout << "\nAfter removing the elements:\n";
    list.print();

    return 0;
}
