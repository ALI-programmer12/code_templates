#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {

        data = 0;
        next = nullptr;
    }
    Node(int val)
    {

        data = val;
        next = nullptr;
    }
};

class LinkedList
{

    Node *head;
    Node *tail;

public:
    LinkedList()
    {

        head = tail = nullptr;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void moveElementsToEnd(int positions)
    {
        Node *temp;
        for (int i = 0; i < positions; i++)
        {
            temp = head;
            head = head->next;
            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }
        cout << endl;
    }

    void bubbleSort()
    {
        Node *temp = head;
        int len = 0;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        bool swapped = false;
        for (int i = 0; i < len; i++)
        {
            temp = head;
            for (int j = 0; j < len - i - 1; j++)
            {
                if (temp->data > temp->next->data)
                {
                    int temp2 = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = temp2;
                    swapped = true;
                }
                temp = temp->next;
            }
            if (swapped == false)
            {
                cout<<"already sorted"<<endl;
                return;
            }
            
        }
    }

    void printLinkedList()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        };
        cout << endl;
    }
};

int main()
{
    LinkedList ll;

    ll.push_back(5);
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(8);
    ll.push_back(6);
    ll.push_back(4);
    ll.push_back(2);

    cout << "Original list: " << endl;
    ll.printLinkedList();


    ll.printLinkedList();
}   