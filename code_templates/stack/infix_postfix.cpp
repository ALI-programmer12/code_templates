#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Stack
{
    char *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        top = -1;
        arr = new char[size];
        this->size = size;
    }

    void push(char val)
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

    int getSizeOfFilledStack()
    {
        return top;
    }

    void print()
    {
        if (top >= 0 && top < size)
        {
            for (int i = top; i >= 0; i--)
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

int precedence(char c)
{

    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isRightAssociative(char c)
{
    if (c == '^')
    {
        return true;
    }
    return false;
}

string infixToPostFix(string infix)
{
    string postfix = "";
    Stack st(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                postfix += st.peek();
                st.pop();
            }
            if (st.peek() == '(')
            {
                st.pop();
            }
        }
        else
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                char top = st.peek();
                if ((isRightAssociative(c) && precedence(c) < precedence(top)) || !isRightAssociative(c) && precedence(c) <= precedence(top))
                {
                    postfix += st.peek();
                    st.pop();
                }
                else
                {
                    break;
                }
                
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        char top = st.peek();
        postfix += top;
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix = "A+B*C-D/E";
    string postfix = infixToPostFix(infix);

    cout<<postfix<<endl;
    return 0;
}