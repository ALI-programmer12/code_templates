#include <iostream>
using namespace std;

class Queue {

    int *arr;
    int qSize;
    int qFront;
    int rear;

    public:
    Queue(){}
    Queue(int size){

        arr = new int[size];
        qFront = 0;
        rear = 0;
        qSize = size;
    }
    void enqueue(int val){

        if (rear == qSize)
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        
        arr[rear] = val;
        rear++; 
    }

    void dequeue(){
        if (qFront == rear)
        {
            cout<<"Stack is empty!"<<endl;
            return;
        }
        arr[qFront] = -1;
        qFront++;
        if (qFront == rear)
        {
            qFront = 0;
            rear = 0;
        }  
    }

    int front(){

        if (qFront == rear)
        {
            cout<<"Stack is empty!"<<endl;
            return -1;
            
        }
        
        return arr[qFront];
    }

    int back(){
        if (qFront == rear)
        {
            cout<<"Stack is empty!"<<endl;
            return -1;
            
        }
        
        return arr[rear-1];
    }

    int size(){
        return qSize;
    }

    bool isEmpty(){

        if (qFront == rear)
        {
            return false;
        }
        return true;   
    }

};
 
int main() {
    
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);


    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    q.dequeue();
    cout<<"Is Empty: "<<q.isEmpty()<<endl;
    q.dequeue();
    cout<<"Is Empty: "<<q.isEmpty()<<endl;
    q.dequeue();
    cout<<"Is Empty: "<<q.isEmpty()<<endl;
    cout<<q.front();
    return 0;
}