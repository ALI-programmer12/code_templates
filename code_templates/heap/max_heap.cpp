    #include <iostream>
    using namespace std;

    class MaxHeap
    {
        int heap[10];
        int currentSize;

        int get_parent(int index)
        {
            return (index - 1) / 2;
        }
        int get_left(int index)
        {
            return 2 * index + 1;
        }
        int get_right(int index)
        {
            return 2 * index + 2;
        }

    public:
        MaxHeap()
        {
            currentSize = 0;
        }

        void heapify_up(int index)
        {
            while (index != 0 && heap[index] > heap[get_parent(index)])
            {
                int temp = heap[index];
                heap[index] = heap[get_parent(index)];
                heap[get_parent(index)] = temp;

                index = get_parent(index);
            }
        }

        void heapify_down(int index)
        {

            int largest = index;
            int left = get_left(index);
            int right = get_right(index);

            if (left < currentSize && heap[left] > heap[largest])
            {
                largest = left;
            }

            if (right < currentSize && heap[right] > heap[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;

                heapify_down(largest);
            }
        }

        

        void insert(int val)
        {
            if (currentSize >= 10)
            {
                cout << "Heap is full" << endl;
            }

            heap[currentSize] = val;
            heapify_up(currentSize);
            currentSize++;
        }

    void heapSort()
    {
    if (currentSize == 0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    // Temporary copy (so original heap stays unchanged)
    int tempHeap[10];
    for (int i = 0; i < currentSize; i++)
        tempHeap[i] = heap[i];

    int tempSize = currentSize;

    cout << "Heapsort result: ";

    // Perform heap sort
    while (tempSize > 0)
    {
        // Maximum element at root
        cout << tempHeap[0] << " ";

        // Move last element to root
        tempHeap[0] = tempHeap[tempSize - 1];
        tempSize--;

        // Call heapify_down on temp array
        heapify_down_temp(tempHeap, tempSize, 0);
    }

    cout << endl;
}


        

        void deleteFromMaxHeap()
        {

            if (currentSize <= 0)
            {
                cout << "Nothing to delete!! Heap is empty" << endl;
            }

            heap[0] = heap[currentSize - 1];
            currentSize--;
            heapify_down(0);
        }
        
        // void update_key(int i, int new_val)
        // {

        //     if (i < 0 || i >= currentSize)
        //     {
        //         cout << "Please Enter the index between from 0 to " << currentSize << endl;
        //         return;
        //     }

        //     heap[i] = new_val;

        //     if (i>0 && heap[i] > heap[get_parent(i)])
        //     {
        //        heapify_up(i);
        //     }
        //     else
        //     {
        //         heapify_down(i);
        //     }
            
        // }

        

        void display() {
            cout << "Heap: ";
            for (int i = 0; i < currentSize; i++)
                cout << heap[i] << " ";
            cout << endl;
        }
    };

    int main() {
        MaxHeap h;
        h.insert(8);
        h.insert(7);
        h.insert(6);
        h.insert(5);
        h.insert(4);

        h.display();
        cout<<"\n~~After updation~~\n";
        // h.update_key(2, 3); // Update index 2 → 3
        h.display();

          cout<<"\n~~After deletion~~\n";
        h.deleteFromMaxHeap(); 
        h.display();

        return 0;
    }

