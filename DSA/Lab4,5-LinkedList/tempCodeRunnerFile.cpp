#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        int exp;
        node* next;

        node(int data, int exp)
        {
            this->data = data;
            this->exp = exp;
            next = NULL;
        }
};

void insert_tail(node* &head, int data, int exp)
{
    node* tail = new node(data, exp);
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

void display(node* head)
{
    node* tmp = head;
    
    while(tmp != NULL)
    {
        cout << tmp->data << "x^" << tmp->exp;
        if(tmp->next != NULL) cout <<  " + ";
        tmp = tmp->next;
    } 
    cout << endl;
}

node* add(node* head1, node* head2)
{
    node* tmp1 = head1;
    node* tmp2 = head2;
    node* dummy_node = new node(-1, -1);
    node* tmp = dummy_node;

    while(tmp1 != NULL && tmp2 != NULL)
    {
        if(tmp1->exp > tmp2->exp)
        {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        }

        else if(tmp1->exp < tmp2->exp)
        {
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }

        else
        {
            node* new_node = new node(tmp1->data + tmp2->data, tmp1->exp);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            tmp->next = new_node;
        }

        tmp = tmp->next;
    }

    while(tmp1 != NULL)
    {
        tmp->next = tmp1;
        tmp1 = tmp1->next; 
    }

    while(tmp2 != NULL)
    {
        tmp->next = tmp2;
        tmp2 = tmp2->next;
    }

    return dummy_node->next;
}

int main()
{
    int data1[3] = {2 ,4, 1};
    int data2[4] = {7, 2, 6 , 4};

    int exp1[3] = {2, 3, 5};
    int exp2[4] = {2, 3, 5, 9};

    node* head = NULL;
    node* head1 = NULL;
    node* head2 = NULL;

    for(int i = 0; i < 3; ++i)
    {
        insert_tail(head1, data1[i], exp1[i]);
    }


    for(int i = 0; i < 4; ++i)
    {
        insert_tail(head2, data2[i], exp2[i]);
        
    }

    display(head1);
    display(head2);

    head = add(head1, head2);

    display(head);
    return 0;
}