#include <iostream>
using namespace std;
#define n 4

bool checkRow(char arr[n][n], int i, int j)
{

    if (j < 0)
        return true;

    if (arr[i][j] == 'Q')
    {
        return false;
    }

    return checkRow(arr, i, j - 1);
}

bool checkColumn(char arr[n][n], int i, int j)
{
    if (i <0)
        return true;

    if (arr[i][j] == 'Q')
    {
        return false;
    }

    return checkColumn(arr, i - 1, j);
}

bool checkRightDiagonal(char arr[n][n], int i, int j)
{
    if (i < 0 || j >= n)
        return true;

    if (arr[i][j] == 'Q')
    {
        return false;
    }

    return checkRightDiagonal(arr, i - 1, j + 1);
}

bool checkLeftDiagonal(char arr[n][n], int i, int j)
{
    if (i < 0 || j < 0)
        return true;

    if (arr[i][j] == 'Q')
    {
        return false;
    }

    return checkLeftDiagonal(arr, i - 1, j - 1);
}

bool canPlace(char arr[n][n], int i, int j)
{

    return checkColumn(arr, i , j) &&
           checkLeftDiagonal(arr, i, j) &&
           checkRightDiagonal(arr, i, j);
}

bool placeQueens(char arr[n][n], int i, int j)
{
    if (i == n)
    {
        return true;
    }

    if (j == n)
    {
        return false;
    }

   
    if (canPlace(arr, i, j)) //if we placed the queen then check another row 
    {
        cout<<"p";
        arr[i][j] = 'Q';

        if (placeQueens(arr, i + 1, 0))
            return true; // mistake -> i'm directly returning the function not its value which causes problem in backtracking
        
        arr[i][j] = '-';
    }
    // otherwise check next columns
   
    return placeQueens(arr, i, j+1);
    
}

int main()
{
    char arr[n][n] = {
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'}};

    if (placeQueens(arr, 0, 0))
    {
        cout<<"Queens placed successfully"<<endl;
  
    }
    else
    {
        cout<<"Queens not placed!!"<<endl;
    }

    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    
    
    return 0;
}