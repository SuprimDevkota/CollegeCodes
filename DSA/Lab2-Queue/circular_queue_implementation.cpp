#include <iostream>
#define SIZE 5
using namespace std;

template <typename T>
class CQueue
{

    private:
        T queue[SIZE];
        int front;
        int rear;
    
    public:
        CQueue()
        {
            front = -1;
            rear = -1;
        }

        void enequeue(T x)
        {
            if((rear + 1) % SIZE == front){
                throw("\nQueue Full\n");
            }

            else if(front == -1 && rear == -1){
                front = rear = 0;
                queue[rear] = x;
            }

            else{
                rear = (rear + 1) % SIZE;
                queue[rear] = x;
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
                front = (front + 1) % SIZE;
            }
        }   

        void display()
        {
            int i = front;
            if(front == -1 && rear == -1){
                cout << "Queue is empty";
            }

            else{
                cout << "Elements in queue are: " << endl;
                while(i != rear){
                    cout << queue[i] << " ";
                    i = (i + 1) % SIZE; 
                }

                cout << queue[rear] << endl;
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
    CQueue<int> q;

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

        q.enequeue(8);

        q.display();
    }
    
    catch (const char* err){
        cout << err;
    }
    return 0;
}