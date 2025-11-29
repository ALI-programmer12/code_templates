#include <iostream>
#include <vector>
using namespace std;
#define n 5

bool checkRow(int i, int s, int e, char matrix[n][n], vector<string> &ans)
{
    if (s > e)
    {
        string word = "";
        for (int k = 0; k < n; k++)
        {
            word += matrix[i][k];
        }

        ans.push_back(word);
        return true;
    }

    if (matrix[i][s] == matrix[i][e])
    {
        return checkRow(i, s + 1, e - 1, matrix, ans);
    }

    return false;
}
bool checkColumn(int j, int s, int e, char matrix[n][n], vector<string> &ans)
{

    if (s > e)
    {
        string word = "";
        for (int k = 0; k < n; k++)
        {
            word += matrix[k][j];
        }
        ans.push_back(word);
        return true;
    }

    if (matrix[s][j] == matrix[e][j])
    {
        return checkColumn(j, s + 1, e - 1, matrix, ans);
    }

    return false;
}

bool isPalindrome(int i, int j, char matrix[n][n], vector<string> &ans)
{
    if (checkRow(i, j, n - 1, matrix, ans))
    {
        return true;
    }
    if (checkColumn(j, i, n - 1, matrix, ans))
    {
        return true;
    }

    return false;
}

void findPalindromeInRow(char matrix[n][n], int i, int j, vector<string> &ans)
{
    if (i == n - 1)
    {
        return;
    }

    isPalindrome(i, j, matrix, ans);
    findPalindromeInRow(matrix, i + 1, j, ans);
}
void findPalindromeInCol(char matrix[n][n], int i, int j, vector<string> &ans)
{
    if (j == n - 1)
    {
        return;
    }

    isPalindrome(i, j, matrix, ans);
    findPalindromeInCol(matrix, i, j+1, ans);
}



int main()
{

    char matrix[n][n] = {
        {'l', 'e', 'c', 'e', 'l'}, // "level" -> palindrome
        {'q', 'w', 'c', 'r', 't'},
        {'r', 'a', 'd', 'a', 'r'}, // "radar" -> palindrome
        {'a', 'b', 'c', 'd', 'e'},
        {'z', 'x', 'c', 'v', 'b'}};

    vector<string> ans;

    findPalindromeInRow(matrix, 0, 0, ans);
    findPalindromeInCol(matrix, 0, 1, ans);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;
// #define n 5

// // Utility function to check palindrome
// bool isPalindrome(string s) {
//     int l = 0, r = s.size() - 1;
//     while (l < r) {
//         if (s[l] != s[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }

// // Backtracking in a row
// void backtrackRow(int row, int start, string current, char matrix[n][n], vector<string> &ans) {
//     if (start == n) {
//         return; // reached end of row
//     }

//     // choice: include matrix[row][start]
//     current.push_back(matrix[row][start]);

//     // check palindrome
//     if (isPalindrome(current) && current.size() > 1) {
//         ans.push_back(current);
//     }

//     // explore further
//     backtrackRow(row, start + 1, current, matrix, ans);

//     // backtrack (remove last char)
//     current.pop_back();
// }

// // Backtracking in a column
// void backtrackCol(int col, int start, string current, char matrix[n][n], vector<string> &ans) {
//     if (start == n) {
//         return; // reached end of column
//     }

//     // choice: include matrix[start][col]
//     current.push_back(matrix[start][col]);

//     // check palindrome
//     if (isPalindrome(current) && current.size() > 1) {
//         ans.push_back(current);
//     }

//     // explore further
//     backtrackCol(col, start + 1, current, matrix, ans);

//     // backtrack (remove last char)
//     current.pop_back();
// }


// int main() {
//     char matrix[n][n] = {
//         {'l', 'e', 'c', 'e', 'l'}, // "level"
//         {'q', 'w', 'c', 'r', 't'},
//         {'r', 'a', 'd', 'a', 'r'}, // "radar"
//         {'a', 'b', 'c', 'd', 'e'},
//         {'z', 'x', 'c', 'v', 'b'}
//     };

//     vector<string> ans;

//     // Check palindromes in all rows
//     for (int i = 0; i < n; i++) {
//         backtrackRow(i, 0, "", matrix, ans);
//     }

//     // Check palindromes in all columns
//     for (int j = 0; j < n; j++) {
//         backtrackCol(j, 0, "", matrix, ans);
//     }

//     // Print all palindromes
//     for (auto &s : ans) {
//         cout << s << " ";
//     }
//     cout << endl;
//     return 0;
// }
