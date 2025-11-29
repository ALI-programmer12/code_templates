#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        top = -1;
        arr = new int[size];
        this->size = size;
    }

    void push(int val)
    {

        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop()
    {

        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int peek()
    {

        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {

        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSizeOfFilledStack() {
        return top;
    }

    void print()
    {
        if (top >= 0 && top < size)
        {
            for (int i = top ; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            return;
        }
        else
        {
            cout << "Stack is empty!!" << endl;
            return;
        }
        
       
    }
};

int main()
{

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.pop();

    cout << "Top of stack: " << st.peek() << endl;

    st.print();
    cout << endl;
    cout << "Size of stack: " << st.getSizeOfFilledStack() << endl;
    cout << ((st.isEmpty()) ? "Stack is Empty" : "Stack is Not Empty");
    return 0;
}