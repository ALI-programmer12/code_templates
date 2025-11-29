#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

// Create bad character table
void badCharHeuristic(const string &pattern, vector<int> &badChar) {
    int m = pattern.length();
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1; 
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i; // last occurrence
}


void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(NO_OF_CHARS);
    badCharHeuristic(pattern, badChar);

    int s = 0; // shift of text's pattern
    while (s <= n - m) {
        int j = m - 1;

       
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;

            
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            // Shift pattern according to bad character formula
            int shift = max(1, j - badChar[text[s + j]]);
            s += shift;
        }
    }
}

int main() {
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    return 0;
}