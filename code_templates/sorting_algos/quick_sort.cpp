#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    string itemName;
    float itemCost;
    string itemDetails;
    bool inStock;
};

int divide(Item data[], int low, int high)
{
    float pivotValue = data[high].itemCost;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (data[j].itemCost <= pivotValue)
        {
            i++;
            Item temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    Item temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;

    return i + 1;
}

void quickSort(Item data[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = divide(data, low, high);
        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}