#include <iostream>
using namespace std;
int stack[100], n = 100, top = -1;
int queue[100], N = 100, front = -1, rear = -1;

// Queue class with queue functions
class Queue
{
public:
    void enqueue(int val)
    {

        if (rear == N - 1)
            cout << "Queue Overflow" << endl;
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = val;
        }
    }
    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow ";
        }
        else
        {
            int x = queue[front];
            front++;
            return x;
        }
    }
    void Display()
    {
        if (front == -1)
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    }
};

// Stack class with stack functions
class Stack
{
public:
    void push(int val)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
        }
    }
    int pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            int x = stack[top];
            top--;
            return x;
        }
    }
    void display()
    {
        if (top >= 0)
        {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
            cout << "Stack is empty";
    }
};
int main()
{
    int n;
    cout << "Array size: ";
    cin >> n;
    int a[n];
    cout<<"Insert Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // push array elements to stack st
    Stack st;
    for (int i = 0; i < n; i++)
    {
        st.push(a[i]);
    }
    st.display();

    // enqueue stack elements
    Queue q;
    while (top > -1)
    {
        int x = st.pop();
        q.enqueue(x);
    }
    q.Display();
    // Dequeue queue elements and print them
    cout << "Dequeued Elements from the queue: ";
    while (front <= rear)
    {
        cout << q.dequeue() << " ";
    }
    return 0;
}
