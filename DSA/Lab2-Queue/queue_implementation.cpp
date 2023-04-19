#include <iostream>
#define SIZE 5
using namespace std;

template <typename T>
class Queue
{

    private:
        T queue[SIZE];
        int front;
        int rear;
    
    public:
        Queue()
        {
            front = -1;
            rear = -1;
        }

        void enequeue(T x)
        {
            if(rear == SIZE - 1){
                throw("\nQueue Full\n");
            }

            else if(front == -1 && rear == -1){
                front = rear = 0;
                queue[rear] = x;
            }

            else{
                queue[++rear] = x;
            }
        }    

        void dequeue()
        {
            if(front == -1 && rear == -1){
                throw("\nQueue Empty\n");
            }

            else if(front == rear){
                front = rear = -1;
            }

            else{
                front++;
            }
        }   

        void display()
        {
            if(front == -1 && rear == -1){
                cout << "Queue is empty";
            }

            else{
                cout << "Elements in queue are: " << endl;
                for(int i = front; i <= rear; ++i){
                    cout << queue[i] << " ";
                }

                cout << endl;
            }
        }

        void peek()
        {
            if(front == -1 && rear == -1){
                cout << "Queue is empty";
            }

            else{
                cout << queue[front];
            }
        }
};

int main()
{
    Queue<int> q;

    try
    {
        q.enequeue(2);
        q.enequeue(5);
        q.enequeue(-1);
        q.enequeue(0);
        q.enequeue(7);

        q.display();

        q.dequeue();
        q.dequeue();
        q.dequeue();

        q.enequeue(7);

        q.display();
    }
    
    catch (const char* err){
        cout << err;
    }
    return 0;
}