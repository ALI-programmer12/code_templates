#include <iostream>
using namespace std;

void bruteForceSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        // Check characters one by one
        while (j < m && text[i + j] == pattern[j])
            j++;

        // If full pattern matched
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            count++;
        }
    }

    if (count == 0)
        cout << "Pattern not found!" << endl;
}

int main()
{
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    cout << endl;
    bruteForceSearch(text, pattern);
    cout << endl;

    return 0;
}
