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

void swapItems(Item &a, Item &b)
{
    Item temp = a;
    a = b;
    b = temp;
}

int divide(Item data[], int low, int high)
{
    float pivot = data[high].itemCost;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (data[j].itemCost <= pivot)
        {
            i++;
            swapItems(data[i], data[j]);
        }
    }

    swapItems(data[i + 1], data[high]);
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

int main()
{
    Item data[5] = {
        {"Laptop", 85000, "Gaming laptop", true},
        {"Mouse", 1200, "Wireless mouse", true},
        {"Keyboard", 3500, "Mechanical keyboard", false},
        {"Monitor", 25000, "24 inch LED", true},
        {"USB", 800, "32GB USB drive", true}
    };

    int n = 5;

    cout << "\n--- Before Sorting ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << data[i].itemName << " - " << data[i].itemCost << endl;
    }

    quickSort(data, 0, n - 1);

    cout << "\n--- After Sorting (Ascending by Cost) ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << data[i].itemName << " - " << data[i].itemCost << endl;
    }

    return 0;
}

