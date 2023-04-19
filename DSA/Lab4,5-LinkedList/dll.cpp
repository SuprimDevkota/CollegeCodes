#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* prev;
        node* next;

        node(int val)
        {
            data = val;
            prev = NULL;
            next = NULL;
        }
};

void insert_head(node* &head, int val)
{
    node* new_node = new node(val);
    if(head != NULL)
    {
        new_node->next = head;
        head->prev = new_node;
    }
    head = new_node;
}

void insert_tail(node* &head, int val)
{
    node* new_node = new node(val);
    if(head == NULL)
    {
        insert_head(head, val);
        return;
    }

    node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    new_node->prev = tmp;
    tmp->next = new_node;
}

void insert_before(node* &head, int pivot, int val)
{
    node* new_node = new node(val);
    node* tmp = head;

    while(tmp->next->data != pivot)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    new_node->prev = tmp;
    tmp->next = new_node;
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
    new_node->prev = tmp;
    tmp->next = new_node;
}

void delete_head(node* &head)
{
    node* to_delete = head;
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    head = head->next;
    head->prev = NULL;
    delete to_delete;
}

void delete_tail(node* &head)
{
    node* tmp = head;
    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    node* to_delete = tmp->next;
    tmp->next = NULL;
    delete to_delete;
}

void delete_after(node* &head, int pivot)
{
    node* tmp = head;
    while(tmp->data != pivot)
    {
        tmp = tmp->next;
    }
    
    if(tmp->next->next == NULL)
    {
        delete_tail(head);
        return;
    }
    node* to_delete = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete to_delete;
}

void delete_before(node* &head, int pivot)
{
    node* tmp = head;
    
    while(tmp->data != pivot)
    {
        tmp = tmp->next;
    }
    
    if(tmp->prev->prev == NULL)
    {
        delete_head(head);
        return;
    }
    tmp = tmp->prev->prev;
    node* to_delete = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete to_delete;
}

void display(node* head)
{
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " <-> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    insert_head(head, 1);
    insert_head(head, 2);
    insert_head(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    insert_tail(head, 6);
    insert_before(head, 4, 7);
    insert_after(head, 5, 8);

    display(head);

    delete_head(head);
    delete_tail(head);
    delete_after(head, 7);
    delete_before(head, 8);
    display(head);

    return 0;
}