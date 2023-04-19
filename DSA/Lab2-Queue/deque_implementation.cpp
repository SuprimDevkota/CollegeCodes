#include <iostream>
#define SIZE 5
using namespace std;


template <typename T>
class Deque
{
    private:
        T deque[SIZE];
        int front;
        int rear;

    public:
        Deque()
        {
            front = rear = -1;
        }

        void InsertFront(T x)
        {
            if((rear + 1) % SIZE == front){
                throw("\nDeque Full\n");
            }

            else if(front == -1 && rear == -1){
                front = rear = 0;
                deque[front] = x;
            }
            
            else
            {
                front = (front - 1) % SIZE;
                deque[front] = x;
            }
        }

        void InsertRear(T x)
        {
            if((rear + 1) % SIZE == front){
                throw("\nDeque Full\n");
            }

            else if(front == -1 && rear == -1){
                front = rear = 0;
            }

            else
            {
                rear = (rear + 1) % SIZE;
                deque[rear] = x;
            }
        }

        void DeleteFront()
        {
            if(front == -1 && rear == -1){
                throw("\nDeque empty\n");
            }

            else if(front == rear){
                front = rear = -1;
            }

            else{
                front = (front + 1) % SIZE;
            }
        }

        void DeleteRear()
        {
            if(front == -1 && rear == -1){
                throw("\nDeque empty\n");
            }

            else if(front == rear){
                front = rear = -1;
            }

            else{
                rear = (rear - 1) % SIZE; 
            }
        }

        void Display()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Deque is empty" << endl;
            }
            cout << "Elements in queue: " << endl;
            int i = front;
            while(i != rear){
                cout << deque[i] << " ";
                i = (i + 1) % SIZE;
            }

            cout << deque[rear] << endl;
        }
};


int main()
{
    Deque<int> q;

    try
    {
        q.InsertFront(1);
        q.InsertRear(2);
        q.InsertFront(3);
        q.InsertRear(4);

        q.Display();

        q.DeleteFront();
        q.DeleteRear();

        q.Display();
    }

    catch(const char* err)
    {
        cout << err << endl;
    }

    return 0;
}