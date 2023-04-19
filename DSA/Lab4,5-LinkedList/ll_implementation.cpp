#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_beginning(node* &head, int val)
{
    node* new_head = new node(val);
    if(head == NULL)
    {
        head = new_head;
        return;
    }

    new_head->next = head;
    head = new_head;
}

void insert_at_end(node* &head, int val)
{
    node* tail = new node(val);

    if(head == NULL)
    {
        head = tail;
        return;
    }

    node* tmp = head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = tail;
}

void insert_after(node* &head, int pivot, int val)
{
    node* new_node = new node(val);
    node* tmp = head;

    while(tmp->data != pivot)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
}

void insert_before(node* &head, int pivot, int val)
{
    node* new_node = new node(val);
    node* tmp = head;

    if(tmp->data == pivot)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    while(tmp->next->data != pivot)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
}

void delete_from_beginning(node* &head)
{
    node* todelete = head;
    head = head->next;

    delete todelete;
}

void delete_from_end(node* &head)
{
    node* tmp = head;

    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    node* todelete = tmp->next;
    tmp->next = NULL;
    delete todelete;
}

void delete_after(node* &head, int pivot)
{
    node* tmp = head;

    while(tmp->data != pivot)
    {
        tmp = tmp->next;
    }

    node* todelete = tmp->next;
    tmp->next = tmp->next->next;
    delete todelete;
}

void display(node* head)
{
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }

    if(tmp == NULL) cout << "NULL";

    cout << endl;
}

int main()
{
    node* head = NULL;
    insert_at_beginning(head, 1);
    insert_at_end(head, 2);
    insert_after(head, 2, 3);
    insert_before(head, 1, 4);
    display(head);

    delete_from_beginning(head);
    delete_from_end(head);
    delete_after(head, 1);
    display(head);
    return 0; 
}