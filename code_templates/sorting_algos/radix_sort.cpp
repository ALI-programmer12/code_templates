#include <iostream>
using namespace std;

int findMax(int arr[], int len)
{
    int largest = arr[0];
    for (int i = 1; i < len; i++)
        if (arr[i] > largest)
            largest = arr[i];
    return largest;
}

void countSort(int arr[], int len, int digitPos)
{
    int *result = new int[len];
    int freq[10] = {0};

    // Count frequency of digits
    for (int i = 0; i < len; i++)
        freq[(arr[i] / digitPos) % 10]++;

    // Convert to cumulative frequency
    for (int i = 1; i < 10; i++)
        freq[i] += freq[i - 1];

    // Build the output array
    for (int i = len - 1; i >= 0; i--)
    {
        int digit = (arr[i] / digitPos) % 10;
        result[freq[digit] - 1] = arr[i];
        freq[digit]--;
    }

    // Copy result back to original array
    for (int i = 0; i < len; i++)
        arr[i] = result[i];

    delete[] result;
}

void radixSort(int arr[], int len)
{
    int largest = findMax(arr, len);

    // Apply counting sort for every digit
    for (int exp = 1; largest / exp > 0; exp *= 10)
        countSort(arr, len, exp);
}

void showArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int data[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array:\n";
    showArray(data, size);

    radixSort(data, size);

    cout << "\nSorted array:\n";
    showArray(data, size);

    return 0;
}
